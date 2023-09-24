#include <bits/stdc++.h>
using namespace std;

void solve () {
	int ans;
	int n, s;
	cin >> n >> s;
	
	int mp = (n-1) / 2;
	
	ans = s / (n-mp); 
	
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
