#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v(26, 0);
	
	for (int i = 0; i < n; i++) {
		v[s[i] - 'A']++;
	}
	int ans = n;
	
	for (int i = 0; i < k; i++) ans = min(ans, v[i]);
	
	cout << ans * k << "\n";
}
