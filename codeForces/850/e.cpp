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
#define por(i, a, b, in) for (ll i = a; i < (b); i += in)
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
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	//	sort(all(v));
	//	ll j = 1;
	//	rep (i, 0, n) {
	//		while (i < n && v[i] < j) i++;
	//		if (i == n) break;		
	//		ans += v[i] - j;
	//		j++;
	//	}
	
	ll pre = v[0] - 1;
	cout << pre << " ";
	ll mex = (v[0] == 1)? 2: 1;
	ll j = 0;

	for (ll id = 1; id < n; id++){
		ll i = id;
		while (i > 0 && v[i-1] > v[i]) {
			swap(v[i], v[i-1]);
			i--;
		}
		ll dis = id - i;
		if (v[i] == mex) {
			mex++;
			ans = pre - dis;
			j = max(j, i);

		} else if (v[i] < mex) {
			ans = pre;
			j++;

		} else if (v[i] > mex) {
			// ans = pre + (v[i] - mex);
			// + previous
			// + (v[i] - mex)
			// - (i - j+1)
			// - dis 
			ans = pre + (v[i] - mex) - (i - (j+1)) - dis;

			// ans = 0;  or just Recalculating to the right
		}
		//cout << j << " " << i << endl;

		cout << ans << " ";
		pre = ans;
	}
	cout << endl;
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
