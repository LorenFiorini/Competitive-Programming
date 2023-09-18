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
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
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

int ans = 1e9;
int h, w;
int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, -1, 1};
vpii posible;

bool check(int r, int c, vvi &vis) {
	if (r < 0|| r >= h || c < 0|| c >= w) return false;
	if (vis[r][c]) return false;
	return 1;
}

void dfs2(vvi &v, int r, int c, int br) {
	if (r+1 == h && c+1 == w) {
		ans = min(ans, br);
		return;
	}
	
	// RIGHT
	if (c+1 < w) {
		if (v[r][c+1] == 0) {
			v[r][c+1] = 1;
			if (r+1<h){
				v[r+1][c+1] = 1;
				if (c+2 < w) v[r+1][c+2] = 1;
			}
			dfs2(v, r, c+1, br+1);
			v[r][c+1] = 0;
			if (r+1<h){
				v[r+1][c+1] = 0;
				if (c+2 < w) v[r+1][c+2] = 0;
			}
		} else {
			dfs2(v, r, c+1, br);
		}
	}
	
	// DOWN
	if (r+1 < h) {
		if (!v[r+1][c]) {
			del(v, r+1, c);
			dfs2(v, r+1, c, br+1);
		} else {
			dfs2(v, r+1, c, br);
		}
	}
	
	show(ans);
}

void dfs(vvi &v, vvi &vis, int r, int c) {
	vis[r][c] = true;
	
	if (r+1 == h && c+1 == w) {
		ans = 0;
		return;
	}
	
	rep (i, 0, 4) 
	{
		int ro = r + a[i];
		int co = c + b[i];
		if (!check(ro, co, vis)) continue;
		if (v[ro][co])dfs(v, vis, ro, co);
	}
	posible.pb({r, c});
}

void solve () {
	cin >> h >> w;
	vvi v(h, vint(w,0));
	rep (i, 0, h) rep(j,0,w) {
		char c;
		cin >> c;
		v[i][j] = (c == '.');
	}
	// 1 == true == empty == ONE
	
	vvi vis(h, vint(w, 0));
	dfs(v, vis, 0, 0);
	
	rep (i, 0, len(posible)) {
		int tmp = ans;
		dfs2(v, posible[i].ff, posible[i].ss, 0);
		if (ans == tmp) break;
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
