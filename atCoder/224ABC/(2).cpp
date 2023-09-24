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

int h, w, n;

void bfs(vvi &v, int r, int c, vvi &mx){
	mx[r][c] = max(mx[r][c], 0);
	
	// through column
	rep (i, 0, h) {
		if (i != r && v[i][c] < v[r][c]) {
			mx[i][c] = max(mx[i][c], mx[r][c] + 1);
		}
	}
	// through row
	rep (j, 0, w) {
		if (j != c && v[r][j] < v[r][c]) {
			mx[r][j] = max(mx[r][j], mx[r][c] + 1);
		}
	}
	
}

void solve () {	
	cin >> h >> w >> n;
	vvi v(h, vint (w, 0));
	vpii sta(n);
	multimap<int, pii> mp;
	rep (i, 0, n) {
		int r, c, a;
		cin >> r >> c >> a;
		r--; c--;
		v[r][c] = a;
		sta[i] = {r, c};
		mp.insert({a, {r, c}});
	}
	
	// max path
	vvi mx(h, vint(w, -1));
	for (auto it = mp.rbegin(); it != mp.rend(); it++) {
		bfs(v, it->ss.ff, it->ss.ss, mx);
	}
	
	// OUTPUT
	rep (i, 0, n) {
		show(max(mx[sta[i].ff][sta[i].ss], -1));
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
