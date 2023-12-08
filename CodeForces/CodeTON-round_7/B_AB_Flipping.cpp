#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
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
using namespace std;


void solve (void) {
	int ans = 0;
	int n; cin >> n;
	string s; cin >> s;
	vector<int> v(n, 0);
	vector<int> used(n, 0);
	
	for (int i = 0; i < n; i++) {
		v[i] = s[i] - 'A';
	}

	// for (int num : v)  cout << num << " "; cout << endl; // debug


	for (int i = 0; i < n - 1; i++) {
		if (v[i] == 0 && v[i + 1] == 1 && used[i] == 0) {
			ans++;
			swap(v[i], v[i + 1]);
			used[i] = 1;
			i -= 2;
		}
	}
	// for (int num : v)  cout << num << " "; cout << endl; // debug

	cout << ans << endl;
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */



/*
B. AB Flipping
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string 𝑠
 of length 𝑛
 consisting of characters 𝙰
 and 𝙱
. You are allowed to do the following operation:

Choose an index 1≤𝑖≤𝑛−1
 such that 𝑠𝑖=𝙰
 and 𝑠𝑖+1=𝙱
. Then, swap 𝑠𝑖
 and 𝑠𝑖+1
.
You are only allowed to do the operation at most once for each index 1≤𝑖≤𝑛−1
. However, you can do it in any order you want. Find the maximum number of operations that you can carry out.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤1000
). Description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of string 𝑠
.

The second line of each test case contains the string 𝑠
 (𝑠𝑖=𝙰
 or 𝑠𝑖=𝙱
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer containing the maximum number of operations that you can carry out.

Example
inputCopy
3
2
AB
4
BBBA
4
AABB
outputCopy
1
0
3
Note
In the first test case, we can do the operation exactly once for 𝑖=1
 as 𝑠1=𝙰
 and 𝑠2=𝙱
.

In the second test case, it can be proven that it is not possible to do an operation.

In the third test case, we can do an operation on 𝑖=2
 to form 𝙰𝙱𝙰𝙱
, then another operation on 𝑖=3
 to form 𝙰𝙱𝙱𝙰
, and finally another operation on 𝑖=1
 to form 𝙱𝙰𝙱𝙰
. Note that even though at the end, 𝑠2=𝙰
 and 𝑠3=𝙱
, we cannot do an operation on 𝑖=2
 again as we can only do the operation at most once for each index.*/