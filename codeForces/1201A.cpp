#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	
	int ans = 0;
	for (int j = 0 ; j < m; j++) {
		map<char, int> mp;
		for (int i = 0; i < n; i++) {
			mp[v[i][j]]++;
		}
		int mx = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			mx = max(mx, it->second);
		}
		ans += a[j] * mx;
	}
	cout << ans << endl;
}


