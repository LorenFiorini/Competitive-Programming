
/*D. Ones and Twos
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a 1
-indexed array 𝑎
 of length 𝑛
 where each element is 1
 or 2
.

Process 𝑞
 queries of the following two types:

"1 s": check if there exists a subarray†
 of 𝑎
 whose sum equals to 𝑠
.
"2 i v": change 𝑎𝑖
 to 𝑣
.
†
 An array 𝑏
 is a subarray of an array 𝑎
 if 𝑏
 can be obtained from 𝑎
 by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.

Input
Each test contains multiple test cases. The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑞
 (1≤𝑛,𝑞≤105
) — the length of array 𝑎
 and the number of queries.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (𝑎𝑖
 is 1
 or 2
) — the elements of array 𝑎
.

Each of the following 𝑞
 lines of each test case contains some integers. The first integer op
 is either 1
 or 2
.

If op
 is 1
, it is followed by one integer 𝑠
 (1≤𝑠≤2𝑛
).
If op
 is 2
, it is followed by two integers 𝑖
 and 𝑣
 (1≤𝑖≤𝑛
, 𝑣
 is 1
 or 2
).
It is guaranteed that the sum of 𝑛
 and the sum of 𝑞
 over all test cases both do not exceed 105
.

Output
For each query with op=1
, output "YES" in one line if there exists a subarray of 𝑎
 whose sum is equals to 𝑠
, otherwise output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
inputCopy
2
5 5
2 1 2 1 2
1 5
1 6
1 7
2 4 2
1 7
3 2
2 2 2
1 6
1 5
outputCopy
YES
YES
NO
YES
YES
NO
Note
Consider the first example:

The answer for the first query is "YES" because 𝑎1+𝑎2+𝑎3=2+1+2=5
.
The answer for the second query is "YES" because 𝑎1+𝑎2+𝑎3+𝑎4=2+1+2+1=6
.
The answer for the third query is "NO" because we cannot find any subarray of 𝑎
 whose sum is 7
.
After the fourth query, the array 𝑎
 becomes [2,1,2,2,2]
.
The answer for the fifth query is "YES" because 𝑎2+𝑎3+𝑎4+𝑎5=1+2+2+2=7.
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

// 2^18 = 262144

// int MAXN = 262144;
// vector<int> a(MAXN, 0);

int N = 262144;
map<int, int> cnt;

void show_vector (vector<int> &v) {
	for (int num : v) 
		cout << num << " ";
	cout << endl;
}

bool is_power_of_two (int x) {
	return x && (!(x & (x - 1)));
}

bool check (vector<int> &v, int val) {
	if (val > v[1]) return 0;
	// Double pointer technique

	int level = 0;
	int l = 1, r = 1;
	int sum = 0;
	while (r < N) {
	// while (r >= l * 2) {
		sum += v[r];
		while (l < (1 << level) && sum > val) {
			sum -= v[l];
			l++;
		}
		if (sum == val)
			return 1;
		else if (sum < val && r == l * 2) 
			return 0;
		r++;
		if (is_power_of_two(r)) level++;
	}
	return false;
}


void solve (void) {
	cnt.clear();
	int n, q; 
	cin >> n >> q;
	vector<int> v(2 * n, 0);
	N = 2 * n;

	for (int i = n; i < 2*n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}

	for (int i = n - 1; i > 0; i--) {
		v[i] = v[2 * i] + v[2 * i + 1];
	}


	// QUERIES
	for (int i = 0; i < q; i++) {
		int op; 
		cin >> op;

		if (op == 1) {
			int s;
			cin >> s;
			
			if (check(v,s) ) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {
			int id, val;
			cin >> id >> val;
			id += n - 1;
			cnt[v[id]]--;
			v[id] = val;
			cnt[v[id]]++;
			while (id > 1) {
				id /= 2;
				v[id] = v[2 * id] + v[2 * id + 1];
			}
		}
	}

}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */


