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
typedef	int64_t	lint;
typedef pair<ll, ll> pii;
typedef vector<int> vint;
typedef vector<int64_t> vll;
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
#define por(i_, a_, b_, in_) for (auto i_ = a_; i_ != (b_); i_ += in_)
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

int64_t MX = 1e18;
map<pii, int64_t> mp;


int64_t dfs(int64_t n, int64_t m, int64_t k, vll &v, int64_t day, int64_t tickets) {
	if (tickets == k) {
		return 0;
	}
	int64_t need = k - tickets;
	if (day+1 == n) {
		if (need > m)
			return MX;
		return need * (v[day] + tickets);
	}

	pii key = make_pair(day, tickets); 
	if (mp.find(key) != mp.end()) return mp[key];
	int64_t ans = MX;
	int64_t buy = 0, best = 0;

	int64_t days_left = n - day;
	if (days_left * m < need) return MX;

	// while (buy <= m && tickets + buy <= k)
	int64_t le = max(0LL, need - ((days_left - 1) * m));
	int64_t ri = min(m, need);

	while (le < ri) {
		buy = (le + ri) / 2;
		int64_t ret = dfs(n, m, k, v, day + 1, tickets + buy);
		int64_t here = buy * (v[day] + tickets);
		if (ret  >= MX) {
			le = buy + 1;
		} else  {
			if (ret+here < ans) {
				best = buy;
				ans = ret;
			}
			ri = buy;
		}
	}

	mp[key] = ans + le * (v[day] + tickets);
	return mp[key];
}

void	solve(void) {
	mp.clear();
	int64_t ans = 0;
	int64_t n, m, k;
	cin >> n >> m >> k; 
	vll v(n);
    rep (i, 0, n) cin >> v[i];
	
	ans = dfs(n, m, k, v, 0, 0);
	// show('a');

	show(ans);
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	
	cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
