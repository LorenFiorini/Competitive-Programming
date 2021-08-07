#include <bits/stdc++.h>
using namespace std;

void solve () {
	int ans = 2;
	int mx = 0;
	vector<int> v(11);
	for (int i = 0; i < 4 ;i++) {
		int p;
		cin >> p;
		v[p]++;
		mx = max(mx, v[p]);
	}
	
	if (mx == 4) {
		ans = 0;
	} else if (mx == 3) {
		ans = 1;
	} 
	
	cout << ans << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
