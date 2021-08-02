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
	int n, q, k;
	cin >> n >> q >> k;
	vector<int> v(n);
	REP (i, 0, n) cin >> v[i];
	REP (i, 0, q) {
		int ans = 0;
		int l, r;
		cin >> l >> r;
		l--; r--;
		//ans += 2 * (r - l);
		//ans += 2 * (v[r] - v[l] - 1);
		ans = max(v[n-1] - v[l] + 1, v[r] - v[0] - 1);
		cout << ans << "\n";
		
	}
	
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


