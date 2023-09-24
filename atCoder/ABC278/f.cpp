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

int n;

void adja(vstr &vec, vvi &v) {
	rep (i, 0, n) {
		int m = len(vec[i]);
		//show(m);
		rep (j, 0, n) {
			if (i == j) {
				v[i][j] = 0;
			} else if (vec[i][m-1] == vec[j][0]) {
				v[i][j] = 1;
			}
		}
	}
}

void floyd(vvi &v) {
	rep (k, 0, n) {
		rep (i, 0 ,n) {
			rep (j, 0, n) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
}

void solve () {
	int ans = 0;
	cin >> n;
	vstr vec(n);
	rep(i, 0, n) cin >> vec[i];
	//sort(all(vec));
	vvi v(n, vint(n, 1e9));
	adja(vec, v);
	//showvv(v, n, n); cout << endl;
	floyd(v);
	//showvv(v, n, n);

	bool ok = 1;
	rep (i, 0, n/2) {
		rep (j, 0, n/2) {
			ok &= (v[i][j] % 2 == 0);
		}
	}
	if (ok) {
		show("Second");
	} else {
		show("First");
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

/*
0 4 3 1 2 2 
2 0 2 3 1 1 
3 1 0 4 2 2 
2 3 2 0 1 1 
4 2 1 5 0 3 
1 5 4 2 3 0 
First

0 2 2 2 2 3 1 3 3 3 
2 0 2 2 2 3 3 1 3 3 
2 2 0 2 2 3 3 3 1 3 
2 2 2 0 2 1 3 3 3 3 
2 2 2 2 0 3 3 3 3 1 
1 1 1 1 1 0 2 2 2 2 
1 1 1 1 1 2 0 2 2 2 
1 1 1 1 1 2 2 0 2 2 
1 1 1 1 1 2 2 2 0 2 
1 1 1 1 1 2 2 2 2 0 
Second

0 9 3 9 9 9 9 2 9 1 9 3 2 9 9 9 
1 0 4 9 9 1 9 3 9 2 9 4 3 1 9 9 
9 9 0 9 9 9 9 9 9 9 9 1 9 9 9 9 
2 1 5 0 9 2 9 4 9 3 9 5 4 2 9 9 
3 2 6 1 0 3 1 5 9 4 1 6 5 3 1 9 
9 9 3 9 9 0 9 2 9 1 9 3 2 9 9 9 
2 1 5 9 9 2 0 4 9 3 9 5 4 2 9 9 
9 9 1 9 9 9 9 0 9 9 9 1 9 9 9 9 
9 9 9 9 9 9 9 9 0 9 9 9 9 9 9 1 
9 9 2 9 9 9 9 1 9 0 9 2 1 9 9 9 
2 1 5 9 9 2 9 4 9 3 0 5 4 2 9 9 
9 9 1 9 9 9 9 9 9 9 9 0 9 9 9 9 
9 9 1 9 9 9 9 9 9 9 9 1 0 9 9 9 
9 9 3 9 9 9 9 2 9 1 9 3 2 0 9 9 
2 1 5 9 9 2 9 4 9 3 9 5 4 2 0 9 
9 9 9 9 9 9 9 9 1 9 9 9 9 9 9 0 
First
*/