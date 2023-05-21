class Solution {
    vector<bool> a;
    int n;
    int dfs(string &s, vector<int> &dp, int i) {
        if (dp[i] < n) return dp[i];

        cout << i << ": "; for (auto &t: dp) cout << t << " "; cout << endl;
        int j = 0;
        while (j < 26) a[j++] = false;
        j = i;
        while (j < n && !a[s[j] - 'a']) {
            a[s[j] - 'a'] = true;
            j++;
        }
        while (i < j) {
            dp[i] = min(dp[i], dfs(s, dp, j));
            j--;
            cout << i << ": "; for (auto &t: dp) cout << t << " "; cout << endl;
        }
        dp[i] += 1;
        
        cout << i << ": "; for (auto &t: dp) cout << t << " "; cout << endl;
        return dp[i];
    }
public:
    int partitionString(string s) {
        a.resize(26, 0);
        n = s.size();
        vector<int> dp(n + 1, n);
        dp[n] = 0;

        cout << "   "; for (auto &t: s) cout << t << " "; cout << "-\n";
        dfs(s, dp, 0);
        return dp[0];
    }
};