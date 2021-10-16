#include <bits/stdc++.h>
using namespace std;

void solve () {
	string s;
	cin >> s;
	
	map<char, int> mp;
	for (char c : s) mp[c]++;
	
	if (mp['A'] + mp['C'] == mp['B']) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
