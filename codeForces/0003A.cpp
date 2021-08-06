#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int a[2] = {s[0] - 'a', s[1] - '0'};
	int b[2] = {t[0] - 'a', t[1] - '0'};
	
	vector<string> ans;
	while (a[0] != b[0] || a[1] != b[1]) {
		string move = "";
		if (a[0] < b[0]) {
			move.push_back('R');
			a[0]++;
		} else if (a[0] > b[0]) {
			move.push_back('L');
			a[0]--;
		}
		
		if (a[1] < b[1]) {
			move.push_back('U');
			a[1]++;
		} else if (a[1] > b[1]) {
			move.push_back('D');
			a[1]--;
		}
		
		ans.push_back(move);
	}
	
	cout << (int) ans.size() << "\n";
	for (string str : ans) cout << str << "\n";
}

