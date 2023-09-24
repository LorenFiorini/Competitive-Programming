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
#define showbin(x) for (int i = (1 << 12); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

/*
void solve () {
	int ans = 0;
	int n, m, sz;
	cin >> n >> m;
	// vvi v(m);
	int N = 10;
	vvi v(N, vint(N, 0));

	rep (i, 0, m) {
		cin >> sz;
		rep (j, 0, sz) {
			cin >> num;
			v[i][num-1] = 1;
		}
	}	
	rep ()

	
	
	show(ans);
}*/

int ans = 0;
int n, m, sz, num;

void dfs(vint &v, int val, int p, int cur) {
	ans += (val == cur);
	//vis[i] = 1;
	//showbin(cur);

	rep (i, p + 1, m) {
		dfs(v, val, i, cur | v[i]);
	}
}

void solve () {
	cin >> n >> m;
	vint v(m);

	rep (i, 0, m) {
		cin >> sz;
		rep (j, 0, sz) {
			cin >> num;
			v[i] |= (1 << (num - 1));
		}
	}

	int val = 0;
	rep (i, 0, n) val |= (1 << i);
	vint vis(m, 0);


	//for (auto aa: v) {showbin(aa); }
	//showbin(val);
	rep (i, 0, m) {
		dfs(v, val, i, v[i]);
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
