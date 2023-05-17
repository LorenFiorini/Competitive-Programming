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

int n, m;
int d[4] = {1, -1, 0, 0};

int dfs(vvi &v, vvi &vis, int i, int j) {

	vis[i][j] = 1;
	int ans = v[i][j];
	rep (id, 0, 4) {
		int r = i + d[id];
		int c = j + d[3-id];
		if (min(r, c) < 0 || r == n || c == m) continue;
		if (!vis[r][c] && v[r][c] > 0) {
			ans += dfs(v, vis, r, c);
		}
	}
	return ans;
}

void solve (void) {
	int ans = 0;
	cin >> n >> m;
	vvi v(n, vint(m));
	vvi vis(n, vint(m, 0));
	rep (i, 0, n) {
		rep (j, 0, m) {
			cin >> v[i][j];
		}
	}

	rep (i, 0, n) {
		rep (j, 0, m) {
			if ((vis[i][j] == 0) && v[i][j] > 0) {
				ans = max(ans, dfs(v, vis, i, j));
			}
		}
	}

	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
