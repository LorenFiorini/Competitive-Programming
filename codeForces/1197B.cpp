#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	bool up = true;
	for (int i = 1; i < n; i++) {
		if (v[i-1] == v[i]) {
			if (v[i]==1) continue;
			else {
				cout << "NO\n";
				return 0;
			}
		} else if (up and v[i-1] > v[i]) {
			up = false;
		} else if (not up and v[i-1] < v[i]) {
			cout << "NO\n";
			return 0;
		}
	}	
	
	cout << "YES\n";
}


