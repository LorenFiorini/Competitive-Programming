#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ans = "YES";
	int n, m;
	cin >> n >> m;
	
	vector<string> v(n);
	for (string &s : v) {
		cin >> s;
		
		bool ok = 1;
		for (int j = 1; j < m ; j++) {
			ok &= s[j] == s[j-1];
		}
		if (not ok) ans = "NO";
	}
	
	bool ok = 1;
	for (int i = 1; i < n; i++) ok &= v[i-1][0] != v[i][0];
	
	
	if (not ok) ans = "NO";
	
	cout << ans << endl;
	
	return 0;
}

// Lorenzo Fiorini
