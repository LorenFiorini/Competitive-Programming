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
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " <ls < it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

ll count(ll num) {
	ll ans = 0;
	while (num % 10 == 0) {
		ans++;
		num /= 10;
	}
	return ans;
}
void solve () {
	ll ans = 0, ten = 10, cnt = 0, five = 5;
	ll n, m;
	cin >> n >> m;
	// zeroes -> number
	map<ll, ll> mp;
	mp[0] = n * m;

	bool niu = 1;
	while (niu) {
		niu = 0;

		ll num = m / ten;
		num *= ten;

		if (num > 0 && num <= m) {
			niu = 1;
			ans = n * num;
			cnt = count(ans);
			mp[cnt] = max(mp[cnt], ans);
			cout << num << " " << ans << endl;
		}

		if (n % 2 == 0) {
			five = ten / 2;
			num += five;
			if (num > 0 && num <= m) {
				niu = 1;
				ans = n * num;
				cnt = count(ans);
				mp[cnt] = max(mp[cnt], ans);
				cout << num << " " << ans << endl;	
			}
		}

		ten *= 10;
	}


	ans = mp.rbegin()->second;
	cout << ans << endl;
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