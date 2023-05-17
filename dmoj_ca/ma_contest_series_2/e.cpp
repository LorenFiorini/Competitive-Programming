#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
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
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
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
	ll ans = 0;
	ll n;
	cin >> n;
	
	ll mx = 500;
	vvi mat(mx, vll(mx, 0));
	map<ll, vpii> mp;
	rep (i, 0, n) {
		vll line(4);
		rep(j, 0, 4) cin >> line[j];
		rep(j, 0, 4) line[j] += 101;

		if (line[0] == line[2]) {
			ll x = line[0];
			ll y0 = min(line[1], line[3]);
			ll y1 = max(line[1], line[3]);

			while (y0 <= y1) {
				mat[x][y0]++;
				y0++;
			}
		} else {
			ll y = line[1];
			ll x0 = min(line[0], line[2]);
			ll x1 = max(line[0], line[2]);
			mp[y].push_back(make_pair(x0, x1));
		}
	}
	
	for (auto &yy: mp) {
		ll y = yy.first;
		ll cnt = 0;

		for (auto p: yy.second) {
			ll x0 = p.first;
			ll x1 = p.second;

			while (x0 <= x1) {
				cnt += mat[x0][y];
				x0++;
			}
		}
		
		ans += cnt;
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
