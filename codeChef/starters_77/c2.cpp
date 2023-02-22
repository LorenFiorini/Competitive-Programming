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

ll n, k;
vll A;

bool palin(vll &v) {
	// Is it a palindrome
	int i = 0, j = len(v) - 1;
	while (i < j) {
		if (v[i] != v[j]) return 0;
		i++;
		j--;
	}
	return 1;
}

void odd_case() {
	// N is ODD
	show("YES");
}

void even_case() {
	// N is EVEN
	ll a = 0;
	rep (i, 0, n) {
		a += A[i];
	}


	if (a%2 == 0) {
		show("YES");
	} else {
		show("NO");
	}
}

void solve () {
	cin >> n >> k;
	A.resize(n);
	rep (i, 0, n) cin >> A[i];
	if (n == k) {
		if (palin(A)) {
			show("YES");
		} else {
			show("NO");
		}
	} else if (n % 2 || k % 2) {
		odd_case();
	}  else {
		even_case();
	}

}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
