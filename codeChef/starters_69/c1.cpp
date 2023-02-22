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
//
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
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
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second
/*
	0 	1 	2

	X 	K   K => K called mn
	X 	1 	0 => 6 => 4 to K==
	X 	2 	0 => 5 => 3 to K==
	X 	3 	0 => 4 => 2 to K==
	X 	1 	2 => 3 => 1 to K==
	X 	2 	2 => 2

1 0 -> 6
2 0 -> 5 == 
3 0 -> 4 == 0 1 --> 01 02 20(+5) -> 7 
4 0 -> 3 == 

	Even 
	X 	4 	0 => 3
	X 	6 	0 => min(3 + 5, 4 + 4)
	X 	8 	0 => min(3 + 3,)

	Odd 
	X 	5 	0 => 3 + 6 
	X 	7 	0 => 3
while (d > 3) {
	ans += 3;
	d -= 4;
}
*/

void solve () {
	int ans = 0, n;
	cin >> n;
	vint v(n);
	vint cnt(3, 0);

	rep (i, 0, n) {
		cin >> v[i];
		v[i] %= 3;
		cnt[v[i] % 3]++;
	}

	int mn = min(cnt[1], cnt[2]);
	ans += mn;

	if (cnt[1] > mn) {
		int d = cnt[1] - mn;
		ans += (d / 4) * 3;
		d %= 4;
		if (d == 1) ans += 6;
		if (d == 2) ans += 5;
		if (d == 3) ans += 4;
	}
	if (cnt[2] > mn) {
		int d = cnt[2] - mn;

		ans += (d / 4) * 3;
		d %= 4;
		if (d == 1) ans += 4;
		if (d == 2) ans += 5;
		if (d == 3) ans += 6;
	}
	


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