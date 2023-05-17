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

int dfs(vvi &ri, int col, int a, int b, int &ans) {
	if (a == b) {
		ans = max(ans, 2 * (ri[a][col] + 1));
		return ri[a][col];
	}

	int up = dfs(ri, col, a+1, b, ans);
	int da = dfs(ri, col, a, b-1, ans);
	int mn = min(up, da);
	int length = b - a + 1;
	int per = 2 * (length + mn);
	ans = max(ans, per);

	//cout << a << " " << b << " -> ";
	//showp(da, up);
	//showp(length, mn);
	//cout << endl;
	return mn;
}

void solve (void) {
	int ans = 0;
	cin >> n >> m;
	vstr v(n);
	rep(i, 0, n) cin >> v[i];

	// Right
	//show("Right");
	vvi ri(n, vint (m, 0));
	rep (i, 0, n) {
		rep (j, 0, m) {
			if (v[i][j] == '.') {
				ri[i][j] = 1;
				if (j) ri[i][j] += ri[i][j-1];
			}
		}
	}
	//showmat(ri); 
	
	for (int col = m-1; col >= 0; col--) {
		dfs(ri, col, 0, n-1, ans);
		break;
	}


	show(ans - 1);
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
// Left
show("Left");
vvi le(n, vint (m, 0));
rep (i, 0, n) {
	for (int j = m-1; j >= 0; j--) {
		if (v[i][j] == '.') {
			le[i][j] = 1;
			if (j+1 < m) le[i][j] += le[i][j+1];
		}
	}
}
showmat(le);


//// Down
//show("Down");
//vvi da(n, vint (m, 0));
//rep (i, 0, n) {
//	rep (j, 0, m) {
//		if (v[i][j] == '.') {
//			da[i][j] = 1;
//			if (i) da[i][j] += da[i-1][j];
//		}
//	}
//}
//showmat(da); 
*/
