class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n);
        
        priority_queue<pair<int, int> > pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i]});
        }
        
        
        while (!pq.empty()) {
            
        }
        
        return ans;
    }
};






class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        set<pair<int, int> > pq;
        for (int i = 0; i < n; i++) {
            pq.insert({nums[i], i});
        }
        
        int id = 0;
        while (id < n && !pq.empty()) {
            pair<int, int> p = *pq.begin();
            pq.erase(p);

            if (p.second == id) {
                ans[id] = p.first;
            } else {
                
                pair<int, int> q = p;
                auto it = pq.begin();
                
                while (it != pq.end() && abs(it->first - p.first) <= limit) {
                    if (q.second > it->second) {
                        q = *it;
                    }
                    it++;
                }
                ans[q.second] = p.first;
                pq.erase(q);
                pq.insert({q.first, p.second});
            }
            while (id < n && ans[id] != -1) id++;
        }
        
        return ans;
    }
};

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
            pair<int, int> q = p;
            auto it = pq.begin();
            
            while (it != pq.end() && abs(it->first - p.first) <= limit) {
                if (q.second > it->second) {
                    q = *it;
                }
                it++;
            }
            if (p == q) {
                ans[p.second] = p.first;
            } else {
                pq.erase(q);
                ans[q.second] = p.first;
                pq.insert({q.first, p.second});
            }
        }
        
        return ans;
    }
};





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