

/*
C. Matching Arrays
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two arrays 𝑎
 and 𝑏
 of size 𝑛
. The beauty of the arrays 𝑎
 and 𝑏
 is the number of indices 𝑖
 such that 𝑎𝑖>𝑏𝑖
.

You are also given an integer 𝑥
. Determine whether it is possible to rearrange the elements of 𝑏
 such that the beauty of the arrays becomes 𝑥
. If it is possible, output one valid rearrangement of 𝑏
.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤2⋅105
, 0≤𝑥≤𝑛
) — the size of arrays 𝑎
 and 𝑏
 and the desired beauty of the arrays.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2𝑛
) — the elements of array 𝑎
.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2𝑛
) — the elements of array 𝑏
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "NO" if it is not possible to rearrange 𝑏
 to make the beauty of the arrays equal to 𝑥
.

Otherwise, output "YES". Then, on the next line, output 𝑛
 integers which represent the rearrangement of 𝑏
.

If there are multiple solutions, you may output any of them.

You can output "YES" and "NO" in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
inputCopy
7
1 0
1
2
1 1
1
2
3 0
2 4 3
4 1 2
3 1
2 4 3
4 1 2
3 2
2 4 3
4 1 2
3 3
2 4 3
4 1 2
5 2
6 4 5 6 2
9 7 9 1 1
outputCopy
YES
2
NO
NO
YES
2 4 1
YES
4 1 2
NO
YES
1 9 9 7 1
Note
In test cases 1 and 2, the beauty of the arrays has to be 0
 since 𝑎1=1≤2=𝑏1
.

In test cases 3, 4, 5 and 6, the only possible beauty of the arrays is 𝑥=1
 and 𝑥=2
. In particular, if 𝑏
 is rearranged to [2,4,1]
, then 𝑎3=3>1=𝑏3
, so the beauty of the arrays is 1
. If 𝑏
 is kept in the same order as given the input, then 𝑎2=4>𝑏2=1
 and 𝑎3=3>2=𝑏3
, so the beauty of the arrays is  2.
*/
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


int N = 0;
void show_vector (vector<int> &v) {
	for (int num : v) 
		cout << num << "\n";
	cout << endl;
}

void show_matrix (vector<vector<int>> &mat) {
	for (vector<int> row : mat) {
		cout << "[";
		for (int i = 0; i < row.size(); i++) {
			cout << row[i];
			if (i < row.size() - 1)
				cout << ", ";
		}
		cout << "]" << endl;
	}
}

int calculate_beauty (vector<vector<int>> &a, vector<int> &b) {
	int beauty = 0;
	for (int i = 0; i < N; i++) {
		if (a[i][0] > b[i])
			beauty++;
	}
	return beauty;
}

int get_max_beauty (vector<vector<int>> &a, vector<int> &b) {
	int max_beauty = 0;
	int i = 0, j = 0;
	while (i < N && j < N) {
		if (a[i][0] <= b[j]) {
			i++;
		} else {
			max_beauty++;
			i++;
			j++;
		}
	}
	return max_beauty;
}

int get_min_beauty (vector<vector<int>> &a, vector<int> &b) {
	int min_beauty = 0;
	// int i = N-1, j = N-1;
	// while (i >= 0 && j >= 0) {
	// 	if (a[i][0] <= b[j]) {
	// 		i--;
	// 		j--;
	// 	} else {
	// 		min_beauty++;
	// 		i--;
	// 	}
	// }
	int na = N-1, nb = N-1;
	int i = 0, j = 0;
	while (i < na && j < N) {
		if (a[i] <= b[j]) {
			i++;
			j++;
		} else {
			min_beauty++;
			j++;
			na--;
		}
	}
	return min_beauty;
}

vector<int> create_beauty_array (vector<vector<int>> &a, vector<int> &b, int x) {
	vector<int> ans(N);
	int i = 0, j = 0;
	queue<int> q;
	while (x > 0 && i < N && j < N) {
		if (a[i][0] > b[j]) {
			ans[a[i][1]] = b[j];
			i++;
			j++;
			x--;
		} else {
			q.push(b[j]);
			j++;
		}
	}
	while (i < N && !q.empty()) {
		ans[a[i][1]] = q.front();
		q.pop();
		i++;
	}
	return ans;
}
void solve (void) {
	// Input
	int n, x;
	cin >> n >> x;
	N = n;
	vector<vector<int>> a(n, vector<int> (3));
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		a[i][1] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	// If already beautiful
	int beauty = calculate_beauty(a, b);
	if (beauty == x) {	cout << "YES" << endl; for (auto num : b) cout << num << " "; cout << endl; return;	}


	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	// MAX BEAUTY
	int max_beauty = get_max_beauty(a, b);
	if (x > max_beauty) { cout << "NO" << endl;	return;	}

	// MIN BEAUTY
	int min_beauty = get_min_beauty(a, b);
	if (x < min_beauty) { cout << "NO" << endl;	return;	}


	// SURELY YES
	cout << "YES" << endl;
	vector<int> ans = create_beauty_array(a, b, x);
	
	// cout << " max_beauty: " << max_beauty << endl; // Debug
	// cout << " min_beauty: " << min_beauty << endl; // Debug
	// cout << " x: " << x << endl; // Debug
	cout << " Final beauty: " << calculate_beauty(a, ans) << endl; // Debug

	// Output
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
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



/*
C. Matching Arrays
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two arrays 𝑎
 and 𝑏
 of size 𝑛
. The beauty of the arrays 𝑎
 and 𝑏
 is the number of indices 𝑖
 such that 𝑎𝑖>𝑏𝑖
.

You are also given an integer 𝑥
. Determine whether it is possible to rearrange the elements of 𝑏
 such that the beauty of the arrays becomes 𝑥
. If it is possible, output one valid rearrangement of 𝑏
.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤2⋅105
, 0≤𝑥≤𝑛
) — the size of arrays 𝑎
 and 𝑏
 and the desired beauty of the arrays.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2𝑛
) — the elements of array 𝑎
.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2𝑛
) — the elements of array 𝑏
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "NO" if it is not possible to rearrange 𝑏
 to make the beauty of the arrays equal to 𝑥
.

Otherwise, output "YES". Then, on the next line, output 𝑛
 integers which represent the rearrangement of 𝑏
.

If there are multiple solutions, you may output any of them.

You can output "YES" and "NO" in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
inputCopy
7
1 0
1
2
1 1
1
2
3 0
2 4 3
4 1 2
3 1
2 4 3
4 1 2
3 2
2 4 3
4 1 2
3 3
2 4 3
4 1 2
5 2
6 4 5 6 2
9 7 9 1 1
outputCopy
YES
2
NO
NO
YES
2 4 1
YES
4 1 2
NO
YES
1 9 9 7 1
Note
In test cases 1 and 2, the beauty of the arrays has to be 0
 since 𝑎1=1≤2=𝑏1
.

In test cases 3, 4, 5 and 6, the only possible beauty of the arrays is 𝑥=1
 and 𝑥=2
. In particular, if 𝑏
 is rearranged to [2,4,1]
, then 𝑎3=3>1=𝑏3
, so the beauty of the arrays is 1
. If 𝑏
 is kept in the same order as given the input, then 𝑎2=4>𝑏2=1
 and 𝑎3=3>2=𝑏3
, so the beauty of the arrays is  2.
*/
