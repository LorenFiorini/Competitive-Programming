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


void solve () {
	int ans = 0;
	string num;
	cin >> num;
	if (num == "1") {showp(1,0); return;}
	int sz = len(num);
	string a, b;
	int carry = 0;

	rep (i, 0, sz) {
		char ca = '0';
		char cb = '0';
		int d = num[i] - '0'; // 0-9
		if (carry) d += 10; // 10-19
		
		if (d == 19 && i+1 == sz) {

		}

		carry = d % 2;
		ca += d / 2;
		cb += d / 2;

		if (!i && ca == '0' && cb == '0') continue;

		a.pb(ca);
		b.pb(cb);
	}
	if (carry) {
		int i = sz - 1;
		while (i > 0 && b[i] == '9') i--;
		b[i]++;
	}
	
	
	showp(a, b);
}
/*
void solve () {
	int ans = 0;
	int n;
	cin >> n;
	int a = n / 2;
	int b = n / 2 + n % 2;
	
	showp(a, b);
}
*/
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
19 = 14 + 5
	

199 = 144 + 54 +1


999 = 549 + 449

199 = 144 + 54 +1

*/