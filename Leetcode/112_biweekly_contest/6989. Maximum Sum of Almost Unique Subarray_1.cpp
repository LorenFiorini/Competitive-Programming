/*
You are given an integer array nums and two positive integers m and k.

Return the maximum sum out of all almost unique subarrays of length k of nums. If no such subarray exists, return 0.

A subarray of nums is almost unique if it contains at least m pairwise distinct elements.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0, n = nums.size();
		unordered_map<int, int> mp;
		long long i = 0, j = 0;
		long long sum = 0;

		while (j < n) {
			mp[nums[j]]++;
			sum += nums[j];
			if (j - i + 1 == k) {
				if (mp.size() >= m) {
					ans = max(ans, sum);
				}
				mp[nums[i]]--;
				if (mp[nums[i]] == 0) mp.erase(nums[i]);
				sum -= nums[i];
				i++;
			}
			j++;
		}
		return ans;
    }
};


int main() {
	Solution sol;
	vector<int> t1 = {2,6,7,3,1,7};
	cout << sol.maxSum(t1, 3, 4) << endl;

	vector<int> t2 = {5,9,9,2,4,5,4};
	cout << sol.maxSum(t2, 1, 3) << endl;

	vector<int> t3 = {1,2,1,2,1,2,1};
	cout << sol.maxSum(t3, 3, 3) << endl;
	return 0;
}
