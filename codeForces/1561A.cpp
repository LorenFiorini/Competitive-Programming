#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v, int n) {
	for (int i = 0; i < n; i++) {
		if (i + 1 != v[i]) return false;
	}
	return true;
}

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	while (not check(v, n)) {
		if (ans % 2) {
			for (int i = 1; i < n-1; i += 2) 
				if (v[i] > v[i+1])
					swap(v[i], v[i+1]);	
		} else {
			for (int i = 0; i < n-1; i += 2) 
				if (v[i] > v[i+1])
					swap(v[i], v[i+1]);			
		}
		ans++;
	}
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}

// Lorenzo Fiorini

