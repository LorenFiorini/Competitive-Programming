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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vint v(n);
	rep (i, 0, n) v[i] = s[i] - 'a';

	//showv(v);

	// first op
	rep (i, 1, n) {
		if (v[i-1] == v[i] + 1) {
			int j = i+1;
			while (j+1 < n && v[i] == v[j+1] && abs(v[j] - v[j+1]) == 1) {
				swap(v[j], v[j+1]);
				j++;
			}
			j--; // last Jth equal

			int k = i;
			while (k > 0 && v[k-1] == v[k] + 1) {
				swap(v[k-1], v[j]);
				j--;
				k--;
			}
		}
	}

	//rep (i, 0, n) {
	//	char c = 'a' + v[i];
	//	cout << c;
	//}

	// second op
	int m = 1;
	vvi vec(1, vint(2, 0));
	vec[0][0] = v[0];
	rep (i, 0, n) {
		if (v[i] == vec[m-1][0]) {
			vec[m-1][1]++;
		} else {
			vec.pb({v[i], 1});
			m++;
		}
	}

	rep (id, 1, m-1) {
		if (vec[id-1][0] - 1 == vec[id+1][0] && vec[id][0] + 1 == vec[id+1][0]) {
			swap(vec[id], vec[id+1]);
			swap(vec[id-1], vec[id]);
		}
	}

	rep (i, 0, m) {
		char c = 'a' + vec[i][0];
		while (vec[i][1] > 0) {
			vec[i][1]--;
			cout << c;
		}
	}


	cout << endl;
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
