#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll, ll> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

vll pr;
void primes() {
	ll N = 500;
	vll vec(N, 1);
	rep (i, 2, N) {
		if (vec[i]) {
			pr.pb(i);
			por (j, i+i, N, i) {
				vec[j] = 0;
			}
		}
	}
}

ll LCM(ll a, ll b) {
	ll n = len(pr);
	a = abs(a);
	b = abs(b);
	// factors
	mpii fa;
	rep (i, 0, n) {
		while (a % pr[i] == 0 && a != 0) {
			fa[pr[i]]++;
			a /= pr[i];
		}
	}
	mpii fb;
	rep (i, 0, n) {
		while (b % pr[i] == 0 && b != 0) {
			fb[pr[i]]++;
			b /= pr[i];
		}
	}
	// Common
	each(it, fb) {
		if (fa.find(it->ff) == fa.end()) {
			fa[it->ff] = it->ss;
		} else {
			fa[it->ff] = max(fa[it->ff], it->ss);
		}
	}
	ll ans = 1;
	each(it, fa) {
		ans *= pow(it->ff, it->ss);
	}
	return ans;
}

void solve () {
	ll n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];
	
	ll start = 0;
	if (n % 2) {
		// lcm of 3 numbers 
		ll tmp = LCM(v[0], v[1]);
		ll lcm = LCM(tmp, v[2]);
	
		rep(i,0,3) {
			tmp = lcm / v[i];
			if(!i) tmp *= -2;
			cout << tmp << " ";
		}
		start = 3;
	}
	
	por (i, start, n, 2) {
		ll lcm = LCM(v[i], v[i+1]);
		ll A = lcm / v[i];
		ll B = -(lcm / v[i+1]);
		cout << A << " " << B << " ";
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	primes();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
