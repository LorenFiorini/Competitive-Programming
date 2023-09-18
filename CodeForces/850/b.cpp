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
3 10 5
65 95 165
40 65 145

40 70 140 (when -25, only )
[35,45]

[55,75]
*/

void solve () {
	ll n, w, h;
	cin >> n >> w >> h;
	vll A(n);
	rep (i, 0, n) cin >> A[i];
	vll B(n);
	rep (i, 0, n) cin >> B[i];

	// maximum shift [l, r]
	ll le, ri;

	ll pla = A[0] - w;
	ll plb = B[0] - h;
	ll pra = A[0] + w;
	ll prb = B[0] + h;

	//le = plb - pla;
	//ri = prb - pra;
	//showp(le, ri);
	//ll mx = plb - pla;
	//ll mn = prb - pra;
	ll L = plb - pla;
	ll R = prb - pra;

	rep (i, 0, n) {
		pla = A[i] - w;
		plb = B[i] - h;
		pra = A[i] + w;
		prb = B[i] + h;
		
		le = plb - pla;
		ri = prb - pra;

		L = min(L, le);
		R = max(R, ri);
		//showp(le, ri);
		//showp(L, R);
		//show("");
		
		if (R > L) {
			show("NO");
			return;
		}


		//mx = max(mx, max(le, ri));
		//mn = min(mn, min(le, ri));
	}

	
	show("YES");
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
