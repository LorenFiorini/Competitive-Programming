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
#define por(i_, a_, b_, in_) for (auto i_ = a_; i_ != (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
#define len(v_) v_.size()
#define precision(d_) cout << setprecision(d_) << fixed;
// Debugging Tools
#define show(x_) std::cout << x_ << '\n';
#define shows(x_) std::cout << x_ << ' ';
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {std::cout << ((x_&i_)? 1: 0);} std::cout << '\n';
#define showp(x_, y_) std::cout << x_ << ' ' << y_ << '\n';
#define showv(v_) for (auto a_: v_) {std::cout << a_ << ' ';} std::cout << '\n';
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showmap(mp_) for (auto a_: mp_) {std::cout << a_->first << ' ' << a_->second << '\n';} std::cout << '\n';

ll	N;
vll get_v(vll &a, ll n, ll k) {
	vll v(n);

	rep(i, 0, n) v[i] = a[i] % k;

	return v;
}

// set<ll> get_set(set<ll> )
bool	check(vll a, ll k) {
	set<ll> st;

	for (auto num : a) {
		st.insert(num % k);
	}
	// shows(k);
	// shows("st:");
	// showv(st);
	// shows(st.size());
	return len(st) == 2;
}
// ll dfs(set<ll> 

void	solve(void) {
	ll ans = 1;
	cin >> N;
	ll n = N;
	vll a(N);
	rep (i, 0, N) cin >> a[i];
	if (check(a, ans)) {show(ans); return;}
	

	while (!check(a, ans)) {
		ll g = gcd(a[0], a[N-1]);
		rep(i, 1, n-1) {
			g = gcd(g, a[i]);
		}
		ll b = get_v(a, n, ans);
		n = len(b);
		swap(a, n);
	}
	ans = g - 1;
	if (check(a, ans)) {show(ans); return;}


	show(ans);
}
ll modInverse(ll A, ll M) 
{ 
    for (ll X = 1; X < M; X++) 
        if (((A % M) * (X % M)) % M == 1) 
            return X; 
} 

// void	solve(void) {
// 	ll ans = 2;
// 	ll n;
// 	cin >> n;
// 	vll v(n);
// 	rep (i, 0, n) cin >> v[i];

	
// 	ll g = gcd(v[0], v[n-1]);
// 	rep(i, 1, n-1) {
// 		g = gcd(g, v[i]);
// 	}
// 	// ll h = modInverse(g);
// 	// showp(g, h);

// 	show(ans);
// }
int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	
	cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
