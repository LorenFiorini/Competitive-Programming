#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()

int h;
int w;

ll dfs(vector<vector<bool>> &used, int r, int c, int a, int b) {
	if (a < 0 || b < 0) return 0;
	if (c == w) {c = 0;	r++;}
	if (r == h) return 1;
	
	if (used[r][c]) return dfs(used, r, c + 1, a, b);
	
	ll res = 0;
	used[r][c] = true;
	res += dfs(used, r, c + 1, a, b - 1);
	if (c + 1 < w && !used[r][c+1]) {
		used[r][c+1] = true;
		res += dfs(used, r, c + 1, a-1, b);
		used[r][c+1] = false;
	}
	
	if (r + 1 < w && !used[r+1][c]) {
		used[r+1][c] = true;
		res += dfs(used, r, c + 1, a-1, b);
		used[r+1][c] = false;
	}
	used[r][c] = false;
	return res;
}

void solve () {
	ll ans;
	int a, b;
	cin >> h >> w >> a >> b;
	vector<vector<bool>> used(h, vector<bool> (w, false));
	
	ans = dfs(used, 0, 0, a, b);
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
