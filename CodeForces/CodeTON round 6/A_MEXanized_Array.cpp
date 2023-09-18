#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";


void solve (void) {
	int ans = 0;
	int n, k, x;
	cin >> n >> k >> x;

	int final_mex = k;
	int max_element_possible = x;

	if (x < k-1 || n < k) {
		ans = -1;
	} else {
		int N = n - k;
		ans = (k * (k - 1)) / 2;
		// cout << ans << ",N=" << N << "\t";

		if (x > k && N > 0) {
			ans += N * (x);
		} else if (N > 0) {
			ans += N * (k - 1);
			// ans += 1;
		}
	}
	
	cout << ans << endl;
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return (0);
}

/**
 * By Lorenzo Fiorini
 * 
 * Contact
 * 	- linkedin.com/in/lorenfiorini/
 *	- github.com/LorenFiorini
*/ 

/*A. MEXanized Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given three non-negative integers n
, k
, and x
. Find the maximum possible sum of elements in an array consisting of non-negative integers, which has n
 elements, its MEX is equal to k
, and all its elements do not exceed x
. If such an array does not exist, output −1
.

The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance:

The MEX of [2,2,1]
 is 0
, because 0
 does not belong to the array.
The MEX of [3,1,0,1]
 is 2
, because 0
 and 1
 belong to the array, but 2
 does not.
The MEX of [0,3,1,2]
 is 4
, because 0
, 1
, 2
 and 3
 belong to the array, but 4
 does not.
Input
The first line contains a single integer t
 (1≤t≤1000
) — the number of test cases. Then follows the description of the test cases.

The only line of each test case contains three integers n
, k
, and x
 (1≤n,k,x≤200
).

Output
For each test case, output a single number — the maximum sum of elements in a valid array, or −1
, if such an array does not exist.
*/
