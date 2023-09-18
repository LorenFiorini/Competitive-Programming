#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; 
	cin >> t; 
	while (t--){
		ll n, a, b;
		cin >> n >> a >> b;
		ll ans = 0;
		if (n & 1) {
			ans = a;
			n--;
		}
		ans += min(a * n, b * (n/2));
		cout << ans << "\n";
	}
	
	return 0;
}

// Lorenzo Fiorini
