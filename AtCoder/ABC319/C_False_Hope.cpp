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
#define por(i_, a_, b_, in_) for (int i_ = a_; i_ < (b_); i_ += in_)
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

void check_matrix(vector<vector<double> > &c) {
	rep(i, 0, 3) {
		rep(j, 0, 3) {
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve () {
	// Input
	int n = 3;
	vector<vector<double> > C(n, vector<double>(n, 0));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			C[i][j] = x;
		}
	}
	// check_matrix(C);

	// Process
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// cout << setprecision(10) << fixed;
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */




	// // Process
	// // Check if there are 3 consecutive cells with the same number
	// rep (i, 0, n) {
	// 	if (c[i][0] == c[i][1] && c[i][1] == c[i][2]) {
	// 		show("No");
	// 		return;
	// 	}
	// 	if (c[0][i] == c[1][i] && c[1][i] == c[2][i]) {
	// 		show("No");
	// 		return;
	// 	}
	// }

	// // Main Diagonal
	// if (c[0][0] == c[1][1] && c[1][1] == c[2][2]) {
	// 	show("No");
	// 	return;
	// }

	// // Secondary Diagonal
	// if (c[0][2] == c[1][1] && c[1][1] == c[2][0]) {
	// 	show("No");
	// 	return;
	// }

	// // Output
	// show("Yes");

/*Problem Statement
There is a 
3×3 grid with numbers between 
1 and 
9, inclusive, written in each square. The square at the 
i-th row from the top and 
j-th column from the left 
(1≤i≤3,1≤j≤3) contains the number 
c 
i,j
​
 .

The same number may be written in different squares, but not in three consecutive cells vertically, horizontally, or diagonally. More precisely, it is guaranteed that 
c 
i,j
​
  satisfies all of the following conditions.

c 
i,1
​
 =c 
i,2
​
 =c 
i,3
​
  does not hold for any 
1≤i≤3.
c 
1,j
​
 =c 
2,j
​
 =c 
3,j
​
  does not hold for any 
1≤j≤3.
c 
1,1
​
 =c 
2,2
​
 =c 
3,3
​
  does not hold.
c 
3,1
​
 =c 
2,2
​
 =c 
1,3
​
  does not hold.
Takahashi will see the numbers written in each cell in random order. He will get disappointed when there is a line (vertical, horizontal, or diagonal) that satisfies the following condition.

The first two squares he sees contain the same number, but the last square contains a different number.
Find the probability that Takahashi sees the numbers in all the squares without getting disappointed.

Constraints
c 
i,j
​
 ∈{1,2,3,4,5,6,7,8,9} (1≤i≤3,1≤j≤3)
c 
i,1
​
 =c 
i,2
​
 =c 
i,3
​
  does not hold for any 
1≤i≤3.
c 
1,j
​
 =c 
2,j
​
 =c 
3,j
​
  does not hold for any 
1≤j≤3.
c 
1,1
​
 =c 
2,2
​
 =c 
3,3
​
  does not hold.
c 
3,1
​
 =c 
2,2
​
 =c 
1,3
​
  does not hold.
Input
The input is given from Standard Input in the following format:

c 
1,1
​
  
c 
1,2
​
  
c 
1,3
​
 
c 
2,1
​
  
c 
2,2
​
  
c 
2,3
​
 
c 
3,1
​
  
c 
3,2
​
  
c 
3,3
​
 
Output
Print one line containing the probability that Takahashi sees the numbers in all the squares without getting disappointed. Your answer will be considered correct if the absolute error from the true value is at most 
10 
−8
 .
 */
