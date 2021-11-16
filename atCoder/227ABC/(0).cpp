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
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
//
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (ll) v.size()
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
/*
vll pr;
void primes() {
	ll N = 5 * (1e2);
	ll lp[N+1];
	rep (i, 2, N+1) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.pb(i);
		}
		for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i*pr[i] <= N; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
	//showv(pr, len(pr));
}
*/

void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	
	rep (i, 1, n+1) {
		rep (j, i, n+1) {
			ll num = n / (i*j);
			num -= (i-1) + (j-i) ;//(j - i + 1);
			if (num > 0) {
				ans += num;
			} else {
				break;
			}
		}
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//primes();
	solve();
	
	return 0;
}

// Lorenzo Fiorini
