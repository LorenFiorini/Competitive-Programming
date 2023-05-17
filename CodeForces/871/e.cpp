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
int d[4][4] = {
	{1, 0, 0, 0},
	{0, -1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, -1}
};

int dfs(vvi &v, int r0, int rn, int c0, int cm, int &ans) {
	if (r0 == rn && c0 == cm) return v[r0][c0];
	if (rn < r0 || cm < c0) return -1;

	int he = rn - r0 + 1;
	int wi = cm - c0 + 1;
	int de = 1001;
	rep (i, 0, 4) {
		int res = dfs(v, r0+d[i][0], rn+d[i][1],
			c0+d[i][2], cm+d[i][3], ans);

		if (res != -1) {
			de = min(de, res);
		}
	}
	ans = max(ans, he * de * wi);
	vint vec = {r0, rn, c0, cm};
	showv(vec);
	show(ans);
	return de;
}

void solve (void) {
	int ans = 0;
	cin >> n >> m;
	vvi v(n, vint(m));
	rep (i, 0, n) {
		rep (j, 0, m) {
			cin >> v[i][j];
			ans = max(ans, v[i][j]);
		}
	}

	int res = dfs(v, 0, n-1, 0, m-1, ans);
	ans = max(ans, res);
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

/*
3 3
1 2 0
3 4 0
0 0 5

return minimum element
int dfs(int r0, int rn, int c0, int cm) {
	if (r0 == rn && c0 == cm) return v[r0][c0];
	
	int he = rn - r0;
	int wi = cm - c0;
	int de = 1e9;
	dfs(r0+1, rn, c0, cm);
}


dfs(int lu, int ld, int ru, int rd) {
	max()
	dfs(lu+1, ld)
}

*/
