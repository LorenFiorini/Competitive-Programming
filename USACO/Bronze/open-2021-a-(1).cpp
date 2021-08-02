#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
	int ans = 0;
	int n, l;
	cin >> n >> l;
	vector<int> v(n);
	bool sit[n];
	int sumcit;
	REP (i,0,n) {
		cin >> v[i];
		sit = false;
	}
	RREP (i, n, 0) {
		int h = v[i];
		if (h <= n - i) {
			if 
			ans = max(ans, h);
		}
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

