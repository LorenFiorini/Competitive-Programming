/*You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
		long long n = nums.size();
		// number to count
		map<int, queue<int>> mp;

		// Double pointer
		int i = 0;
		int j = 0;
		while (j < n) {
			mp[nums[j]]++;
			int mx = mp.rbegin()->first;
			if (mp[mx].size() >= k) {
				ans += n - j;

			
    }
};