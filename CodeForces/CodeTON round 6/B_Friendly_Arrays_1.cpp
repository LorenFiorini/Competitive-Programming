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

int get_msb (int x) {
	int msb = 0;
	while (x > 0) {
		x >>= 1;
		msb++;
	}
	return msb;
}

void solve (void) {
	vector<int> ans(2);
	int most_significant_bit = 0;
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		most_significant_bit = max(most_significant_bit, get_msb(a[i]));
	}
	ans[0] = (1 << most_significant_bit) - 1;
	for (int j = 0; j < m; j++) cin >> b[j];
	

	// show(most_significant_bit);
	int xor_a = 0;
	for (int i = 0; i < n; i++) {
		xor_a ^= a[i];
	}
	ans[0] = min(ans[0], xor_a);
	ans[1] = xor_a;
	// showp("xor_a", xor_a);

	for (int j = 0; j < m; j++) {
		int num = xor_a | b[j];
		ans[0] = min(ans[0], num);
		ans[1] = max(ans[1], num);
	}
	showv(ans);
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
		x |= (1 << i);
		showbin(x, 5);
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if ((a[j] & x) == x) {
				cnt++;
			}
		}
		if (cnt == n) {
			cout << x << endl;
			ans[0] = min(ans[0], x);
			ans[1] = max(ans[1], x);
		}
*/

/*
B. Friendly Arrays
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two arrays of integers — a1,…,an
 of length n
, and b1,…,bm
 of length m
. You can choose any element bj
 from array b
 (1≤j≤m
), and for all 1≤i≤n
 perform ai=ai|bj
. You can perform any number of such operations.

After all the operations, the value of x=a1⊕a2⊕…⊕an
 will be calculated. Find the minimum and maximum values of x
 that could be obtained after performing any set of operations.

Above, |
 is the bitwise OR operation, and ⊕
 is the bitwise XOR operation.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases. This is followed by the description of the test cases.

The first line of each test case contains two integers n
 and m
 (1≤n,m≤2⋅105
) — the sizes of arrays a
 and b
.

The second line of each test case contains n
 integers a1,a2,…,an
 (0≤ai≤109
) — the array a
.

The third line of each test case contains m
 integers b1,b2,…,bm
 (0≤bi≤109
) — the array b
.

It is guaranteed that the sum of values of n
 and m
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output 2
 numbers: the minimum and maximum possible values of x
 after performing any set of operations.
*/