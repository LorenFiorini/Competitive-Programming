class Solution {
    int solve(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        // price.length == n
        int ans = 0;
        vector<vector<int>> adj(n, vector<int> (n, 1e9));
        for (int i = 0; i < n; i++) adj[i][i] = 0;
        for (auto p: edges) {
            adj[p[0]][p[1]] = price[p[1]];
            adj[p[1]][p[0]] = price[p[0]];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        //for (auto b: adj) {for (auto a: b) cout << a << " ";cout <<endl;}
        for (auto p: trips) {
            ans += price[p[0]];
            ans += adj[p[0]][p[1]];
        }
        
        return ans;
    }
    vector<int> bfs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto p: edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<int> color(n, -1);
        
        queue<int> q;
        q.push(0);
        color[0] = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (auto nxt: adj[cur]) {
                if (color[nxt] == -1) {
                    color[nxt] = (color[cur] == 0);
                    q.push(nxt);
                }
            }
        }
        return color;
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        // price.length == n
        int ans = 0;
        vector<int> color = bfs(n, edges);
        
        vector<int> p0(price.begin(), price.end());
        vector<int> p1(price.begin(), price.end());
        
        for (int i = 0; i < n; i++) {
            if (color[i]) {
                p1[i] /= 2;
            } else {
                p0[i] /= 2;
            }
        }
        return min(solve(n, edges, p0, trips), solve(n, edges, p1, trips));
    }
};

/*
23
1
429




No

23
1
434
*/