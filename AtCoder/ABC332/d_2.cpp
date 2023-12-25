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
typedef int64_t ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vll> vvi;
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

ll n, m;

bool check_rows(vvi a, vvi b) {
	rep(i, 0, n) sort(all(a[i]));
	sort(all(a));
	rep(i, 0, n) sort(all(b[i]));
	sort(all(b));

	show("---");
	showmat(a);
	showmat(b);
	return 1;
}

bool check_columns(vvi a, vvi b) {

	return 1;
}

ll solve(vvi &a, vvi &b) {
	
	return 0;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll ans = 0;
	cin >> n >> m;
	vvi A(n, vint(m));
	vvi B(n, vint(m));
	rep(i, 0, n) rep(j, 0, m) cin >> A[i][j];
	rep(i, 0, n) rep(j, 0, m) cin >> B[i][j];

	// showmat(A); // DeBug
	// showmat(B); // Debug
	
	if (check_rows(A, B) && check_columns(A, B)) {
		ans = solve(A, B);
	} else {
		ans = -1;
	}

	cout << ans << endl;
	
	return 0;
}

/* Lorenzo Fiorini */
