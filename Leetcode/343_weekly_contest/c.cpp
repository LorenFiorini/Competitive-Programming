//typedef pair<int, int> pii;

class Solution {
    map<vector<int>, map<vector<int>, int>> adj;
    
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        int n = sr.size();
        int ans = 1e9;
        // {i0, j0} -> {i1, j1}->cost1 ; {i2, j2}->cost2 
        //  adjacency
        
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
        }
        show()
        for (auto road: sr) {
            vector<int> a(2);
            vector<int> b(2);
            a[0] = road[0];
            a[1] = road[1];
            b[0] = road[2];
            b[1] = road[3];
            //int cost = road[4];
            //adj[a].
        }
        return ans;
    }
};




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
    void ad(vector<vector<int>>& sr) {
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
        }
    }
    
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        int n = sr.size();
        int ans = 1e9;
        
        
        
        return ans;
    }
};


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
    int ad(vector<vector<int>>& sr) {
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
        for (auto it = all.begin(); it != all.end(); it++) {
            vector<int> a = *it;
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
        show();
        return adj.size();
    }
    
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        // bfs
        if (start == target) return 0;
        int n = ad(sr);
        int ans = 1e9;
        
        // CurrentCost -> {i1, j1}
        priority_queue<pair<int, vector<int>> > pq;
        for (auto &p: adj[start]) {
            break;
        }
        
        return ans;
    }
};