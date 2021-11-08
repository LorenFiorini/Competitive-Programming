#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
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
mpii factor(ll a) {
	ll n = len(pr);
	mpii f;
	rep (i, 0, n) {
		while (a % pr[i] == 0 && a > 0) {
			f[pr[i]]++;
			a /= pr[i];
		}
	}
	return f;
}

ll LCM(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	// factors
	mpii fa = factor(a);
	mpii fb = factor(b);
	// Common
	each(it, fb) {
		if (fa.find(it->ff) == fa.end()) fa[it->ff] = it->ss;
		else fa[it->ff] = max(fa[it->ff], it->ss);
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
	vll ans(n);
	vpii v(n);
	rep (i, 0, n) {
		cin >> v[i].ff;
		v[i].ss = i;
	}
	sort(all(v));
	
	bool odd = n % 2;
	if (odd == 1) {
		odd = 3;
		ll lcm = 1;
		rep (i, 0, odd) lcm = LCM(lcm, v[i].ff);
		rep (i, 0, odd) {
			ans[v[i].ss] = lcm / v[i].ff;
			if (!i) ans[v[i].ss] *= -2;
		}		
	}
	for (ll i = 0; i < n; i += 2){
		if (n%2) {i++;continue;}
		ll lcm = LCM(v[i].ff, v[i+1].ff);
		ans[v[i].ss] = lcm / v[i].ff;
		ans[v[i+1].ss] = -(lcm / v[i+1].ff);
	}
	
	showv(ans, n);
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
