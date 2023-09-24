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
	string ans = "NO";
	string s;
	int x,y;
	cin >> x >> y;
	cin >> s;
	int n = s.size();
	int u = 0, d = 0, r = 0, l = 0;
	REP (i, 0, n) {
		if (s[i] == 'U') {
			u++; 
		} else if (s[i] == 'D') {
			d--; 
		} else if (s[i] == 'R') {
			r++; 
		} else if (s[i] == 'L') {
			l--;
		}
	}
	if (x >= 0 && y >= 0) {
		if (r >= x && u >= y) ans = "YES";
	} else if (x <= 0 && y >= 0) {
		if (l <= x && u >= y) ans = "YES";
	} else if (x >= 0 && y <= 0) {
		if (r >= x && d <= y) ans = "YES";
	} else {
		if (l <= x && d <= y) ans = "YES";
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
