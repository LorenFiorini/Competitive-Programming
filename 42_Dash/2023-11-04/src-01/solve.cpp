
#include "marvin_404_not_found.hpp"

/** @brief Solve the problem
 * 
 * @param grid Vector containing the grid
 * @param N Number of rows
 * @param M Number of columns
*/



void	solve(vector<string> &grid, int N, int M) {
    pair<int, int> start = {0, 0};
    pair<int, int> end = {N - 1, M - 1};
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};

    vector<vector<int>> mat(N, vector<int>(M, 1e9));
    multimap<double, pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j += 2) {
            if (grid[i][j] == 'M' && grid[i][j + 1] == 'M') {
                start = {i, j+1};
            }
            if (grid[i][j] == 'G' && grid[i][j + 1] == 'G') {
                end = {i, j+1};
            }
        }
        cout << "\n";
    }

    q[0] = start;
    mat[start.first][start.second] = 0;
    
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();

        for (int id = 0; id < 4; id++) {
            int x = p.first + dx[id];
            int y = p.second + 2*dy[id];
            if (x < 0 || x >= N || y < 0 || y >= M) {
                continue;
            }
            int val = 4 * (grid[x][y-1] - '0');
            if (mat[x][y] > mat[p.first][p.second] + val) {
                mat[x][y] = mat[p.first][p.second] + val;
                q.insert(make_pair(mat[x][y], {x, y}));
            }
        }
    }
    showmat(mat);

}

