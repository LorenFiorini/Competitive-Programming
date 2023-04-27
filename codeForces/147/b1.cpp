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

/*
void check(vint &a, vint &b, int L, int R) {
	map<int, int> ma;
	map<int, int> mb;
	rep (i, L, R+1) {
		ma[a[i]]++;
		mb[b[i]]++;
	}
	int i = L, j = L;

	while (ma != mb) {

	}
}

void check(vint &a, vint &b, int L, int R) {
	map<int, int> mp;
	rep (i, L, R+1) {
		mp[b[i]]++;
	}

	int dif = mp.size();
	int i = L, j = L;
	rep (i, L, R+1) {
		mp[a[i]]--;
		if (mp[a[i]] == 0) {
			dif--;
		} else if (mp[a[i]] < 0) {
			dif--;
		}
	}
	
}
*/


/*
void check(vint &a, vint &b, int L, int R) {
	int n = R - L + 1;
	vint ca(n);
	vint cb(n);
	rep(i, 0, n) {
		ca[i] = a[L + i];
		cb[i] = b[L + i];
	}
	sort(all(ca));

	//if (ca == cb) return 

}
*/

int ans, le, ri;
void check(vint &a, vint &b, int L, int R) {	
	//cout << "check:" << L << " " << R << endl;
	int i = L, l = L-1;
	while (i <= R) {
		//if (R+1 - l < ans) break;
		
		if (a[i] > b[i])
		{
			int j = i;
			map<int,int> mp;
			while (j <= R && a[i] >= b[j])
			{
				mp[b[j]]++;
				mp[a[j]]--;
				if (a[i] == b[j]) break;
				j++;
			}

			bool ok = 1;
			for (auto p: mp) {
				ok &= (p.second == 0);
				if (!ok) break;
			}
			if (!ok) {
				l = j-1;
			} 
			i = j;
		} else if (a[i] < b[i]) {
			l = i;
			i++;
		} else {
			i++;
		}

		//cout << "len " << l << " " << i << endl;
		
		if (i - l > ans) {
			ans = max(ans, i - l);
			le = l + 2;
			ri = i + 1;	
		}
		
	}

	//if (ca == cb) return 

}

void solve () {
	ans = 0;
	int n;
	cin >> n;
	vint a(n);
	rep (i, 0, n) cin >> a[i];
	vint b(n);
	rep (i, 0, n) cin >> b[i];
	
	// search for ordered subsequences
	le = 0, ri = 0;
	int mx = 0;

	// length of at least 2
	rep (i, 1, n) {
		if (b[i-1] > b[i]) continue;

		int l, r;
		l = i - 1;		
		while (i < n && b[i-1] <= b[i]) {
			i++;
		}
		r = i;
		// from l until r the array b is ordered
		//if (r - l + 1 <= mx) continue;
		check(a, b, l, r);

	}

	// of length 1
	//if (mx == 0)
	//{
	//	rep (i, 0, n) {
	//		if (a[i] == b[i]) {
	//			le = ri = i + 1;
	//			break;
	//		}
	//	}
	//}
	
	showp(le, ri);
	//show(ans);
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



	while (1) {

		while (j < n && a[j] == b[j]) {
			j++;
		}
		ans = 
	}
*/

