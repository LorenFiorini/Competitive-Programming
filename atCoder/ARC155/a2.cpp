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
#define showp(x, y) cout << x << " " << y << endl;
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";


bool palindrome(string s, int le, int ri) {
	while (le < ri) {
		if (s[le] != s[ri]) return 0;
	}
	return 1;
}

string solve () {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;


	bool pal = palindrome(s, 0, n-1);
	//if (k % n == 0 && ) return "Yes";
	//if (k >= n)


	k =  (k % n);
	showp(n, k);
	for (ll i = 0; i < n; i += k) {
		rep (j, 0, k) {
			
			int l = i + j;
			int r = (i + 2*k - (j+1));
			if (max(l, r) >= n) break;
			if (s[l % n] != s[(r) % n]) {
				showp(l, r);
				return "No";
			}
		}

	}
	//if (palindrome(s, min(k, n - k), max(k, n - k) - 1)) return "Yes";
	//else return "No";
	
	return "Yes";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	cout << solve() << endl;
	
	return 0;
}

// Lorenzo Fiorini