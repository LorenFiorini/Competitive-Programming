#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
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
#define ff first
#define ss second
#define por(i, a, b, in) for (ll i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";


void solve (void) {
	ll ans = 1, cnt = 1;
	ll n, D;
	cin >> n >> D;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	rep (d, 1, D+1) 
	{
		ll lim = v[0] + d;
		ll pre = v[0];
		cnt = 0;
		rep (i, 0, n) {
			if (v[i] < pre) {
				while (v[i] < pre) {
					i++;
				}
			} else if (v[i] >= lim) {
				while (v[i] >= lim) {
					pre += d;
					lim += d;
				}
				cnt = 0;
			}// else {
			//if (pre <= v[i] && v[i] < lim) {
				cnt++;
				pre += d;
				lim += d;
			//}

			ans = max(ans, cnt);
		}
		//showp(d, ans);
	}
	


	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
/*

	rep(x, 1, d+1) {
		ll c = 0;
		cnt = 0;
		rep (i, 0, n) {
			if (x + c*d <= v[i] && v[i] < x + (c+1)*d) {
				cnt++;
				//c++;
			} else if (v[i] >= x + (c+1)*d) {
				while (v[i] >= x + (c+1)*d) c++;
				cnt = 0;
				i--;
			}
			c++;
			//showp(cnt, ans);
			ans = max(ans, cnt);
		}
		//show("");
	}

*/

