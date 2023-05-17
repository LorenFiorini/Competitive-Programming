#include "bits/stdc++.h"
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
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
#define x first
#define y second
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

ll distance(pll a, pll b) {
	ll dx = abs(a.x - b.x);
	ll dy = abs(a.y - b.y);

	return dx*dx + dy*dy;
}

void solve (void) {
	// input coordinates
	ll n, m;
	cin >> n >> m;
	vector<pll> co(m);
	rep (i, 0, m) {
		cin >> co[i].x >> co[i].y;
	}

	// getting distance ^ 2
	vector<vll> dis;
	rep (i, 0, m) {
		rep (j, i + 1, m) {
			dis.push_back({distance(co[i], co[j]), (ll) i, (ll) j});
		}
	}
	sort(all(dis));
	//showmat(dis);
	vint vis(m, 0);
	int color = 1;
	int con = m - n;
	double ans;

	rep (id, 0, con) {
		int i = (int) dis[id][1];
		int j = (int) dis[id][2];

		if (vis[i] == 0 && vis[j] == 0) {
			vis[i] = vis[j] = color;
			color++;
		} else if (vis[i] == 0 || vis[j] == 0) {
			vis[i] = vis[j] = max(vis[i], vis[j]);
		} else if (vis[i] != vis[j]) {
			int mn = min(vis[i], vis[j]);
			int mx = max(vis[i], vis[j]);
			rep (idx, 0, m) {
				if (vis[idx] == mx) 
					vis[idx] = mn;
			}
		} else {
			con++;
		}

		ans = sqrt((double) dis[id][0]);
		//show(ans);
	}

	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << setprecision(2) << fixed;

	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
