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


bool palindrome(string &v, int sz) {
	int i = 0, j = sz - 1;
	//showp(i, j);
	while (i < j) {
		if (v[i] == v[j]) return 0;
		i++;
		j--;
	}
	return 1;
}

void dfs(vvi &adj, vector<string> &color, string tmp, int pos, int end, vint &vis, int &ans) {
	//show(tmp);
	//show(ans);
	//showp(pos, end);
	
	if (pos == end) {
		int sz = len(tmp);
		//show(sz);
		if (sz % 2 == 0 && palindrome(tmp, sz)) {
			ans = min(ans, sz - 1);
		}
		return;
	}
	vis[pos] = 1;


	for (auto nxt: adj[pos]) {
		if (vis[nxt]) continue;
		dfs(adj, color, tmp + color[nxt], nxt, end, vis, ans);
	}
	vis[pos] = 0;
}

void solve () {
	int ans = 1e9;
	int n, m, a, b;
	cin >> n >> m;
	//vint color(n);
	vector<string> color(n);
	vvi adj(n);

	rep (i, 0, n){
		cin >> color[i];
	}
	//show(color);

	rep (i, 0, m) {
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}


	vint vis(n, 0);
	string tmp;
	dfs(adj, color, color[0], 0, n-1, vis, ans);

	if (ans == 1e9) ans = -1;
	show(ans);
	//show("--");
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
