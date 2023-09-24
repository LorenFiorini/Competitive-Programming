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

int n, mm, q, x;
int mini;

void solve () {
	vint v(n+1, 1);
	int e = min(n, x);
	int i = n, m = m-1;

	while (x > 0 && i > 0) {
		showp(i, x);
		i = min(i, x);
		if (x >= i * m) {
			v[i] += m;
			x -= i * m;
		} else {
			// x < i * m
			// x = i * M s.t. M<m
			// M = x/i;
			// x -= i * (x / i)
			int M = x / i;
			v[i] = M;
			x -= (i * M);
		}
		i--;
	}
	i++;
	show("--");
	
	if (x > 0) {
		show(-1);
		return;
	}

	showp(i, e+1 - i);
	rep (id, i, e + 1) {
		cout << v[id] << " ";
	}
	cout << "\n";

	show("-----");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> q;
	
	mini = (n * (n+1)) / 2;
	while (q--) {
		cin >> x;
		if (x >= mini) {
			solve();
		} else {

		}
	}
	
	return 0;
}

// Lorenzo Fiorini
