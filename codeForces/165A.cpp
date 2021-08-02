#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &v, int x, int y) {
	if (x == 0 || y == 0 || x == 2000 || y == 2000) return false;
	int u = -1, d = 1;
	while (u+x >= -1) {
		if (u+x < 0) return false;
		if (v[x+u][y]) break;
		u--;
	}
	while (d+x <= 2001) {
		if (d+x > 2000) return false;
		if (v[x+d][y]) break;
		d++;
	}
	//cout << x -1000<< " " << y-1000 << "\n";
	return true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	vector<vector<int>> v(2001, vector<int> (2001, 0));
	for (int i = 0; i < n; i++) 
	{
		int r, c;
		cin >> r >> c;
		r += 1000; c += 1000; 
		v[r][c] = 1;
	}
	
	for (int i = 0; i <= 2000; i++) {
		vector<pair<int,int>> tmp;
		for (int j = 0; j <= 2000; j++) {
			if (v[i][j]) {
				tmp.push_back({i, j});
			}
		}
		int m = tmp.size();
		if (m >= 3) {
			for (int k = 1; k < m-1; k++) {
				ans += check(v, tmp[k].first, tmp[k].second);
			}
		}
	}
		
	cout << ans << endl;
}
/*
9
-565 -752
-184 723
-184 -752
-184 1
950 723
-565 723
950 -752
950 1
-565 1

*/
