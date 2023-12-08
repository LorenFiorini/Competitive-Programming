/*C. Anonymous Informant
time limit per test3 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given an array 𝑏1,𝑏2,…,𝑏𝑛
.

An anonymous informant has told you that the array 𝑏
 was obtained as follows: initially, there existed an array 𝑎1,𝑎2,…,𝑎𝑛
, after which the following two-component operation was performed 𝑘
 times:

A fixed point†
 𝑥
 of the array 𝑎
 was chosen.
Then, the array 𝑎
 was cyclically shifted to the left‡
 exactly 𝑥
 times.
As a result of 𝑘
 such operations, the array 𝑏1,𝑏2,…,𝑏𝑛
 was obtained. You want to check if the words of the anonymous informant can be true or if they are guaranteed to be false.

†
A number 𝑥
 is called a fixed point of the array 𝑎1,𝑎2,…,𝑎𝑛
 if 1≤𝑥≤𝑛
 and 𝑎𝑥=𝑥
.

‡
A cyclic left shift of the array 𝑎1,𝑎2,…,𝑎𝑛
 is the array 𝑎2,…,𝑎𝑛,𝑎1
.

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛,𝑘
 (1≤𝑛≤2⋅105
, 1≤𝑘≤109
) — the length of the array 𝑏
 and the number of operations performed.

The second line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤109
) — the elements of the array 𝑏
.

It is guaranteed that the sum of the values of 𝑛
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output "Yes" if the words of the anonymous informant can be true, and "No" if they are guaranteed to be false.*/


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

int n, K;

bool dfs(vector<int> &b, int shift, int k) {
    if (k == K) return true;
    
    // if (b[n - 1] == n || k == 0) {
    //     return 1;
    // }
    for (int i = 1; i <= n; i++) {
        int id = (shift + i) % (n + 1);
        cout << b[id] << " ";
    }
    cout << "\n";
    if (k) return 1;
    for (int i = 1; i <= n; i++) {
        int pos = (shift + i);
        pos = (pos % n) + 1;

        int nxt = pos + b[i];
        nxt = (nxt % n) + 1;

        // int pre = b[i] + (i + 1);
        if (b[i] == nxt) {
            cout << "i: " << i << " pos: " << pos << " nxt: " << nxt << "\n";
            // int nxt_shift = (shift + b[id]) % n;
            if (dfs(b, (shift + b[i]) % n, k + 1)) {
                return true;
            }
            return 1;
        }
    }
    return 0;
}

void solve () {
    int k = 0;
	cin >> n >> K;
	vector<int> b(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> b[i + 1];

    // showv(b);
    

    if (dfs(b, 0, k)) {
        show("Yes");
    } else {
    	show("No");
    }
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

