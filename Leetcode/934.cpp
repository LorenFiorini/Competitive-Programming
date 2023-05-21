class Solution {
    void debugg(vector<vector<int>>& mat_) {
        for (auto v_: mat_) {
            for (auto a_: v_) {
                cout << a_ << " ";
            }
            cout << "\n";
        }
    }
    vector<int> d{0,0,1,-1};
    void fun(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<vector<int>> &start, int R, int C, int n) {
        grid[R][C] = 2;
        vis[R][C] = 1;
        start.push({R,C});

        for (int k = 0; k < 4; k++) {
            int r = R + d[k];
            int c = C + d[3-k];
            if (min(r, c) < 0 || max(r, c) >= n || grid[r][c] != 1 || vis[r][c] == 1)
                continue;
            fun(grid, vis, start, r, c, n);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n , vector<int> (n, 0));
        queue<vector<int>> q;

        // Island to 2
        bool found = 0;
        for (int i = 0; (!found) && i < n; i++) {
            for (int j = 0; (!found) && j < n; j++) {
                if (grid[i][j] == 1) {
                    fun(grid, vis, q, i, j, n);
                    found = 1;
                    break;
                }
            }
        }
        debugg(grid);
        debugg(vis);
        // BFS

		while (!q.empty()) {
			int R = q.front()[0];
			int C = q.front()[1];
			q.pop();

			for (int k = 0; k < 4; k++) {
				int r = R + d[k];
				int c = C + d[3-k];
				if (min(r, c) < 0 || max(r, c) >= n || grid[r][c] == 2 || vis[r][c] > 0) {
					continue;
				}
				vis[r][c] = vis[R][C] + 1;
				if (grid[r][c] == 1) {
					return vis[R][C];
				}
				q.push({r, c});
			}
		}
        return 0;
    }
};