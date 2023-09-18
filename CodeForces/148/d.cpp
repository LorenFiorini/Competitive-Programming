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
#define por(i_, a_, b_, in_) for (int i_ = a_; i < (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
#define len(v_) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

/*D1. Red-Blue Operations (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The only difference between easy and hard versions is the maximum values of 𝑛
 and 𝑞
.

You are given an array, consisting of 𝑛
 integers. Initially, all elements are red.

You can apply the following operation to the array multiple times. During the 𝑖
-th operation, you select an element of the array; then:

if the element is red, it increases by 𝑖
 and becomes blue;
if the element is blue, it decreases by 𝑖
 and becomes red.
The operations are numbered from 1
, i. e. during the first operation some element is changed by 1
 and so on.

You are asked 𝑞
 queries of the following form:

given an integer 𝑘
, what can the largest minimum in the array be if you apply exactly 𝑘
 operations to it?
Note that the operations don't affect the array between queries, all queries are asked on the initial array 𝑎
.*/

void solve () {
	ll n, q;
	cin >> n >> q;
	vll a(n);
	vll b(q);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, q) cin >> b[i];
	
	// {a[i], a[i] + i, 0}
	vll vec;
	vector<vll> v(n, vll(3, 0)); 
	rep (i, 0, n) {
		v[i][0] = a[i];
		v[i][1] = a[i] + i + 1;
		v[i][2] = 0;
	}
	sort(all(v));

	while (v[0][2] == 0) {
		vec.push_back(v[0][0]);
		swap(v[0][1], v[0][0]);
		v[0][2] = 1;
		ll i = 0;
		while (i < n - 1 && v[i][0] >= v[i + 1][0]) {
			for (ll j = 0; j < 3; j++)
				swap(v[i][j], v[i + 1][j]);
			i++;
		}
	}
	vec.push_back(v[0][0]);

	ll res = vec[0];
	ll sz = vec.size();
	rep (i, 0, q) {
		if (b[i] < sz) {
			res = vec[b[i]];
		} else {
			ll tmp = (b[i] - sz) % 2;
			res = vec[sz-1 - tmp];
		}
		cout << res << " ";
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}

// Lorenzo Fiorini
