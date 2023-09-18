#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> mp;
	for (char c : s) {
		mp[c]++;
	}
	int ans = 0;
	ans += min(mp['U'], mp['D']) * 2;
	ans += min(mp['L'], mp['R']) * 2;
	
	cout << ans << endl;	
}

