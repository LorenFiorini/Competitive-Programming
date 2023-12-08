/**
D. Neutral Tonality
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given an array 𝑎
 consisting of 𝑛
 integers, as well as an array 𝑏
 consisting of 𝑚
 integers.

Let LIS(𝑐)
 denote the length of the longest increasing subsequence of array 𝑐
. For example, LIS([2,1⎯⎯,1,3⎯⎯])
 = 2
, LIS([1⎯⎯,7⎯⎯,9⎯⎯])
 = 3
, LIS([3,1⎯⎯,2⎯⎯,4⎯⎯])
 = 3
.

You need to insert the numbers 𝑏1,𝑏2,…,𝑏𝑚
 into the array 𝑎
, at any positions, in any order. Let the resulting array be 𝑐1,𝑐2,…,𝑐𝑛+𝑚
. You need to choose the positions for insertion in order to minimize LIS(𝑐)
.

Formally, you need to find an array 𝑐1,𝑐2,…,𝑐𝑛+𝑚
 that simultaneously satisfies the following conditions:

The array 𝑎1,𝑎2,…,𝑎𝑛
 is a subsequence of the array 𝑐1,𝑐2,…,𝑐𝑛+𝑚
.
The array 𝑐1,𝑐2,…,𝑐𝑛+𝑚
 consists of the numbers 𝑎1,𝑎2,…,𝑎𝑛,𝑏1,𝑏2,…,𝑏𝑚
, possibly rearranged.
The value of LIS(𝑐)
 is the minimum possible among all suitable arrays 𝑐
.
Input
Each test contains multiple test cases. The first line contains a single integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛,𝑚
 (1≤𝑛≤2⋅105,1≤𝑚≤2⋅105)
 — the length of array 𝑎
 and the length of array 𝑏
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109)
 — the elements of the array 𝑎
.

The third line of each test case contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (1≤𝑏𝑖≤109)
 — the elements of the array 𝑏
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
, and the sum of 𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛+𝑚
 numbers — the elements of the final array 𝑐1,𝑐2,…,𝑐𝑛+𝑚
, obtained after the insertion, such that the value of LIS(𝑐)
 is minimized. If there are several answers, you can output any of them.
*/

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
typedef int64_t ll;

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
	int n, k;
	cin >> n >> k;
	vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    showv(b);

    for (int i = 0; i < n; i++) {
        // b[i] = (b[i] - i + n) % n;
        b[i] %= n;
        // if (b[i] == i+1) { show("Yes"); return; }
    }

    showv(b);
	show("No");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */

