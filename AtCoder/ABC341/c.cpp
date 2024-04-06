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
typedef int64_t ll;
typedef	int64_t	lint;
typedef pair<ll, ll> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll,ll> mpii;
typedef set<ll> seti;
typedef multiset<ll> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(i_, a_, b_, in_) for (int64_t i_ = a_; i_ != (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
// #define len(v_) v_.size()
#define precision(d_) cout << setprecision(d_) << fixed;
// Debugging Tools
#define show(x_) cout << x_ << '\n';
#define shows(x_) cout << x_ << ' ';
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << '\n';
#define showp(x_, y_) cout << x_ << ' ' << y_ << '\n';
#define showv(v_) for (auto a_: v_) {cout << a_ << ' ';} cout << '\n';
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << ' ' << a_->second << '\n';} cout << '\n';

void get_a(string &t, int64_t &u, int64_t &d, int64_t &l, int64_t &r) {
	int64_t row = 0;
	int64_t col = 0;
	for (char ch: t) {
		if (ch == 'U') {
			row--;
			u = max(u, abs(row));
		} else if (ch == 'D') {
			row++;
			d = max(d, row);
		} else if (ch == 'L') {
			col--;
			l = max(l, abs(col));
		} else if (ch == 'R') {
			col++;
			r = max(r, col);
		} 
	}
}

bool check(vector<string> &v, int64_t row, int64_t col, int64_t h, int64_t w,
 string &t,  int64_t it, int64_t tn) {
	if (v[row][col] == '#') return 0;
	if (it == tn) return 1;

	if (t[it] == 'U') {
		return check(v, row - 1, col, h, w, t, it + 1, tn);
	} else if (t[it] == 'D') {
		return check(v, row + 1, col, h, w, t, it + 1, tn);
	} else if (t[it] == 'L') {
		return check(v, row, col - 1, h, w, t, it + 1, tn);
	} else if (t[it] == 'R') {
		return check(v, row, col + 1, h, w, t, it + 1, tn);
	} 
	return false;
}

void	solve(void) {
	int64_t ans = 0;
	string t;
	int64_t h, w, sn, tn;
	cin >> h >> w >> sn;
	cin >> t;
	vector<string> v(h);
	rep(i, 0, h) cin >> v[i];
	
	// show(t);
	// showv(v);

	ll u = 0, d = 0, l = 0, r = 0;
	get_a(t, u, d, l, r);
	// shows(u); shows(d); shows(l); shows(r); 

	rep (i, u, h - d) {
		rep (j, l, w - r) {
			if (check(v, i, j, h, w, t, 0, sn)) {
				ans++;
			}
		}
	}
	show(ans);
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
