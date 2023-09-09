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
	long long ans = 0;
	long long n, m, total = 0, maxw = 0;
	cin >> n >> m;
	// Words width
	vector<long long> w(n);
	rep (i, 0, n) {
		cin >> w[i];
		maxw = max(maxw, w[i]);
		total += w[i] + 1;
		// if (i) ++total;
	}

	// Binary search the width of the window
	long long l = maxw, r = total ;

	while (l < r) {
		long long mid = (l + r) / 2;
		long long lines = 1, curw = 0;
		rep (i, 0, n) {
			if (curw + w[i] > mid) {
				++lines;
				curw = 0;
			}
			curw += w[i] + 1;
			// if (i) ++curw;
		}
		// debug
		// cout << "l: " << l << "\tr: " << r << "\t";
		// cout << "mid: " << mid << "\t";
		// cout << "lines: " << lines << "\n";

		if (lines <= m) {
			r = mid;
			ans = mid;
		} else {
			l = mid + 1;
		}
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

/* Lorenzo Fiorini */

/* Problem Statement
Takahashi is displaying a sentence with 
N words in a window. All words have the same height, and the width of the 
i-th word 
(1≤i≤N) is 
L 
i
​
 .

The words are displayed in the window separated by a space of width 
1. More precisely, when the sentence is displayed in a window of width 
W, the following conditions are satisfied.

The sentence is divided into several lines.
The first word is displayed at the beginning of the top line.
The 
i-th word 
(2≤i≤N) is displayed either with a gap of 
1 after the 
(i−1)-th word, or at the beginning of the line below the line containing the 
(i−1)-th word. It will not be displayed anywhere else.
The width of each line does not exceed 
W. Here, the width of a line refers to the distance from the left end of the leftmost word to the right end of the rightmost word.
When Takahashi displayed the sentence in the window, the sentence fit into 
M or fewer lines. Find the minimum possible width of the window.

Constraints
1≤M≤N≤2×10 
5
 
1≤L 
i
​
 ≤10 
9
  (1≤i≤N)
All input values are integers.
Input
The input is given from Standard Input in the following format:

N 
M
L 
1
​
  
L 
2
​
  
… 
L 
N
​
 
Output
Print the answer in one line.
*/
