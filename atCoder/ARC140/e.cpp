class Solution {
    int dfs(vector<vector<int>> &matrix, int r, int c, vector<vector<bool>> vis) {
        vis[r][c] = 1;
        int co[4] = {1,-1,0,0};
        
        for (int i = 0; i < 4; i++) {
            int R = r + co[i];
            int C = c + co[3-i];
            
            if (min(R,C) >= 0 && max(R,C) < n && !vis[R][C] && matrix[R][C] > matrix[r][c]) {
                
            }
            
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //vector<vector<int>> v(n*n);
        // 1  , 2  , 3 ... m
        // m+1, m+2,   ... 2*m
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j, vis));                
            }
        }
        
    }
};
