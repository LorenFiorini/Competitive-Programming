#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
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

int mod = 998244353;
int ans, n;
int N = 3010;

void nxt(vvi &v, int r, int c) {
	//int j = c+1;
	int i = r+1;
	
	rep (j, c, N) {
		if (v[i][j] != 0) {
			if (v[i][j] == -1) v[i][j] = v[r][c];
			else v[i][j] += v[r][c];
			v[i][j] %= mod;
		}	
	}
}

void solve () {
	ans = 0;
	
	// input
	cin >> n;
	vint a(n);
	rep (i, 0, n) cin >> a[i];
	vint b(n);
	rep (i, 0, n) cin >> b[i];
	
	// load to matrix
	vvi v(N, vint(N, 0));
	rep (i, 0, n) {
		if (a[i] > b[i]) swap(a[i], b[i]);
		rep (j, a[i], b[i] + 1) {
			if (!i) {
				v[i][j] = 1;
			} else {
				v[i][j] = -1;
			}
		}
	}
	
	// compute
	rep (i, 0, N) {
		rep (j, 0, N) {
			if (v[i][j]) {
				nxt(v, i, j);
			}
		}
	}
	
	// accu,mulate
	rep (j, 0, N) {
		ans += v[n-1][j];
		ans %= mod;
	}

	
	showvv(v, 100, 100);
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
