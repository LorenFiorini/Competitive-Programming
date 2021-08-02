#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	ll cpy = n;
	ll len = 0;
	while (cpy > 0) {
		cpy /= 10;
		len++;
	}
	switch ((len - 1) / 3) {
		case 0:
			ans = 0;
			break;
			
		case 1: 
		// 1.000 -> 999.999
			ans += (n - 999); // 3
			break;
			
		case 2: 
		// 1.000.000 -> 999.999.999
			ans += 9e3 + 9e4 + 9e5; // 999000
			ans += 2 * (n - 999999); // 6
			break;
			
		case 3:
		// 1.000.000.000 -> 999.999.999.999
			ans += 9e3 + 9e4 + 9e5;
			ans += 2 * (9e6 + 9e7 + 9e8);
			ans += 3 * (n - 999999999); // 9
			break;
			
		case 4: 
		// 1.000.000.000.000 -> 999.999.999.999.999
			ans += 9e3 + 9e4 + 9e5;
			ans += 2 * (9e6 + 9e7 + 9e8);
			ans += 3 * (9e11 + 9e10 + 9e9);
			ans += 4 * (n - 999999999999);
			break;
			
		case 5:
			ans += 9e3 + 9e4 + 9e5;
			ans += 2 * (9e6 + 9e7 + 9e8);
			ans += 3 * (9e11 + 9e10 + 9e9);
			ans += 4 * (9e12 + 9e13 + 9e14);
			ans += 5;
			break;
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name


