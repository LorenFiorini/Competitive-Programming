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
	int ans;
	int n, u, v;
	cin >> n >> u >> v;
	ans = min(u, v);
	vector<int> vec(n);
	bool line = 1;
	REP (i, 0, n) {
		cin >> vec[i];
		if (i) {
			if (vec[i] == vec[i-1]) continue;
			//if (vec[i] != vec[i-1]) line = false;
			line = false;
			if (vec[i-1] + 1 != vec[i] && vec[i-1] - 1 != vec[i]) ans = 0;
		}
	}
	if (line) ans += v;
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

