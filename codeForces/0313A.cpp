#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if (n > 0) {
		cout << n << "\n";
	} else {
		int last = n % 10;
		int ans = max(n / 10, (n / 100) * 10 + last);
		cout << ans << "\n";
	}
	
	
	return 0;
}

// Lorenzo Fiorini
