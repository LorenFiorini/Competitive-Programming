#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
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

bool check(vint &sum) {
	rep (j, 0, m) {
		int no = n - sum[j];
		if (no <= sum[j]) return 0;
	}
	return 1;
}

int dfs(vint &dp, vstr &v, vint &sum, int p, int cnt) {
	if (p == n) {
		if (check(sum)) return cnt;
		return 0;
	}
	if (dp[p] != -1) return dp[p];
	int wo = dfs(dp, v, sum, p + 1, cnt);

	rep (j, 0, m) sum[j] += v[p][j] == v[0][j];
	int wi = dfs(dp, v, sum, p + 1, cnt + 1);
	rep (j, 0, m) sum[j] -= v[p][j] == v[0][j];

	dp[p] = max(wo, wi);
	return dp[p];
}

void solve () {
	
	cin >> n >> m;
	vstr v(n);
	rep(i, 0, n) cin >> v[i];

	vint dp(n + 1, -1);
	vint sum(m, 1);
	int ans = dfs(dp, v, sum, 1, 1);

	show(ans);
	//vint sum(m);
	//rep (j, 0, m) {
	//	rep (i, 0, n) {
	//		sum[j] += v[i][j] == v[0][j];
	//	}
	//}
	//showv(sum);	
	//show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
