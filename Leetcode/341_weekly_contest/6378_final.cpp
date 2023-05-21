class Solution {
    
    bool make_contribution(vector<vector<int>>& adj, vector<int>& cnt, int pre, int cur, int end, int val) {
        cnt[cur] += val;
        if (cur == end) return 1;

        for (auto nxt: adj[cur]) {
            if (nxt != pre && make_contribution(adj, cnt, cur, nxt, end, val)) 
                return 1;
        }
        cnt[cur] -= val;
        return 0;
    }
    int dfs(vector<vector<int>> &dp, vector<vector<int>>& adj, vector<int>& cnt, vector<int>& price, int pre, int cur, bool prnt) {
        if (dp[cur][prnt] != -1) return dp[cur][prnt];

        dp[cur][prnt] = cnt[cur] * price[cur];
        int a = cnt[cur] * price[cur] / 2;

        for (auto nxt: adj[cur]) {
            if (nxt == pre) continue;
            dp[cur][prnt] += dfs(dp, adj, cnt, price, cur, nxt, 0);
            if (!prnt) a += dfs(dp, adj, cnt, price, cur, nxt, 1);
        }

        if (!prnt) dp[cur][prnt] = min(dp[cur][prnt], a);
        return dp[cur][prnt];
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> dp(n, vector<int> (2, -1));
        vector<vector<int>> adj(n);
        for (auto p: edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        vector<int> cnt(n, 0);

        map<pair<int, int>, int> count;
        for (auto p: trips) count[{min(p[1], p[0]), max(p[1], p[0])}]++;
        for (auto p: count) make_contribution(adj, cnt, -1, p.first.first, p.first.second, p.second);
        
        //for (auto a: cnt) cout << a << " "; cout <<endl;

        return dfs(dp, adj, cnt, price, -1, 0, 0);
    }
};
