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


void solve () {
	int n;
	cin >> n;

	string s(n+1, '-');

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			int k = n/j;
			if ((n % j == 0) && i % k == 0) {
				s[i] = j + '0';
				break;
			}
		}
	}

	cout << s << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */

/*
Problem Statement
You are given a positive integer 
N. Print a string of length 
(N+1), 
s 
0
​
 s 
1
​
 …s 
N
​
 , defined as follows.

For each 
i=0,1,2,…,N,

if there is a divisor 
j of 
N that is between 
1 and 
9, inclusive, and 
i is a multiple of 
N/j, then 
s 
i
​
  is the digit corresponding to the smallest such 
j (
s 
i
​
  will thus be one of 1, 2, ..., 9);
if no such 
j exists, then 
s 
i
​
  is -.
Constraints
1≤N≤1000
All input values are integers.
Input
The input is given from Standard Input in the following format:

N
Output
Print the answer.

*/