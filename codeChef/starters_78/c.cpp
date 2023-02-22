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
#define len(v) (ll) v.size()
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
	ll k, n;
	cin >> n >> k;
	vll a(n);
	rep (i, 0, n) cin >> a[i];
	vll b(n);
	rep (i, 0, n) cin >> b[i];
	
	// map total -> [a,b] minimum a

	map<ll, vll> mp;
	rep (i, 0, n) {
		ll sum = a[i] + b[i];
		mp[sum].pb(a[i]);
	}

	auto it = mp.begin();
	while (it != mp.end()) {
		//showv(it->ss); 

		ll m = len(it->ss);
		if (m == 0) {it++; continue;}
		if (k >= (m * it->ff)) {
			k -= (m * it->ff);
			ans += m;
		} else {
			ll M = k / it->first;
			ans += (k / it->ff);
			k = (k % it->ff);

			auto it2 = it;
			while (it != mp.end())
			{
				sort(all(it->ss));
				//ll mn = *min_element(all(it->second));
				//mn = min(mn, it->ss[0]);
				if (k >= (it->ss[0])) {
					ans += 1;
					show(ans);
					return;
				}
				it++;
			}


			ll fl = it2->ff;
			it = mp.begin();

			while (it != it2) {
				sort(all(it->ss));
				if (it2->ff + it->ss[0] <= k + it->ff) {
					ans += 1;
					show(ans);
					return;
				}
				
				it++;
			}

			break;
		}
		it++;
		if (k == 0) break;
	}

	//showp("left: ", k);
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--) {
		solve();
		//cout << endl;
	}
	
	
	return 0;
}

// Lorenzo Fiorini
