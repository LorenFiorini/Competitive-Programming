c_2.cpp
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
#include <unordered_map>
#include <unordered_set>
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
#define por(i_, a_, b_, in_) for (int i_ = a_; i_ < (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
#define len(v_) v_.size()
#define precision(d_) cout << setprecision(d_) << fixed;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

int get_odd(int n, vint &v) {
	// distance to indexes
	// int cnt = 0;
	// vector<int> used(n, 0);
	// map<int, vector<pii> > mp;
	// rep (i, 0, n) {
	// 	int dis = v[i] - v[i - 1];
	// 	mp[dis].pb({i - 1, i});
	// }

	// int k = n / 2;
	// auto it = mp
	// while (k > 0) {

	// }
	vvi cnt(2, vint(n + 2, 0));
	rep (i, 0, n-1) {
		if (i % 2 == 0) {
			cnt[0][i + 1] = abs(v[i] - v[i + 1]);

		} else {
			cnt[1][i + 1] = abs(v[i] - v[i + 1]);

		}
	}
	vvi pre(2, vint(n + 2, 0));
	rep (i, 0, n) {
		rep (j, 0, 2) {
			pre[j][i + 1] = cnt[j][i] + pre[j][i];
		}
	}

	// showmat(cnt);
	// showmat(pre);
	int ans = 1e9;
	por (i, 0, n, 2) {
		int num =  pre[0][i] + (pre[1][n-1] - pre[1][i]);
		ans = min(ans, num);
	}
	return ans;
}

void solve (void) {
	int ans = 0;
	int n, k;
	cin >> n >> k;

	map<int, int> mp;
	rep(i, 0, k) {
		int num;
		cin >> num;
		mp[num]++;
	}

	vint v;
	for (auto p: mp) {
		if (p.ss % 2 == 1) {
			v.push_back(p.ff);
		}
	}

	int sz = len(v);

	if (sz % 2 == 0) {
		rep (i, 1, sz) {
			ans += v[i] - v[i - 1];
		}
	} else {
		// showv(v);
		ans = get_odd(sz, v);
	}
	
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
