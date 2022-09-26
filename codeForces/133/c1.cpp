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

int m, n = 2;
/*
vvi ending(vvi &v) {
	vvi vec(2, vint(m));
	vec[0][m-1] = max(v[0][m-1] + 2, v[1][m-1] + 1);
	vec[1][m-1] = max(v[1][m-1] + 2, v[0][m-1] + 1);

	for (int j = m-2; j >= 0; j--) {
		//if (j % 2)
		vec[0][j] = max(v[0][j] + 2*(m-j) , v[1][j] + 1);
		//if (j+1 < m) 
		vec[0][j] = max(vec[0][j], vec[0][j+1] + 1);


		vec[1][j] = max(v[1][j] + 2*(m-j) , v[0][j] + 1);
		//if (j+1 < m) 
		vec[1][j] = max(vec[1][j], vec[1][j+1] + 1);
	}
	return vec;
}

int allway(vvi &v, int r, int c, int ans) {
	rep(j, c+1, m) {
		ans = max(ans , v[r][j]) + 1;
	}
	for (int j = m-1; j >= c; j--) {
		ans = max(ans, v[r==0][j]) + 1;
	}
	return ans;
}*/

vvi ending(vvi &v) {
	vvi vec(2, vint(m));
	vec[0][m-1] = max(v[0][m-1] + 2, v[1][m-1] + 1);
	vec[1][m-1] = max(v[1][m-1] + 2, v[0][m-1] + 1);

	for (int j = m-2; j >= 0; j--) {
		rep(i, 0, n) {

			vec[i][j] = max(v[i][j] + 2*(m-j) -1, 
				max(vec[i][j+1] + 1, v[(i == 0)][j])) + 1;
		}
	}
	return vec;
}

void dfs(vvi &v, vvi &end, int row, int col, int &ans, int val) {
	showp(row, col);

	// option 1 
	//int end = allway(v, row, col, val);
	ans = min(ans, max(end[row][col] -1, val + 0));

	show(ans);
	show(val);
	//show(end);

	// option 2
	val = max(val, v[row == 0][col]) + 1;
	if (col + 1 < m) {
		val = max(val, v[row == 0][col + 1]) + 1;
		dfs(v, end, (row == 0), col + 1, ans, val);
	} else {
		ans = min(ans, val);
	}
}

void solve () {
	int ans = 1e9;
	cin >> m;
	vvi v(n, vint(m));
	rep(i, 0, n) rep(j, 0, m) cin >> v[i][j];
	vvi end = ending(v);
	showvv(end, n, m);

	dfs(v, end, 0, 0, ans, 0);

	show(ans);
	cout << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
