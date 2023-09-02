/*
You are given an integer array nums and two positive integers m and k.

Return the maximum sum out of all almost unique subarrays of length k of nums. If no such subarray exists, return 0.

A subarray of nums is almost unique if it contains at least m pairwise distinct elements.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<long long> vector_count_unique(vector<int>& nums, int m) {
		int n = nums.size();
		vector<long long> v;
		int i = 0, j = 0;
		map<int, long long> mp;
		while (j < n) {
			mp[nums[j]]++;
			// while (mp.size() > m) {
			// 	mp[nums[i]]--;
			// 	if (mp[nums[i]] == 0) mp.erase(nums[i]);
			// 	i++;
			// }
			// v.push_back(j - i + 1);
			j++;
		}
		for (auto p: mp) v.push_back(p.second);
		return v;
	}
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
		vector<long long> v = vector_count_unique(nums, m);
		
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