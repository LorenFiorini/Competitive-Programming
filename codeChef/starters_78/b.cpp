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

void fun(ll &a, ll &b, ll &c, ll &d, ll bit) {
	a <<= 1;
	b <<= 1;
	c <<= 1;
	d <<= 1;
	if (bit == 0) {
		a += 1;
		b += 1;
		c += 1;
		d += 1;
	} else {
		a += 1;
		b += 1;
		c += 1;
		//d += 1;

	}
}

void solve () {
	//ll ans = 0;
	ll n, N;
	cin >> n;
	N = n;
	if (n == 1) {
		cout << "1 4 3 2 \n";
		return;
	}
	else if (n == 0) {
		show(-1);
		return;
	} 
	vll v;
	while (n > 0) {
		v.pb(n % 2);		
		n /= 2;
	}
	reverse(all(v));
	ll m = len(v);
	//showv(v);

	ll a = (1 << (6));
	ll b = (1 << (6));
	ll c = (1 << (6));
	ll d = (1 << (6));

	a += (1 << (4));
	b += (1 << (5));

	ll cnt = 0;
	rep (i, 0, m) {
		fun(a, b, c, d, v[i]);
	}

	cout << a << " ";
	cout << b << " ";
	cout << c << " ";
	cout << d << "\n";

	ll num = ((a & b) | c) ^ d;
	//show((a & b));
	//show(((a & b) | c));
	//show((((a & b) | c) ^ d));
	//showp(N, num);
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
/*
((a & b) | c) ^ d = n

((a & b) | c) = n ^ d


((1 & 1) | 1) ^ 1 = 0
((1 & 0) | 0) ^ 0 = 0
((0 & 1) | 0) ^ 0 = 0

((1 & 1) | 1) ^ 0 = 1

*/