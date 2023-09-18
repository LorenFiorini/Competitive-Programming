#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s, n;
	cin >> s >> n;
	string ans = "YES";
	
	vector<vector<int>> v(n, vector<int> (2, 0));
	for (int i = 0; i < n; i++) 
		cin >> v[i][0] >> v[i][1];
	
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (v[i][0] < s) {
			s += v[i][1];
		} else {
			ans = "NO";
			break;
		}
	} 
	
	
	cout << ans << "\n";
	
	return 0;
}

// Lorenzo Fiorini


