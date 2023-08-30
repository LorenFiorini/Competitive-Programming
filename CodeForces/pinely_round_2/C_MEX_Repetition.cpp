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

int n, k;
int not_there(vector<int> &a) {
	vector<bool> b(n + 1, false);
	for (int i = 0; i < n; i++) {
		b[a[i]] = true;
	}
	for (int i = 0; i <= n; i++) {
		if (b[i] == false) {
			return i;
		}
	}
	return n;
}
void solve(void) {
	int ans = 0;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = not_there(a);
	//cout << "\n"; showv(a); 
	
	k = (k) % (n + 1);
	int id = (n + 1) - k;
	for (int i = id; i < id + n; i++) {
		// cout << a[(i + k) % (n + 1)] << " ";
		cout << a[(i) % (n + 1)] << " ";
		
	}
	cout << "\n";
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
C. MEX Repetition
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a1,a2,…,an
 of pairwise distinct integers from 0
 to n
. Consider the following operation:

consecutively for each i
 from 1
 to n
 in this order, replace ai
 with MEX(a1,a2,…,an)
.
Here MEX
 of a collection of integers c1,c2,…,cm
 is defined as the smallest non-negative integer x
 which does not occur in the collection c
. For example, MEX(0,2,2,1,4)=3
 and MEX(1,2)=0
.

Print the array after applying k
 such operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤105
). The description of the test cases follows.

The first line of each test case contains two integers n
 and k
 (1≤n≤105
, 1≤k≤109
).

The second line contains n
 pairwise distinct integers a1,a2,…,an
 (0≤ai≤n
) representing the elements of the array before applying the operations.

It is guaranteed that the sum of n
 over all test cases does not exceed 105
.

Output
For each test case, print all n
 elements of the array after applying k
 operations.
*/
