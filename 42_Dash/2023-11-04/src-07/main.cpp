
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;
typedef int ll;
vector<vector<ll>> cost;
vector<vector<ll>> eur;
vector<string> keys;
pair<ll, ll> start, finish;
ll best_cost = 1e9;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
string dir[] = {"L", "U", "R", "D"};

float combi[21][3] = { {5, 5, 0}, {5, 0, 5}, {0, 5, 5},
                        {4, 3, 3}, {3, 4, 3}, {3, 3, 4},
                        {5, 4, 1}, {5, 1, 4}, {4, 5, 1},
                        {5, 3, 2}, {5, 2, 3}, {3, 5, 2},
                        {3, 2, 5}, {2, 5, 3}, {2, 3, 5},
                        {4, 4, 2}, {4, 2, 4}, {2, 4, 4},
                        {4, 1, 5}, {1, 5, 4}, {1, 4, 5}};
                    
vector<string> combinations = {"550", "505", "055",
    "433", "343", "334",
    "541", "514", "451",
    "532", "523", "352",
    "325", "253", "235",
    "442", "424", "244",
    "415", "154", "541"};

void read_file(char *file_path, vector<string> &grid, int &N) {
	ifstream file(file_path);
	if (!file.is_open()) {
		std::cout << "Error: File not found" << std::endl;
		exit(1);
	}
	string line;
	while (getline(file, line)) {
		grid.push_back(line);
		N++;
	}
	file.close();
}

vector<vector<ll>> get_matrix(vector<string> &grid, int N, int M) {
	cost.resize(N, vector<ll>(M / 2, 0));
	keys.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j += 2) {
            int val = grid[i][j] - '0';
            if (grid[i][j] == 'M') {
                start = {i, j / 2};
                val = 0;
            }
            if (grid[i][j] == 'G') {
                finish = {i, j / 2};
                val = 0;
            }
            cost[i][j / 2] = val;
            keys[i].push_back(grid[i][j - 1]);
        }
    }
    return cost;
}

void get_euristic_mat(int N, int M) {
	eur.resize(N, vector<ll>(M / 2, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M / 2; j++) {
			eur[i][j] = 2 * (abs(i - finish.first) + abs(j - finish.second));
		}
	}
}

ll bfs(int N, int M, map<char, int> &key_map) {
    ll ans = 1e9;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    vector<vector<string>> path(N, vector<string>(M, ""));
    vector<vector<ll>> mat(N, vector<ll>(M, 1e9));
    q.push({0, start.first, start.second});
    mat[start.first][start.second] = 0;

    while (!q.empty()) {
        vector<ll> p = q.top();
        q.pop();

        if (p[0] > best_cost) {
            break;
        }
        if (p[1] == finish.first && p[2] == finish.second) {
            ans = min(ans, p[0]);
            break;
        }

        for (int id = 0; id < 4; id++) {
            int x = p[1] + dx[id];
            int y = p[2] + dy[id];
            if (x < 0 || x >= N || y < 0 || y >= M) {
                continue;
            }
            ll val = mat[p[1]][p[2]] + eur[x][y] + cost[x][y] * (7 + !key_map[keys[x][y]] - key_map[keys[x][y]]);
            if (mat[x][y] > val) {
                // mat[x][y] = val - eur[x][y];
                mat[x][y] = val;
                path[x][y] = path[p[1]][p[2]] + dir[id];
                q.push({val, x, y});
            }
        }
    }
    return ans;
}

string get_path(int N, int M, map<char, int> &key_map) {
    M = cost[0].size();
    string ans_path = "";
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    vector<vector<ll>> mat(N, vector<ll>(M, 1e9));
    vector<vector<string>> path(N, vector<string>(M, ""));

    q.push({0, start.first, start.second});
    mat[start.first][start.second] = 0;

    while (!q.empty()) {
        vector<ll> p = q.top();
        q.pop();

        if (p[0] > best_cost) {
            break;
        }
        if (p[1] == finish.first && p[2] == finish.second) {
            ans_path = path[p[1]][p[2]];
            break;
        }

        for (int id = 0; id < 4; id++) {
            int x = p[1] + dx[id];
            int y = p[2] + dy[id];
            if (x < 0 || x >= N || y < 0 || y >= M) {
                continue;
            }
            ll val = mat[p[1]][p[2]] + eur[x][y] + cost[x][y] * (7 + !key_map[keys[x][y]] - key_map[keys[x][y]]);
            if (mat[x][y] > val) {
                mat[x][y] = val;
                path[x][y] = path[p[1]][p[2]] + dir[id];
                q.push({val, x, y});
            }
        }
    }
    return ans_path;
}

void	solve(int N, int M) {
    ll mn = 1e9;
    best_cost = 1e9;
    M = M / 2;
    map<char, int> key_map;
    key_map['G'] = 0;
    key_map['M'] = 0;
    string path = "";

    for (int i = 0; i < 21; i++) {
        key_map['W'] = combinations[i][0] - '0';
        key_map['A'] = combinations[i][1] - '0';
        key_map['E'] = combinations[i][2] - '0';
        ll val = bfs(N, M, key_map);
        if (val < mn) {
            mn = val;
            path = get_path(N, M, key_map);
            string ans = combinations[i] + path;
            cout  << ans << endl;
        }
    }
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return (1);
	}
	int N = 0;
	vector<string> grid;
	read_file(argv[1], grid, N);
	int M = grid[0].size();
	get_matrix(grid, N, M);
	get_euristic_mat(N, M);
	solve(N, M);
	return (0);
}
