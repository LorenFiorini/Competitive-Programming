
/**function BIBF-SEARCH(problemF , fF , problemB, fB) returns a solution node, or failure
nodeF ←NODE(problemF .INITIAL) // Node for a start state
nodeB←NODE(problemB.INITIAL) // Node for a goal state
frontierF ←a priority queue ordered by fF , with nodeF as an element
frontierB←a priority queue ordered by fB, with nodeB as an element
reachedF ←a lookup table, with one key nodeF.STATE and value nodeF
reachedB←a lookup table, with one key nodeB.STATE and value nodeB
solution←failure
while not TERMINATED(solution, frontierF , frontierB) do
if fF (TOP(frontierF )) < fB(TOP(frontierB)) then
solution←PROCEED(F, problemF , frontierF , reachedF, reachedB, solution)
else solution←PROCEED(B, problemB, frontierB, reachedB, reachedF , solution)
return solution
function PROCEED(dir, problem, frontier, reached, reached2, solution) returns a solution
// Expand node on frontier; check against the other frontier in reached2.
// The variable “dir” is the direction: either F for forward or B for backward.
node←POP(frontier)
for each child in EXPAND(problem, node) do
s←child.STATE
if s not in reached or PATH-COST(child) < PATH-COST(reached[s]) then
reached[s]←child
add child to frontier
if s is in reached2 then
solution2←JOIN-NODES(dir, child, reached2[s]))
if PATH-COST(solution2) < PATH-COST(solution) then
solution←solution2
return solution
*/


#include "marvin_404_not_found.hpp"


/** @brief Bidirectional best-first search
 *
 * @param mat Matrix to show
*/
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
string dir[] = {"L", "U", "R", "D"};
typedef long long ll;

vector<vector<ll>> get_cost_matrix(vector<string> &grid, int N, int M, pair<int, int> &start, pair<int, int> &end) {
    vector<vector<ll>> cost(N, vector<ll>(M / 2, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j += 2) {
            int val = grid[i][j] - '0';
            if (grid[i][j] == 'M') {
                start = {i, j / 2};
                val = 0;
            }
            if (grid[i][j] == 'G') {
                end = {i, j / 2};
                val = 0;
            }
            cost[i][j / 2] = val;
        }
    }
    return cost;
}

vector<string> get_keys(vector<string> &grid, int N, int M) {
    vector<string> keys(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j += 2) {
            char val = grid[i][j];
            keys[i].push_back(val);
        }
    }
    return keys;
}

vector<vector<ll>> get_heur_matrix(int N, int M, pair<int, int> end) {
    vector<vector<ll>> heur(N, vector<ll>(M, -1));
    queue<pair<int, int>> q;
    q.push(end);
    heur[end.first][end.second] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int id = 0; id < 4; id++) {
            int r = p.first + dx[id];
            int c = p.second + dy[id];
            if (min(r, c) < 0 || r >= N || c >= M) {
                continue;
            }
            if (heur[r][c] == -1) {
                heur[r][c] = heur[p.first][p.second] + 1;
                q.push({r, c});
            }
        }
    }
    return heur;
}

ll bfs(vector<vector<ll>> &cost, vector<string> &keys, vector<vector<ll>> &heur, int N, int M, pair<int, int> start, pair<int, int> end, map<char, int> &key_map, string &ans_path) {
    (void) heur;

    ll ans = 1e9;
    // {Cost, x, y}
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    vector<vector<ll>> mat(N, vector<ll>(M, 1e9));
    vector<vector<string>> path(N, vector<string>(M, ""));

    q.push({0, start.first, start.second});
    mat[start.first][start.second] = 0;

    while (!q.empty()) {
        vector<ll> p = q.top();
        // showv(p);
        q.pop();

        if (p[1] == end.first && p[2] == end.second) {
            ans_path = path[p[1]][p[2]];
            ans = min(ans, p[0]);
            break;
        }

        for (int id = 0; id < 4; id++) {
            int x = p[1] + dx[id];
            int y = p[2] + dy[id];
            if (x < 0 || x >= N || y < 0 || y >= M) {
                continue;
            }
            int val = mat[p[1]][p[2]] + 2 * heur[x][y] + cost[x][y] * (7 + !key_map[keys[x][y]] - key_map[keys[x][y]]);
            if (mat[x][y] > val) {
                mat[x][y] = val;
                path[x][y] = path[p[1]][p[2]] + dir[id];
                q.push({val, x, y});
            }
        }
    }
    // showmat(mat);
    return ans;
}

float combi[21][3] = { {5, 5, 0}, {5, 0, 5}, {0, 5, 5},
                        {5, 4, 1}, {5, 1, 4}, {4, 5, 1}, {4, 1, 5}, {1, 5, 4}, {1, 4, 5},
                        {5, 3, 2}, {5, 2, 3}, {3, 5, 2}, {3, 2, 5}, {2, 5, 3}, {2, 3, 5},
                        {4, 4, 2}, {4, 2, 4}, {2, 4, 4},
                        {4, 3, 3}, {3, 4, 3}, {3, 3, 4} };

void	solve(vector<string> &grid, int N, int M) {
    pair<int, int> start, end;
    vector<vector<ll>> cost = get_cost_matrix(grid, N, M, start, end);
    vector<string> keys = get_keys(grid, N, M);
    M = M / 2;
    vector<vector<ll>> heur = get_heur_matrix(N, M, end);

    // showmat(cost);
    // cout << "\n";
    // showmat(keys);
    // cout << "\n";
    // showmat(heur);

    map<char, int> key_map;
    ll mn = 1e9;
    string path = "";
    string ans = "";

    for (int i = 0; i < 21; i++) {
        key_map['W'] = combi[i][0];
        key_map['A'] = combi[i][1];
        key_map['E'] = combi[i][2];
        ll val = bfs(cost, keys, heur, N, M, start, end, key_map, path);
        if (val < mn) {
            string s = "";
            s.push_back(key_map['W'] + '0');
            s.push_back(key_map['A'] + '0');
            s.push_back(key_map['E'] + '0');
            mn = val;
            ans = s + path;
        }
    }

    cout << ans << "\n";
}

