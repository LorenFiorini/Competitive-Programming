#include <bits/stdc++.h>
using namespace std;
void dfs (vector<int> &v, int pos, vector<int> &ans) {
	ans.push_back(pos);
	if (pos == 1) return;
	dfs(v, v[pos], ans);	
}
int main () {
	ios::sync_with_stdio(false);cin.tie(0);
	int n;	cin >> n;	vector<int> v(n+1, 1);
	for (int i = 0; i < n-1; i++) cin >> v[i+2];
	vector<int> ans;	dfs(v, n, ans);
	for (int i = ans.size(); i > 0; i--) cout << ans[i-1] << ((i-1)? " " : "\n");
}
