#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ans = "YES";
	
	vector<string> v(3);
	for (string &i : v) cin >> i;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v[i][j] != v[2-i][2-j]) ans = "NO";
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

// Lorenzo Fiorini
