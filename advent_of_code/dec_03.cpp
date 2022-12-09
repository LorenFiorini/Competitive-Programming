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
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

void solve () {
	map<char, int> mp;
	rep (i, 0, 26) mp['a' + i] = i + 1;
	rep (i, 0, 26) mp['A' + i] = i + 1 + 26;

	int ans = 0;
	int n = 300;
	vstr v(n);

	rep(i, 0, n) cin >> v[i];
	

	por (i, 0, n, 3) {

		//show(sz);
		
		set<char> aa(all(v[i]));
		set<char> bb(all(v[i+1]));
		set<char> cc(all(v[i+2]));

		for (auto it = aa.begin(); it != aa.end(); it++) {
			if (bb.find(*it) != bb.end() && cc.find(*it) != cc.end()) {
				ans += mp[*it];
			}
		}
	}


	//15801
	show(ans);
}
/*
void solve () {
	map<char, int> mp;
	rep (i, 0, 26) mp['a' + i] = i + 1;
	rep (i, 0, 26) mp['A' + i] = i + 1 + 26;

	int ans = 0;
	int n = 300;
	vstr v(n);

	rep(i, 0, n) cin >> v[i];
	

	rep (i, 0, n) {
		int sz = len(v[i]) >> 1;
		string s = v[i].substr(0, sz);
		string t = v[i].substr(sz, sz);
		showp(s, t);
		//show(sz);
		
		set<char> tt(all(t));
		set<char> ss(all(s));

		for (auto it = tt.begin(); it != tt.end(); it++) {
			if (ss.find(*it) != ss.end()) {
				ans += mp[*it];
			}
		}
	}


	//2711
	//2851
	//3081

	show(ans);
}*/

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini