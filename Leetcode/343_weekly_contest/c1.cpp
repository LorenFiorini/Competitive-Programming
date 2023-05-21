typedef long long ll;
class Solution {
    map<vector<ll>, map<vector<ll>, ll>> adj;
    void show() {
        for (auto &row: adj) {
            cout << "(" << row.first[0] << "," << row.first[1] << "): ";
            for (auto &p: row.second) {
                cout << "(" << p.first[0] << "," << p.first[1] << ")->" << p.second << " ";
            }
            cout << endl;
        }
    }
    vector<vector<ll>> ad(vector<vector<int>>& sr) {
        set<vector<ll>> all;
        for (auto road: sr) {
            vector<ll> a(2);
            vector<ll> b(2);
            a[0] = road[0];
            a[1] = road[1];
            b[0] = road[2];
            b[1] = road[3];
            ll cost = abs(a[0] - b[0]) + abs(a[1] - b[1]);
            adj[a].insert(make_pair(b, cost));
            adj[b].insert(make_pair(a, cost));
            adj[a][b] = min(adj[a][b], (ll) road[4]);
            all.insert(a);
            all.insert(b);
        }
        
        vector<vector<ll>> ans;
        for (auto it = all.begin(); it != all.end(); it++) {
            vector<ll> a = *it;
            ans.push_back(a);
            auto jt = it; jt++;
            for (; jt != all.end(); jt++) {
                vector<ll> b = *jt;
                ll cost = abs(a[0] - b[0]) + abs(a[1] - b[1]);
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
        vector<ll> s(2);
        vector<ll> t(2);
        s[0] = start[0];
        s[1] = start[1];
        t[0] = target[0];
        t[1] = target[1];
        vector<int> tmp(5);
        tmp[0] = start[0];
        tmp[1] = start[1];
        tmp[2] = target[0];
        tmp[3] = target[1];
        tmp[4] = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        sr.push_back(tmp);
        vector<vector<ll>> vec = ad(sr);
        ll n = vec.size();
        ll ans = 1e9;
        
        for (ll k = 0; k < n; k++) {
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    adj[vec[i]][vec[j]] = min(adj[vec[i]][vec[j]], adj[vec[i]][vec[k]] + adj[vec[k]][vec[j]]);
                }
            }
        }
        ans = adj[s][t];
        //show();
        return ans;
    }
};