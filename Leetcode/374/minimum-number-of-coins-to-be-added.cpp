/*
You are given a 0-indexed integer array coins, representing the values of the coins available, and an integer target.

An integer x is obtainable if there exists a subsequence of coins that sums to x.

Return the minimum number of coins of any value that need to be added to the array so that every integer in the range [1, target] is obtainable.

A subsequence of an array is a new non-empty array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.
*/


#define show(VAR) cout << VAR << endl;
#define showv(CON) for(auto VAR : CON) cout << VAR << " "; cout << endl;

class Solution {
    int N, T;
    void dfs(vector<int>& coins, vector<int>& dp, int id, int pos) {
        if (pos > T) return;
        if (dp[pos] != 0) return;
        dp[pos] = 1;
        for (int i = id + 1; i < N; i++) {
            if (coins[i] <= T && dp[coins[i]] == 0)
                dfs(coins, dp, i);
        }
    }
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        
        N = coins.size();
        T = target;
        vector<int> dp(target + 1);

        for (int i = 0; i < N; i++) {
            if (coins[i] <= target && dp[coins[i]] == 0)
                dfs(coins, dp, i, 0);
        }
        showv(dp);
        return 1;
    }
};