/*

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        set<pair<int, int> > pq;
        for (int i = 0; i < n; i++) {
            pq.insert({nums[i], i});
        }
        
        while (!pq.empty()) {
            pair<int, int> p = *pq.begin();
            pq.erase(p);

            auto it = pq.begin();
            while (it != pq.end() && abs(it->first - p.first) <= limit) {
                if (p.second > it->second) {
                    pair<int, int> q = *it;
                    pq.erase(q);
                    
                    swap(p.second, q.second);
                    pq.insert(q);
                    it = pq.begin();
                } else {
                    it++;
                }
            }
            ans[p.second] = p.first;
        }
        
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        
        for (int i = n-1; i >= 0; i--) {
            
            int j = i + 1;
            while (j < n && abs(v[j][0] - v[i][0]) <= limit) {
                if (v[i][1] > v[j][1]) {
                    swap(v[i][1], v[j][1]);
                }
                j++;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[v[i][1]] = v[i][0];
        }
        
        return ans;
    }
};



class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        
        while (changed) {
            changed = false;
            for (int i = n-1; i >= 0; i--) {
                int j = i + 1;
                while (j < n && abs(v[j][0] - v[i][0]) <= limit) {
                    if (v[i][1] > v[j][1]) {
                        swap(v[i][1], v[j][1]);
                    }
                    j++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans[v[i][1]] = v[i][0];
        }
        
        return ans;
    }
};





/**
 * @brief This approach is working but it is not efficient enough to pass all the test cases.
 * It is giving TLE for some test cases.
 */

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int changed = false;
            int j = i + 1;
            while (j < n && abs(v[j][0] - v[i][0]) <= limit) {
                if (v[i][1] > v[j][1]) {
                    swap(v[i][1], v[j][1]);
                    changed = true;
                }
                j++;
            }
            if (changed) {
                i = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[v[i][1]] = v[i][0];
        }
        return ans;
    }
};







class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--) {
            // int changed = false;
            int j = i - 1;
            while (j < n && abs(v[j][0] - v[i][0]) <= limit) {
                if (v[i][1] < v[j][1]) {
                    swap(v[i][1], v[j][1]);
                    // changed = true;
                }
                j++;
            }
            // if (changed) {
            //     i = -1;
            // }
        }
        for (int i = 0; i < n; i++) {
            ans[v[i][1]] = v[i][0];
        }
        return ans;
    }
};