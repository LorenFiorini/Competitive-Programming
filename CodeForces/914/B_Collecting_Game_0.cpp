/*B. Collecting Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array 𝑎
 of 𝑛
 positive integers and a score. If your score is greater than or equal to 𝑎𝑖
, then you can increase your score by 𝑎𝑖
 and remove 𝑎𝑖
 from the array.

For each index 𝑖
, output the maximum number of additional array elements that you can remove if you remove 𝑎𝑖
 and then set your score to 𝑎𝑖
. Note that the removal of 𝑎𝑖
 should not be counted in the answer.

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤5000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output 𝑛
 integers, the 𝑖
-th of which denotes the maximum number of additional array elements that you can remove if you remove 𝑎𝑖
 from the array and then set your score to 𝑎𝑖
.

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

typedef long long ll;

void print (vector<ll> &a) {
	for (ll i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << endl;
}

void solve (void) {
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	// map number to vector of indexes
	// map<ll, vector<ll>> m;
	// for (ll i = 0; i < n; i++) m[a[i]].push_back(i);

	// map number to result
	map<ll, ll> mp;

	// Sorted copy of a
	vector<ll> sorted(a.begin(), a.end());
	sort(sorted.begin(), sorted.end());

	// Prefix sum of sorted
	vector<ll> pre(n+1, 0);
	for (ll i = 0; i < n; i++) {
		// pre[i] = sorted[i];
		// if (i > 0) pre[i] += pre[i - 1];
		pre[i + 1] = pre[i] + sorted[i];
	}

	cout << endl;
	print(a); // debug
	print(sorted); // debug
	print(pre); // debug

	mp[sorted[n - 1]] = n - 1;
	for (ll i = n - 2; i >= 0; i--) {
		mp[sorted[i]] = max(mp[sorted[i]], i);
		// if (pre[i] >= sorted[i]) {
		// 	mp[sorted[i]] = max(mp[sorted[i]], mp[sorted[i + 1]] );
		// 	// mp[sorted[i]] = max(mp[sorted[i]], i);
		// }
		//  else
			// mp[sorted[i]] = max(mp[sorted[i]], i);
		
		// cout << "i: " << i << endl;
		// for (auto x : mp) cout << " " << x.first << ": " << x.second << endl;
	}

	// for (ll i = 1; i < n; i++) {
	// 	// if (mp.find(sorted[i-1]) == mp.end()) {
	// 	// 	continue;
	// 	// }
	// 	if (pre[i] >= sorted[i]) {
	// 		mp[sorted[i-1]] = max(mp[sorted[i-1]], mp[sorted[i]] - 1);
	// 		mp[sorted[i-1]] = max(mp[sorted[i-1]], i - 1);
	// 	}
	// }

	for (ll i = 0; i < n; i++) {
		cout << mp[a[i]] << " ";
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
