class Solution {
    void debug(vector<int>& v_) {
        for (auto a_: v_) {
            cout << a_ << " ";
        }
        cout << "\n";
    }
    void debugg(vector<vector<int>>& mat_) {
        for (auto v_: mat_) {
            for (auto a_: v_) {
                cout << a_ << " ";
            }
            cout << "\n";
        }
    }
    void debuggg(vector<vector<vector<int>>>& A) {
        for (auto mat_: A) {
            debugg(mat_);
            cout << "\n";
        }
    }
    int n;
    int suma = 0;
    vector<int> bfs(vector<vector<vector<int>>> &adj, int S, int T, int target) {
        vector<int> parent(n, 0);
        vector<int> sum(n, 1e9 + 1);
        vector<int> minus_one_found(n, 0);
        
        queue<int> q;
        q.push(S);
        parent[S] = -1;
        sum[S] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (auto &v: adj[u]) {
                if (sum[v[0]] > sum[u] + (v[1] > 0 ? v[1] : 1)) {
                    sum[v[0]] = sum[u] + (v[1] > 0 ? v[1] : 1);
                    minus_one_found[v[0]] = minus_one_found[u] + (v[1] == -1 ? 1 : 0);
                    parent[v[0]] = u;
                    q.push(v[0]);
                }
            }
        }
        if (sum[T] <= target && minus_one_found[T] == 0) {
            vector<int> ans;
            int u = T;
            while (u != S) {
                ans.push_back(u);
                u = parent[u];
            }
            ans.push_back(S);
            suma = target - (sum[T] - minus_one_found[T]);
            return ans;
        }
        return {};
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n_, vector<vector<int>>& edges, int S, int T, int target) {
        n = n_;
        vector<vector<vector<int>>> A(n);
        
        for (auto &e: edges) {
            A[e[0]].push_back({e[1], e[2]});
            A[e[1]].push_back({e[0], e[2]});
        }
        //cout << "A\n";        debuggg(A);
        
        vector<int> path = bfs(A, S, T, target);
        //cout << "path\n";        debug(path);
        if (path.size() > 0) {
            int m = edges.size();
            int k = path.size();
            vector<vector<int>> ans(edges.begin(), edges.end());
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                if (ans[i][2] != -1) continue;
                //cout << "ans[" << i << "]: ";        debug(ans[i]);
                for (int j = 0; j < k-1; ++j) {
                    if ((ans[i][0] == path[j] && ans[i][1] == path[j+1]) || (ans[i][0] == path[j+1] && ans[i][1] == path[j])) {
                        ans[i][2] = 1;
                        temp = ans[i];
                        suma--;
                        break;
                    }
                }
                if (ans[i][2] != 1) {
                    ans[i][2] = 1e9 + 1;
                }
                //debug(ans[i]);
            }
            for (int i = 0; i < m; ++i) {
                if (temp == ans[i]) {
                    ans[i][2] += suma;
                    break;
                }
            }
            
            return ans;
        }
        return {};
    }
};