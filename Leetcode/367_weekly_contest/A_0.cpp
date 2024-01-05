/*
You are given a 0-indexed integer array nums having length n, an integer indexDifference, and an integer valueDifference.

Your task is to find two indices i and j, both in the range [0, n - 1], that satisfy the following conditions:

abs(i - j) >= indexDifference, and
abs(nums[i] - nums[j]) >= valueDifference
Return an integer array answer, where answer = [i, j] if there are two such indices, and answer = [-1, -1] otherwise. If there are multiple choices for the two indices, return any of them.

Note: i and j may be equal.
*/

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
		vector<int> ans = {-1, -1};
		// Number, {First Index, Last Index}
		map<int, pair<int, int>> mp;
		for (int i = 0; i < n; i++) {
			if (mp.find(nums[i]) != mp.end()) 
				mp[nums[i]].second = i;
			else 
				mp[nums[i]] = {i, i};
		}
		for (auto mn: mp) {
			int num = mn.first;
			
			for (auto rit = mp.rbegin(); rit != mp.rend(); rit++) {
				int num2 = rit->first;
				if (abs(num - num2) < valueDifference) {
					break;
				} else if (abs(mp[num].first - mp[num2].second) >= indexDifference) {
					ans[0] = mp[num].first;
					ans[1] = mp[num2].second;
					return ans;
				} else if (abs(mp[num].second - mp[num2].first) >= indexDifference) {
					ans[0] = mp[num].second;
					ans[1] = mp[num2].first;
					return ans;
				}
			}
		}
		return ans;
    }
};
