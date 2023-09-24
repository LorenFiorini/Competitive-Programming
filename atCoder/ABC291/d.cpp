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

ll mod = 998244353;

void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	vector<vll> v(2, vll(n));
	rep (i, 0, n) cin >> v[0][i];
	rep (i, 0, n) cin >> v[1][i];
	

	//set<ll> blocked;
	//rep (i, 0, n) {
	//	if (v[0][i] == v[1][i]) {
	//		if (st.find(v[0][i]) != st.end()) {
	//			show(0);
	//			return;
	//		}
	//		st.insert(v[0][i]);
	//	}
	//}
	//ll bl = blocked.size();

	vector<vll> dp(2, vll(n, 0));
	dp[0][0] = dp[1][0] = 1;

	rep (k, 1, n) {
		rep (i, 0, 2) {
			rep (j, 0, 2) {
				if (v[i][k] != v[j][k-1]) {
					dp[i][k] += dp[j][k-1];
					dp[i][k] %= mod;
				}
			}
		}
	}
	showmat(v);
	showmat(dp);

	ans = (dp[0][n-1] + dp[1][n-1]) % mod;

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
/*
3
1 2
4 2
3 4

1 2
2 4
3 4


for i = 0
choose 1 then	ans += 2 * (n - 1)
choose 2 then	ans += 2 * (n - 1 - (1))  for other cards than contain
ans += 2 * 2
ans += 2 * 1

for i = 1
choose 2 then	ans += 2 * (n - 1 - i)
choose 4 then	ans += 2 * (n - 1 - (1)) 
*/
