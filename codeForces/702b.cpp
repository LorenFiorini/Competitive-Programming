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
	int ans = 0;
	int n;
	vector<int> c(3, 0);
	cin >> n;
	REP (i, 0, n) {
		int tmp;
		cin >> tmp;
		c[tmp % 3]++;
	}
	int mn = min(min(c[0], c[1]), c[2]);
	int mx = max(min(c[0], c[1]), c[2]);
	int tot = 0;
	REP (i, 0, 3) {
		c[i] -= mn;
		tot += c[i];
	}
	int avg = tot / 3;
	REP (i, 0, 3) {
		if (c[i] == 0) {
			if (c[i-1 >= 0 ? i-1: 2] >= tot / 3) {
				c[i-1 >= 0 ? i-1: 2] -= tot / 3;
				c[i] += tot / 3;
				ans += tot / 3;
			} else {
				c[i] += c[i-1 >= 0 ? i-1: 2];
				ans += c[i-1 >= 0 ? i-1: 2];
				c[i-1 >= 0 ? i-1: 2] = 0;
			}
		} else if (c[i] < avg) {
			if (c[i-1 >= 0 ? i-1: 2] + c[i] >= avg) {
				ans += avg - c[i];
				c[i-1 >= 0 ? i-1: 2] -= (avg - c[i]);
				c[i] = avg;
			}
		}
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

