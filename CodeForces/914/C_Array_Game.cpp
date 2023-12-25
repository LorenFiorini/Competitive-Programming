/*C. Array Game
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array 𝑎
 of 𝑛
 positive integers. In one operation, you must pick some (𝑖,𝑗)
 such that 1≤𝑖<𝑗≤|𝑎|
 and append |𝑎𝑖−𝑎𝑗|
 to the end of the 𝑎
 (i.e. increase 𝑛
 by 1
 and set 𝑎𝑛
 to |𝑎𝑖−𝑎𝑗|
). Your task is to minimize and print the minimum value of 𝑎
 after performing 𝑘
 operations.

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤2⋅103
, 1≤𝑘≤109
) — the length of the array and the number of operations you should perform.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1018
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛2
 over all test cases does not exceed 4⋅106
.

Output
For each test case, print a single integer — the smallest possible value of the minimum of array 𝑎
 after performing 𝑘
 operations.
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
#include <unordered_map>
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
#include <iomanip>
using namespace std;


void solve (void) {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;

	cout << endl;
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
