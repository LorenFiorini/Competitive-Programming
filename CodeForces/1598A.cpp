#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	string b;
	cin >> b;
	
	bool ok = 1;
	for (int i = 0 ;i < n; i++) {
		ok &= !(a[i] == '1' && b[i] == '1');
	}
	
	if (ok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}		
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

