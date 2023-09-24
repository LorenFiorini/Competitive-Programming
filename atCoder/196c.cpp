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


ll help (ll n) {
	ll answer = 0;
	if (n < 99 && n >= 11) {
		REP (i, 1, 10) {
			ll tmp = i * 10 + i;
			if (tmp <= n) answer++;
			else break;
		}
	} else if (n < 9999 && n >= 1010) {
		REP (i, 10, 100) {
			ll tmp = i * 100 + i;
			if (tmp <= n) answer++;
			else break;
		}
	} else if (n < 999999 && n >= 100100) {
		REP (i, 1e2, 1e3) {
			ll tmp = i * 1e3 + i;
			if (tmp <= n) answer++;
			else break;
		}
	} else if (n < 99999999 && n >= 10001000) {
		REP (i, 1e3, 1e4) {
			ll tmp = i * 1e4 + i;
			if (tmp <= n) answer++;
			else break;
		}
	} else if (n < 9999999999 && n >= 1000010000) {
		REP (i, 1e4, 1e5) {
			ll tmp = i * 1e5 + i;
			if (tmp <= n) answer++;
			else break;
		}
	} else if (n < 999999999999 && n >= 100000100000) { //9.99 * 10^(11) 
		REP (i, 1e5, 1e6) {
			ll tmp = i * 1e6 + i;
			if (tmp <= n) answer++;
			else break;
		}
	}
	return answer;
}



void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	
	if (n >= 99) ans += 9; 
	if (n >= 9999) ans += 90;
	if (n >= 999999) ans += 900;
	if (n >= 99999999) ans += 9000;
	if (n >= 9999999999) ans += 90000;
	if (n >= 999999999999) ans += 900000;
	
	ans += help(n);
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}

