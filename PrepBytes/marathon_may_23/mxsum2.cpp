/* 
Problem: Large subset
You are given an array A of size N. The task is to find the maximum XOR value of the elements from all the possible subsets.

Input format:
The first line consists of N, the size of the array. Next line contains N space seperated integer corresponding to each element A[i].

Output:
Print out the maximum XOR subset value.

Constraints:
1 <= N <= 10^6

1 <= A[i] <= 10^6

Time limit
1 second

Example
Input:
 5
 6 7 14 4 4 

Output:
 15

Explanation:
subset [6,7,14] has maximum xor value.
*/


/* Solution */
#include <bits/stdc++.h>
using namespace std;



void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	// Create an empty Trie. Every node of Trie is going to contain two children, for 0 and 1 values of a bit.
	vector<vector<int>> trie(2, vector<int>(2, -1));

	// Initialize pre_xor = 0 and insert into the Trie, Initialize result = INT_MIN
	int pre_xor = 0;
	for (int i = 0; i < n; i++) {
		pre_xor ^= a[i];
		int curr = 0;
		for (int j = 31; j >= 0; j--) {
			// Find current bit in given prefix
			int bit = (pre_xor >> j) & 1;
			// Insert bit in current prefix in trie
			if (trie[curr][bit] == -1) trie[curr][bit] = trie.size(), trie.push_back(vector<int>(2, -1));
			curr = trie[curr][bit];
		}
	}

	// Traverse the given array and do the following for every array element arr[i].
	for (int i = 0; i < n; i++) {
		pre_xor ^= a[i];
		int curr = 0, new_xor = 0;
		for (int j = 31; j >= 0; j--) {
			int bit = (pre_xor >> j) & 1;
			// Find the maximum among current prefix xor and it's complement in Trie
			if (trie[curr][1 - bit] != -1) {
				new_xor += (1 << j);
				curr = trie[curr][1 - bit];
			} else {
				curr = trie[curr][bit];
			}
		}
		ans = max(ans, new_xor);
	}

	// Output
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}

// Lorenzo Fiorini

/*
Find the maximum subarray XOR in a given array using trie Data Structure.
Maximize the xor subarray by using trie data structure to find the binary inverse of current prefix xor inorder to set the left most unset bits and maximize the value.

Follow the steps to Implement the idea:
1. Create an empty Trie. Every node of Trie is going to contain two children, for 0 and 1 values of a bit.
2. Initialize pre_xor = 0 and insert into the Trie, Initialize result = INT_MIN
3. Traverse the given array and do the following for every array element arr[i].
	3.1 pre_xor  = pre_xor  ^ arr[i], pre_xor now contains xor of elements from arr[0] to arr[i].
	3.2 Query the maximum xor value ending with arr[i] from Trie.
	3.3 Update the result if the value obtained above is more than the current value of the result.

Time Complexity: O(N)
Space Complexity: O(N)
*/
