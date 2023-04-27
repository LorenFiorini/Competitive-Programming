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
#include <iomanip>
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

vint pr;
int sz;

void help() {
	int N = 3200;
	vint prim(N, 1);
	rep (i, 2, N) {
		if (!prim[i]) continue;
		pr.pb(i);
		por (j, i, N, i) prim[j] = 0;
	}
	//showv(pr);
}
void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	mpii mp;

	//show(sz);
	rep(i, 0, n) {
		int num = v[i];
		int j = 0;

		while (j < sz && num > 1) {
			while (num > 1 && (num % pr[j] == 0)) {
				//cout << "-" << pr[j];
				mp[pr[j]]++;
				num /= pr[j];
			}
			j++;
		}
		if (num > 1) {
			mp[num]++;
		}
	}
	
	int di = 0;
	for (auto p: mp) {
	//	showp(p.ff, p.ss);
		ans += (p.second / 2);
		di += (p.ss % 2);
	}
	ans += (di / 3);

	show(ans);
	//showp(" ", di);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	help();
	sz = len(pr);
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
