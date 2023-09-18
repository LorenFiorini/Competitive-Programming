#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	
	ll d = n % m;
	ll ans = min(b * d, a * (m-d));
	
	cout << ans << endl;
	return 0;
}

// Lorenzo Fiorini

