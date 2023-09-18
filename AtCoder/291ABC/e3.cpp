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

vector<seti> adj;
vector<bool> vis;
vint v;
int n, m, a, b;

bool cycle(int cur) {
	if (v[cur] > n) return 1;
	vis[cur] = 1;

	for (auto nxt: adj[cur]) {
		if (vis[nxt]) return 1;

		if (v[nxt] >= v[cur] + 1) continue;
		v[nxt] = v[cur] + 1;

		if (cycle(nxt)) return 1;
	}

	vis[cur] = 0;
	return 0;
}

void solve () {
	cin >> n >> m;
	adj.resize(n);
	v.resize(n, 1);
	vis.resize(n, 0);

	rep (i, 0, m) {
		cin >> a >> b;
		a--; b--;
		adj[a].insert(b);
	}
	rep (i, 0, n) {
		if (cycle(i)) {
			show("No");
			return;
		}
	}


	seti uni(all(v));

	if (len(uni) < n) {
		show("No"); 
	} else {
		show("Yes");
		showv(v);
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
/*

*/
