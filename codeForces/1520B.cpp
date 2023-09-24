#include <bits/stdc++.h>
using namespace std;

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	int dig = 0;
	int tmp = n;
	while (tmp > 0) {
		tmp /= 10;
		dig++;
	}
	ans += (dig - 1) * 9;
	
	for (int i = 1; i <= 9; i++) {
		int num = i;
		int cnt = 1;
		while (cnt++ < dig) {
			num *= 10;
			num += i;
		}
		if (n >= num) ans++;
		else break;
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

