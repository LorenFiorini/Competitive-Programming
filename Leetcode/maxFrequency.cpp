class Solution {
    void debug_vv(vector<vector<int>>& v) {
        int m = v.size();
        // for (auto nc : v) cout << nc[0] << ": " << nc[1] << endl; // Debug 
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < m; i++) cout << v[i][j] << " ";
            cout << endl;
        }
    }
    void debug_v(vector<int>& v) {
        for (auto a : v) cout << a << " ";
        cout << endl;
    }
    
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        map<int, int> mp;
        for (int num : nums) mp[num]++;
        
        int m = mp.size();
        vector<vector<int>> v;
        for (auto p : mp) v.push_back({p.first, p.second});
        
        debug_vv(v);

        // Prefix sum of frequency
        vector<int> pre(m, 0);
        int cnt = v[0][1];
        for (int i = 1; i < m; i++) {
            pre[i] = pre[i - 1] + cnt * (v[i][0] - v[i - 1][0]);
            cnt += v[i][1];
        }
        vector<int> post(m, 0);
        cnt = v[m - 1][1];
        for (int i = m - 2; i >= 0; i--) {
            post[i] = post[i + 1] + cnt * (v[i + 1][0] - v[i][0]);
            cnt += v[i][1];
        }
        cout << " "; debug_v(pre);
        cout << " "; debug_v(post);
        
        return ans;
    }
};