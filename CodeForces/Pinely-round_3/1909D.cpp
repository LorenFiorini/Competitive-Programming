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
#define por(i_, a_, b_, in_) for (ll i_ = a_; i_ != (b_); i_ += in_)
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
#define showmap(mp_) for (auto a_: mp_) {cout << a_.first << ' ' << a_.second << '\n';} cout << '\n';


void	solve(void) {
	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	vll v(n);
	rep (i, 0, n) cin >> v[i];
	
	map<ll, ll> mp;
	rep (i, 0, n) mp[v[i]]++;

	ll sz = mp.size();
	set<ll> tops;

	while (sz > 2) {
		ll num = mp.rbegin()->first;
		ll fac = mp.rbegin()->second;

		// if (tops.find(num) != tops.end()) {	show(-1);	return ;}
		tops.insert(num);
		
		mp.erase(num);
		// if (mp.empty()) break;

		ll a = (num + k) / 2;
		ll b = a;
		if ((num + k) % 2 == 1) {
			b++;
			if (b >= num) {	show(-1);	return ;}
		} 
		ans += fac;

		ll ta = mp[a] + fac;
		mp.erase(a);
		mp.insert(mk(a, ta));
		ll tb = mp[b] + fac;
		mp.erase(b);
		mp.insert(mk(b, tb));

		sz = mp.size();
		std::cout << " " << sz << endl;
		// showmap(mp);
	}
	
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
