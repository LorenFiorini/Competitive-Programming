#include <bits/stdc++.h>
using namespace std;
// Global
int n, m;

int smallest_up_to_k(vector<vector<vector<int>>> &v, int r, int c, int k) {
	int ans = 0;
	for (int i = 0; i <= max(k, r); i++) {
		if (0 == ans and v[r][c][i] > 0) ans = v[r][c][i];
		else if (ans > 0 and v[r][c][i] > 0) {
			ans = min(v[r][c][i], ans);
		} 
	}
	return ans;
}

void dfs(vector<vector<vector<int>>> &v, int row, int from, int to, int tiempo, int highest, vector<bool> &vis) {
	//if (0) return;
	vis[to] = true;
	
	if (row != from) highest = max(highest, from);
	
	int toHere = smallest_up_to_k(v, row, to, highest);
	v[row][to][highest] = min((toHere) > 0? toHere : tiempo, tiempo);
	
	
	for (int i = 0; i < n; i++) {
		int time = smallest_up_to_k(v, to, i, max(to, highest));
		if (time != 0 and not vis[i])
			dfs(v, row, to, i, time + tiempo, highest, vis);
	}
}


void solve () {
	cin >> n >> m;
	vector<vector<vector<int>>> v(n, vector<vector<int>> (n, vector<int> (n, 0)));
	
	// INPUT
	for (int i = 0; i < m; i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		for (int k = 0; k < n; k++) {
			v[a][b][k] = c;
		}
	}
	
	// Depth First Search
	for (int from = 0; from < n; from++) {
		for (int to = 0; to < n; to++) {
			vector<bool> vis(n, 0);
			vis[from] = true;
			if (v[from][to][0] != 0) dfs(v, from, from, to, v[from][to][0], 0, vis);
		}
	}
	
	
	// Accumulate answer
	int ans = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans += smallest_up_to_k(v, i, j, k);
			}
		}
	}
	
	cout << '\n';
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << v[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << ans << '\n';
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	
	return 0;
}

// Lorenzo Fiorini
