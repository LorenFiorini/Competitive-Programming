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

void solve(void) {
	int ans = 0;
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = i + 1;
	}

	int last_index = 0;
	for (int num = 1; num <= n; num++) {
		if (mp[num] > last_index) {
			last_index = mp[num];
		} else {
			ans++;
			last_index = mp[num];
		}
	}


	cout << ans << "\n";
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

/*
B. Split Sort
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a permutation†
 p1,p2,…,pn
 of integers 1
 to n
.

You can change the current permutation by applying the following operation several (possibly, zero) times:

choose some x
 (2≤x≤n
);
create a new permutation by:
first, writing down all elements of p
 that are less than x
, without changing their order;
second, writing down all elements of p
 that are greater than or equal to x
, without changing their order;
replace p
 with the newly created permutation.
For example, if the permutation used to be [6,4,3,5,2,1]
 and you choose x=4
, then you will first write down [3,2,1]
, then append this with [6,4,5]
. So the initial permutation will be replaced by [3,2,1,6,4,5]
.

Find the minimum number of operations you need to achieve pi=i
 for i=1,2,…,n
. We can show that it is always possible to do so.

†
 A permutation of length n
 is an array consisting of n
 distinct integers from 1
 to n
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (n=3
 but there is 4
 in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The first line of each test case contains one integer n
 (1≤n≤100000
).

The second line of each test case contains n
 integers p1,p2,…,pn
 (1≤pi≤n
). It is guaranteed that p1,p2,…,pn
 is a permutation.

It is guaranteed that the sum of n
 over all test cases does not exceed 100000
.

Output
For each test case, output the answer on a separate line.
*/
