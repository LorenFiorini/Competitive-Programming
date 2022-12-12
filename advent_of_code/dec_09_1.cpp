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
	int ans = 0;
	int n = 8;
	char d, last = 'R';
	int num, x = 0, y = 0, X = 0, Y = 0;
	map<pii, int> mp;
	mp[{x,y}] = 1;


	rep (i, 0, n) {
		cin >> d >> num;
		

		last = d;
		while (num) {

			if (d == 'L') {
				x++;
			} else if (d == 'R') {
				x--;
			} else if (d == 'U') {
				y++;
			} else {
				y--;
			}

			int dist = max(abs(x - X), abs(y - Y));
			if (dist > 1) {
				X = x;
				Y = y;
				if (d == 'L') {
					X--;
				} else if (d == 'R') {
					X++;
				} else if (d == 'U') {
					Y--;
				} else {
					Y++;
				}
				mp[{X, Y}]++;
			}
			
			num--;
		}
		
	}
	
	each(it, mp) {
		if (it->ss > 0) {
			//showp(it->ff.ff, it->ff.ss);
			ans++;
		}
	}
	//show(len(mp));
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

// 6687
// 6524
// 6503

