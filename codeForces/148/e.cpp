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

/*E. Combinatorics Problem
time limit per test4 seconds
memory limit per test1024 megabytes
inputstandard input
outputstandard output
Recall that the binomial coefficient (𝑥𝑦)
 is calculated as follows (𝑥
 and 𝑦
 are non-negative integers):

if 𝑥<𝑦
, then (𝑥𝑦)=0
;
otherwise, (𝑥𝑦)=𝑥!𝑦!⋅(𝑥−𝑦)!
.
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
 and an integer 𝑘
. You have to calculate a new array 𝑏1,𝑏2,…,𝑏𝑛
, where

𝑏1=((1𝑘)⋅𝑎1)mod998244353
;
𝑏2=((2𝑘)⋅𝑎1+(1𝑘)⋅𝑎2)mod998244353
;
𝑏3=((3𝑘)⋅𝑎1+(2𝑘)⋅𝑎2+(1𝑘)⋅𝑎3)mod998244353
, and so on.
Formally, 𝑏𝑖=(∑𝑗=1𝑖(𝑖−𝑗+1𝑘)⋅𝑎𝑗)mod998244353
.

Note that the array is given in a modified way, and you have to output it in a modified way as well.

Input
The only line of the input contains six integers 𝑛
, 𝑎1
, 𝑥
, 𝑦
, 𝑚
 and 𝑘
 (1≤𝑛≤107
; 0≤𝑎1,𝑥,𝑦<𝑚
; 2≤𝑚≤998244353
; 1≤𝑘≤5
).

The array [𝑎1,𝑎2,…,𝑎𝑛]
 is generated as follows:

𝑎1
 is given in the input;
for 2≤𝑖≤𝑛
, 𝑎𝑖=(𝑎𝑖−1⋅𝑥+𝑦)mod𝑚
.
Output
Since outputting up to 107
 integers might be too slow, you have to do the following:

Let 𝑐𝑖=𝑏𝑖⋅𝑖
 (without taking modulo 998244353
 after the multiplication). Print the integer 𝑐1⊕𝑐2⊕⋯⊕𝑐𝑛
, where ⊕
 denotes the bitwise XOR operator.*/

ll mod = 998244353;
map<pair<ll, ll>, ll> dp;

ll choose(ll n, ll k) {
	if (n < k) {
		return 0;
	}
	if (n == k || k == 0) {
		return 1;
	}
	if (dp.find(mk(n, k)) == dp.end()) {
	dp[mk(n, k)] = choose(n-1, k-1) + choose(n-1, k);
	}

	return dp[mk(n, k)];
}

void solve () {
	ll ans = 0;
	ll n, a0, x, y, m, k;
	cin >> n >> a0 >> x >> y >> m >> k;
	vll a(n, a0);
	vll b(n);
	rep (i, 1, n) {
		a[i] = (a[i-1] * x + y) % m;
	}
	
	rep (i, 0, n) {
		b[i] = (a[i] * choose(i+1, k)) % mod;
		if (i) b[i] = (b[i] + b[i-1]) % mod;
		ans ^= (b[i] * (i+1));
	}
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}

// Lorenzo Fiorini
