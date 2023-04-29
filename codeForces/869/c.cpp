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


/*
++++++[---]+++++


*/
int search_sub(vpii &vp, int n, int left, int right) {
	int ans = 2;
	int mx_len = right - left + 1;

	rep (id, 0, n) {
		if (ans == mx_len) break;
		int le = vp[id].first;
		int ri = vp[id].second;
		
		if (ri < left) continue;
		if (le > right) break;
		
		le = max(le, left);
		ri = min(ri, right);


		int i = id;
		while (i+1 < n && vp[i+1].first - ri < 2) {
			ri = min(ri, right);
			i++;
		}

		int add = 0;
		//if (left < le) 
			add += min(1, le - left);
		
		//if (right > ri) 
			add += min(1, right - ri);
		
		//cout << le << " " << ri << " + " << add << ": " ;
		ans = max(ans, min(ri - le + 1 + add, mx_len));
	}
	
	return ans;
}

void solve () {
	int ans = 0;
	int n, q;
	cin >> n >> q;
	vint v(n);
	rep (i, 0, n) cin >> v[i];

	// find all '>=' subsequences
	// INCLUSIVE
	// better <
	vpii vp;
	rep (i, 0, n-1) {
		if (i+1 < n && v[i] < v[i+1]) {
			int le = i;
			int ri = i + 1;
			int t = i+1;
			while (ri < n && v[ri-1] < v[ri]) ri++;
			//while (max(t, ri) < n && t - ri < 2) {
			//	ri = t;
			//	while (ri < n && v[ri-1] < v[ri]) ri++;
			//	t = ri;
			//	while (t < n-1 && v[t-1] >= v[t]) t++;				
			//}

			vp.pb(make_pair(le, ri-1));
			showp(le, ri-1);

			i = ri-1;
		}
	}

	int sz = vp.size();



	while (q--)
	{
		int le, ri;
		cin >> le >> ri;
		le--; ri--;
		if (ri - le < 2) {
			ans = ri - le + 1;
		} else {
			ans = search_sub(vp, sz, le, ri);
		}
		show(ans);
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
