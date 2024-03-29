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

void solve () {
	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	vll a(n); // category
	vll b(n); // time
	rep (i, 0, n) cin >> a[i];
	rep (i, 0, n) cin >> b[i];
	
	map<ll , ll> mp;
	rep (i, 0, n) {
		if (mp.find(a[i]) != mp.end()) {
			mp[a[i]] = min(mp[a[i]], b[i]);
		} else {
			mp[a[i]] = b[i];
		}
	}

	ll sz = len(mp);
	if (sz < k) {
		show(-1);
		return;
	}
	/*else {
		auto it = mp.begin();
		while (k--) {
			//cout << ans << " ";
			ans += it->ss;
			it++;
		}
	}*/
	vpii v(sz);
	int i = 0;
	for (auto p: mp) {
		v[i] = {p.ss, p.ff};
		i++;
	}
	sort(all(v));

	i = 0;
	while (k--) {
		ans += v[i].ff;
		i++;
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