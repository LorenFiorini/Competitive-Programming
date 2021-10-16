#include <bits/stdc++.h>
using namespace std;

void solve () {
	string a, b, c;
	cin >> a >> b >> c;
	map<char, int> mp;
	for (char ch : a) mp[ch]++;
	for (char ch : b) mp[ch]++;
	
	for (char ch : c) mp[ch]--;
	
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second != 0) {
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
	return;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini




