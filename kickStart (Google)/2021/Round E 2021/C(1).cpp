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

int n, m;

bool valid(vstr &v, int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= m) return false;
	return (v[r][c] != '#');
}

void corners(vstr &v, vvi &vis, int r, int c) {
	if (vis[r][c]) return;
	vis[r][c] = 1;
	
	char ch = v[r][c];	
	//to up and down
	int u = r, d = r;
	do {	u--;	} while (valid(v, u, c));	u++;
	do {	d++;	} while (valid(v, d, c));	d--;
	
	int pos = d - (r - u);
	if (pos != r && v[r][c] != v[pos][c]) {
		v[pos][c] = ch;
		corners(v, vis, pos, c);
	}
	
	
	//to left and right
	int le = c, ri = c;
	do {	le--;	} while (valid(v, r, le));	le++;
	do {	ri++;	} while (valid(v, r, ri));	ri--;
	
	pos = ri - (c-le);
	if (pos != c && v[r][c] != v[r][pos]) {
		v[r][pos] = ch;
		corners(v, vis, r, pos);
	}
	
	return;
}

void solve () {
	cin >> n >> m;
	vstr v(n);
	rep (i, 0, n) cin >> v[i];
	vstr cpy(all(v));
	
	vvi vis(n, vint(m, false));
	rep (i, 0, n) {
		rep (j,0,m) {
			if (v[i][j] >= 'A' && v[i][j] <= 'Z' && vis[i][j] == false) {
				corners(v, vis, i, j);
			}
		}
 	}

	// count
	int ans = 0;
	rep (i, 0, n) {
		rep (j, 0, m) {
			ans += (v[i][j] != cpy[i][j]);
		}
 	}
	
	show(ans);
	rep (i, 0, n) show(v[i]);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
