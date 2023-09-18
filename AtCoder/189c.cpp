#include <bits/stdc++.h>
using namespace std;
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
	cin >> n;
	vector<int> v(n + 1);
	REP (i, 1, n + 1) {
		cin >> v[i];
	}
	REP (i, 1, n + 1) {
		int mn = 1000000;
		REP (j, i, n + 1) {
			mn = min(mn, v[j]);
			ans = max(ans, mn * (j - i + 1));
		}
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int t; cin >> t;
	//while (t--) 
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name
