#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
	// Create a Range Query data structure with the maximum elements
	vector<vector<long long>> getRangeQuery(vector<int>& nums, long long n, long long m) {


		vector<vector<long long> > rangeQuery(m, vector<long long>(n, 0));
		for (int i = 0; i < n; i++) rangeQuery[0][i] = nums[i];

		for (int i = 1; i < m; i++) {
			for (int j = 0; j + (1 << i) <= n; j++) {
				rangeQuery[i][j] = max(rangeQuery[i - 1][j], rangeQuery[i - 1][j + (1 << (i - 1))]);
			}
		}
		return rangeQuery;
	}
	long long getMaximum(vector<vector<long long>>& rangeQuery, long long l, long long r, long long m) {
		long long ans = 0;
		for (int i = m; i >= 0; i--) {
			if ((1 << i) <= r - l + 1) {
				ans = max(ans, rangeQuery[i][l]);
				l += (1 << i);
			}
		}
		return ans;
	}
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
		long long n = nums.size();
		long long m = 0;
		while ((1 << m) < n) m++;

		// Create a Range Query data structure with the maximum elements
		vector<vector<long long> > rangeQuery = getRangeQuery(nums, n, m);
		for (auto row : rangeQuery) { for (auto col : row) cout << col << " "; cout << endl; } 

		// Create a hash table to store the indexes for each number
		map<long long, vector<long long>> mp;
		for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);

		// Count the number of subarrays
		for (auto p : mp) {
			int len = p.second.size();
			for (int i = 0; i + k - 1 < len; i++) {
				int l = p.second[i];
				int r = p.second[i + k - 1];
				long long mx = getMaximum(rangeQuery, l, r, m);
				cout << "l = " << l << ", r = " << r << ", mx = " << mx << endl;
				if (mx < p.first) ans++;
			}
		}
		return ans;
    }
};

int main() {
	vector<int>	nums;
	int			k;
	Solution	sol;
	// Test case 1
	nums	= {1,3,2,3,3};
	k		= 2;
	cout << sol.countSubarrays(nums, k) << endl;

	// Test case 2
	nums	= {1,4,2,1};
	k		= 3;
	cout << sol.countSubarrays(nums, k) << endl;
	return 0;
}
