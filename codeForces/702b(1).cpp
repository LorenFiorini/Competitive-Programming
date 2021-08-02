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
	int tot = 0;
	REP (i, 0, 3) {
		tot += c[i];
	}
	int avg = tot / 3;
	bool ok = false;
	while (!ok) {
		ok = true;
		REP (i, 0, 3) {
			if (c[i] > avg) {
				int dif = c[i] - avg;
				c[(i+1) % 3] += dif;
				ans += dif;
				c[i] -= dif;
				ok = false;
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

