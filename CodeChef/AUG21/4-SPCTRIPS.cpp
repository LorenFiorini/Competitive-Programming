#include <bits/stdc++.h>
using namespace std;

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++){
			int c = a % b;
			if (c != 0 && b%c == 0) ans++;
		}
	}
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin >> t; 
	while (t--)
		solve();
	
	return 0;
}

// Lorenzo Fiorini
