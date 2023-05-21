class Solution {
    int solve(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        int ans = 0;
        vector<vector<int>> adj(n, vector<int> (n, 1e8));
        for (int i = 0; i < n; i++) adj[i][i] = 0;
        //for (int i = 0; i < n; i++) adj[i][i] = price[i];
        for (auto p: edges) {
            //adj[p[0]][p[1]] = price[p[1]] + price[p[0]];
            //adj[p[1]][p[0]] = price[p[0]] + price[p[1]];
            adj[p[0]][p[1]] = price[p[1]];
            adj[p[1]][p[0]] = price[p[0]];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (max(adj[i][k], adj[k][j]) < 1e8)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
        //for (auto b: adj) {for (auto a: b) cout << a << "\t";cout <<endl;}
        
        set<pair<int, int>> st;
        for (auto p: trips) {
            pair<int, int> par = {p[0], p[1]}; //{min(p[0], p[1]), max(p[0], p[1])};
            if (st.find(par) != st.end()) {
                //cout << p[0] << " " << p[1] << " " << adj[p[0]][p[1]];
                cout << " same trip\n";
            }
            st.insert(par);
            swap(par.first, par.second);
            if (st.find(par) != st.end()) {
                //cout << p[0] << " " << p[1] << " " << adj[p[0]][p[1]];
                cout << " opposite trip\n";
            }
            
            
            
            //int a = price[p[0]] + adj[p[0]][p[1]];
            //int b = price[p[1]] + adj[p[1]][p[0]];
            //if (a != b) cout << "rsuogh\n";
            //ans += min(a, b);
            //ans += adj[p[0]][p[1]];
            ans += price[p[0]] + adj[p[0]][p[1]];
        }
        cout << ans << endl;
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
        int ans = 1e9;
        vector<int> color = bfs(n, edges);
        
        //for (auto a: color) cout << a << " "; cout << endl;
        
        for (int j = 0; j < 2; j++) {
            vector<int> p(n);
            for (int i = 0; i < n; i++) {
                p[i] = price[i];
                if (color[i] == j) {
                    p[i] = price[i] / 2;
                }
            }
            int a = solve(n, edges, p, trips);
            ans = min(ans, a);
        }
        
        
        return ans;
    }
};