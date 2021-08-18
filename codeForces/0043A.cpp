#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	
	map<string, int> mp;
	while (n--) {
		string s;
		cin >> s;
		mp[s]++;
	}
	
	int mx = 0;
	string ans;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second > mx) {
			mx = it->second;
			ans = it ->first;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

// Lorenzo Fiorini

