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

bool ok(vint &v, vint &a, int n) {
	for (int i = 0; i < n; i++) {
		int j = 2*i;
		if (a[i] != (v[j] + v[j+1])) return 0;
	}
	return 1;
}

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	if (n % 2 == 0) {show("No"); return;}
	
	vint v(2*n);
	iota(all(v), 1);
	//showv(v);
	vint a(n);
	rep (i, 0, n) a[i] = (2 * n + 1) - n/2 + i;

	do {
		if (ok(v, a, n)) {
			showv(v);
			return;
		}
	} while (next_permutation(all(v)));

	show(ans);
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
/*
1,2,3,...,n,n+1,n+2,n+3,...,2n

Sn =  n * (n+1) / 2

S_{2n} =  2*n * (2*n+1) / 2
	= n * (4n + 2) / 2
	= 2 + 6 + . . . + 4n

Sn 	= 4 * (4+1) / 2 = 10
S2n = 8 * (8+1) / 2 = 36
	= 9+9+9+9
	=
Sn 	= 5 * (5+1) / 2 = 15
S2n = 10 * (10+1) / 2 = 55
	= 11+11+11+11+11
	= 9 + 10 + 11 + 12 + 13
	= (1)
S10 = 1+2+3+4+5 + 6+7+8+9+10
	= (3+6) + (2+8) + (4+7) + (1)
9	= 1+8 = 2+7 = 3+6 = 4+5
	= 8+1 + 7+2


S6 	= 1+2+3 + 4+5+6 = 6(7)/2 = 21 = 6+7+8
	= (2+4) + (1+6) + (3+5)
*/