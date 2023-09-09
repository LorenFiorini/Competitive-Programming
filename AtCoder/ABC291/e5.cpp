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


void solve () {
	int n, m, a, b;
	cin >> n >> m;
	vector<seti>  adj(n); 
	vint v(n, 1);

	rep (i, 0, m) {
		cin >> a >> b;
		a--; b--;
		if (adj[a].find(b) == adj[a].end()) {
			adj[a].insert(b);
			v[b]++;
		}
	}
	showv(v);
	priority_queue<pii> pq;
	rep (i, 0, n) pq.push(make_pair(v[i], i));

	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();

		int cur = p.second;
		if (v[cur] > p.first) continue;

		for (int nxt: adj[cur]) {
			if (v[nxt] < v[cur] + 1) {
				v[nxt] = v[cur] + 1;
				pq.push(make_pair(v[nxt], nxt));
			}
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
