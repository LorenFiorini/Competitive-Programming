class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int n = p1.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            a += p1[i];
            if ((i-1 >= 0 && p1[i-1] == 10) || (i-2 >= 0 && p1[i-2] == 10)) a += p1[i];
            b += p2[i];
            if ((i-1 >= 0 && p2[i-1] == 10) || (i-2 >= 0 && p2[i-2] == 10)) b += p2[i];
        }
        if (a == b) return 0;
        if (a > b) return 1;
        return 2;
    }
};



/*
class Solution {
    map<vector<int>, map<vector<int>, int>> adj;
    void show() {
        for (auto &row: adj) {
            cout << "(" << row.first[0] << "," << row.first[1] << "): ";
            for (auto &p: row.second) {
                cout << "(" << p.first[0] << "," << p.first[1] << ")->" << p.second << " ";
            }
            cout << endl;
        }
    }
    vector<vector<int>> ad(vector<vector<int>>& sr) {
        set<vector<int>> all;
        for (auto road: sr) {
            vector<int> a(2);
            vector<int> b(2);
            a[0] = road[0];
            a[1] = road[1];
            b[0] = road[2];
            b[1] = road[3];
            int cost = abs(a[0] - b[0]) + abs(a[1] - b[1]);
            adj[a].insert(make_pair(b, cost));
            adj[b].insert(make_pair(a, cost));
            adj[a][b] = min(adj[a][b], road[4]);
            all.insert(a);
            all.insert(b);
        }
        
        vector<vector<int>> ans;
        for (auto it = all.begin(); it != all.end(); it++) {
            vector<int> a = *it;
            ans.push_back(a);
            auto jt = it; jt++;
            for (; jt != all.end(); jt++) {
                vector<int> b = *jt;
                int cost = abs(a[0] - b[0]) + abs(a[1] - b[1]);
                if (adj[*it].find(*jt) == adj[*it].end()) {
                    adj[a].insert(make_pair(b, cost));
                }
                if (adj[b].find(a) == adj[b].end()) {
                    adj[b].insert(make_pair(a, cost));
                }
            }
        }
        //show();
        return ans;
    }
    
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        // bfs
        if (start == target) return 0;
        vector<vector<int>> vec = ad(sr);
        int n = vec.size();
        int ans = 1e9;
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[vec[i]][vec[j]] = min(adj[vec[i]][vec[j]], adj[vec[i]][vec[k]] + adj[vec[k]][vec[j]]);
                }
            }
        }
        ans = adj[start][target];
        return ans;
    }
};
*/