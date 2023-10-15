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

int mx = 102;
vvi ans(mx);

bool ok(vint &v, int n) {
	vint pre(n + 1, 0);

	rep (i, 0, n) {
		pre[i + 1] = pre[i] + v[i];

		rep (j, 0, i) {
			int sum = pre[i + 1] - pre[j];
			int d = i - j + 1;
			if (sum % d == 0) return 0;
		}
	}
	return 1;
}

void help() {
	ans[1] = {1};
	ans[2] = {2, 1};
	rep (i, 3, mx) {
		if (i % 2) {
			ans[i] = {-1};
		} else {
			ans[i] = ans[i - 2];
			ans[i].pb(i);
			ans[i].pb(i-1);
		}
	}
	/*
	rep (i, 1, 12) {
		vint v(i);
		iota(all(v), 1);
		cout << i << ": ";
		do {
			if (ok(v, i)) {
				ans[i] = v;
				showv(v);
				break;
			}
		} while (next_permutation(all(v)));
		if (ans[i].size() == 0) {
			ans[i] = {-1};
			show("-");
		}
		cout << endl;
	}*/
}




void solve () {
	int n;
	cin >> n;
	showv(ans[n]);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	help();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
/*
1
1 2



*/