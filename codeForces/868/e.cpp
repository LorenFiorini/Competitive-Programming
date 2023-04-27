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


int dfs(vvi &adj, vint &vis, int cur) {
	vis[cur] = 1;

	int ans = 1;
	for (int nxt: adj[cur]) {
		if (!vis[nxt]) ans += dfs(adj, vis, nxt);
	}
	return ans;
} 

void solve () {
	int ans = 0;
	int n, l, r, a, b;
	cin >> n >> l >> r;
	vvi adj(n);
	rep (i, 0, n) {
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	// count connected components
	b = 0;
	vint com;
	vint vis(n, 0);
	rep (i, 0, n) {
		if (!vis[i]){
			a = dfs(adj, vis, i);
			if (a >= l) {
				com.pb(a);
				b += (a >= 2*l);
			}

		}
	}
	

	sort(all(com));
	int sz = len(com);
	a = sz - b;
	while (sz > 0 && com[sz - 1] >= l) {
		int tmp = (com[sz-1] >= 2*l);

		if ((a + 2*b) % 2) {
			//if (com[sz-1] )
			com[sz-1] -= r;
		} else {
			com[sz-1] -= l;
		}

		if (com[sz - 1] < l) {
			com.pop_back();
			sz--;
			if (tmp) b--;
			else a--;
		} else {
			int j = sz-1;
			while (j > 0 && com[j-1] > com[j]) {
				swap(com[j-1], com[j]);
				j--;
			}
			if (tmp && com[j] < 2*l) {a++; b--;}
		}
		//showv(com);
		//cout << endl;
		ans++;
	}
	//showv(com);
	
	if (ans % 2) {
		show("Alice");
	} else {
		show("Bob"); 
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

		if (sz == 2 && com[0] < 2*l) {

			com[sz - 1] -= l;
		} else {
			com[sz - 1] -= r;
		}


		*/

