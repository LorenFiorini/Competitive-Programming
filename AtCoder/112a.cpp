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
	ll l, r;
	cin >> l >> r;
	/*for (ll i = l ; (2 * i) <= r ; i++) {
		if (i + i <= r) ans++; 
		ll tmp = 2 * (r - 2 * i);
		if (tmp > 0) ans += tmp;
		cout << tmp << "\n";
	}*/
	ll tmp = 2 * (r - 2 * l);
	/*
	for (ll i = tmp ; i >= 0 ; i -= 4) {
		ans++;
		ans += i;
	} */
	ll sum = 0; 
	if (tmp >= 0) {
		sum= (tmp / 4 + 1) * (tmp % 4 + tmp) / 2;
		ans = sum + (tmp / 4 + 1);
		//if (tmp % 4 > 0) ans++;
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
//$ sudo g++ -o name name.cpp
//$ ./name

