
class Solution {
    void dfs(vector<vector<int>>& v, int n, int i) {
        int j = i + 1;
        while (j < n && abs(v[j][0] - v[i][0]) <= limit) {
            if (v[i][1] > v[j][1]) {
                swap(v[i][1], v[j][1]);
            }
            j++;
        }
        dfs(v, n, i+1);
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        dfs(v, n, 0);
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[v[i][1]] = v[i][0];
        }
        return ans;
    }
};