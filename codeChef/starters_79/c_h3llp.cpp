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
#define showp(x, y) cout << x << " " << y << ": ";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

// 1 	Chef 		wins
// 0 	Chefina 	wins
bool dfs(vvi &v, int x, int y, bool turn) {
	//cout << x << "  " << y << "\t";
	//// Return the winner
	//if (turn) {
	//	show("CHEF");
	//} else {
	//	show("CHEFINA");
	//}

	//if (min(x, y) == 1) return (turn);
	if (min(x, y) < 0) return (turn);

	if (v[y][x] != 5) return v[y-1][x-1];
	
	bool ans = !turn;
	if (turn) {
		// Chef
		//if (x == 2 && y < 2) return 1;
		if ((dfs(v, x - 1, y - 1, turn == 0) == turn) ||
			(dfs(v, x - 2, y, turn == 0) == turn)) {
			ans = 1;
		}
	} else {
		// Chefina
		//if (x < 2 && y == 2) return 0;
		if ((dfs(v, x - 1, y - 1, turn == 0) == turn) ||
			(dfs(v, x, y - 2, turn == 0) == turn)) {
			ans = 0;
		}
	}

	v[y][x] = ans;
	return ans; 
}

void solve () {
	ll ans = 0;
	ll x, y;
	cin >> x >> y;
	//if (dfs(x, y, 1)) {
	//	show("CHEF");
	//} else {
	//	//cout << x-y << "\t";
	//	show("CHEFINA");
	//}
	
	int n = 25;
	vvi v(n, vint(n, 5));
	v[1][1] = v[1][2] = v[2][1] = 1;
	v[2][2] = v[3][2] = v[2][3] = 0;
	rep (i, 1, n) {
		rep (j, 1, n) {
			showp(i, j);
			if (dfs(v, i, j, 1)) {
				//v[j][i] = 1;
				show("CHEF");
			} else {
				cout << i-j << "\t";
				show("CHEFINA");
			}
		}
	}
	


	showmat(v);
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
Base Cases
1 1	->	0 0 Chef 
1 2	->	0 1	Chef
2 1	->	1 0 or 	0 1 	Chef
2 2	->	0 2	not	1 1	Chef
2 3 -> 	0 2	Chef


*/