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
	int n;
	cin >> n;
	
	
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

/*
D. Prefix Purchase
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have an array a
 of size n
, initially filled with zeros (a1=a2=…=an=0
). You also have an array of integers c
 of size n
.

Initially, you have k
 coins. By paying ci
 coins, you can add 1
 to all elements of the array a
 from the first to the i
-th element (aj+=1
 for all 1≤j≤i
). You can buy any ci
 any number of times. A purchase is only possible if k≥ci
, meaning that at any moment k≥0
 must hold true.

Find the lexicographically largest array a
 that can be obtained.

An array a
 is lexicographically smaller than an array b
 of the same length if and only if in the first position where a
 and b
 differ, the element in array a
 is smaller than the corresponding element in b
.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the size of arrays a
 and c
.

The second line of each test case contains n
 integers c1,c2,…,cn
 (1≤ci≤109
) — the array c
.

The third line of each test case contains a single integer k
 (1≤k≤109
) — the number of coins you have.

It is guaranteed that the sum of all n
 values across all test cases does not exceed 2⋅105
.

Output
For each test case, output n
 integers a1,a2,…,an
 — the lexicographically largest array a
 that can be obtained.
*/