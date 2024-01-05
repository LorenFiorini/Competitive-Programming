
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit)
    {
        int n = nums.size();        
        vector<int> ans(n);
        vector<vector<int>> v(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            v[i][0] = nums[i];
            v[i][1] = i;
        }
        sort(v.begin(), v.end());
        // Two pointers
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            cout << i << " " << j << endl; // debug
            set<int> min_heap;
            min_heap.insert(v[i][1]);
            j = i + 1;
            while (j+1 == n || abs(v[j + 1][0] - v[j][0]) <= limit)
            {
                min_heap.insert(v[j][1]);
                j++;
            }
            for (auto it = min_heap.begin(); it != min_heap.end(); it++)
            {
                ans[*it] = v[i][0];
                i++;
            }
        }
        return (ans);
    }
};