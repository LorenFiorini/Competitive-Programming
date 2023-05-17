#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

// Problem
/*Problem
You are given an array A=A 1​ ,A 2​ ,…,A N​  of size N.Consider a subsequence S=S 1​ ,S 2​ ,…,S M​  of A. Let us define the Goodness of subsequence S as follows:
1. Sort the subsequence S in non-decreasing order.
2. Then, the Goodness of subsequence S is the number of indices such that S_i​ = i, where (1≤≤∣∣).(1≤i≤∣S∣).For example, suppose A=[10,3,2,5,11,3,1,12], and the subsequence is S=[3,2,5,3,1]. After sorting, S=[1,2,3,3,5], and so the Goodness of S is 4.
Consider all the 2^N −1 possible non-empty subsequences of array A, and find the sum of all their Goodness.

Since the answer can be large, output the answer modulo 10^9 +7.
Note: A sequence S is a subsequence of array A if S can be obtained from A by deletion of several (possibly, zero) elements. For example, [3,1] is a subsequence of [3,2,1] and [4,3,1], but not a subsequence of [1,3,3,7] and [3,10,4].*/

/*
Input Format
The first line of input will contain a single integer T, denoting the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N - the size of the array A.
The second line of each test case contains N space-separated integers, A 1​ ,A 2​ ,A 3​ ,...,A N​.

Output Format
For each test case, output the answer modulo 10^9 +7.
*/

// n choose k ->  
map<pll, ll> mp;
ll mod = 1e9 + 7;

// Binomial Coefficient with Dynamic Programming 
ll choose(ll n, ll k) {
	if (k == 0 || k == n) return 1;
	if (mp.find(mk(n, k)) != mp.end()) return mp[mk(n, k)];
	return mp[mk(n, k)] = (choose(n-1, k-1) + choose(n-1, k)) % mod;
}

void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	map<ll, ll> nums;
	rep (i, 0, n) {
		cin >> v[i];
		nums[v[i]]++;
	}

	sort(all(v));
	//show(""); showv(v);
	
	rep (i, 0, n) {
		if (v[i] <= i+1) {
			//rep (j, 0, n-i) 
			ans += pow(2, n - i - 1);
			ll d = i - v[i];
			if (d > 0 && d <= n - i - 1)
				ans += choose(i, d);
		} else {
			ans += 0;
		}
		ans %= mod;
		//showp(1+i, ans);
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
