#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	s--;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	
	if (not a[0]) {
		cout << "NO\n";
		return 0;
	}
	
	if (a[s]) {
		cout << "YES\n";
	} else if (b[s]){
		for (int i = s+1; i < n; i++) {
			if (a[i] && b[i]) {
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
	} else {
		cout << "NO\n";
	}	
}

