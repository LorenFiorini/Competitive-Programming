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
	// LONG LONG (check numeric limits dummy)
	ll ans = 0;
	int r, c;
	cin >> r >> c;
	vector< vector<int> > v(r, vector<int> (c));
	vector< vector<int> > h(r, vector<int> (c));
	//priority_queue< pair<int, pair<int, int>>> next;
	
	
	REP (i,0,r) REP(j,0,c) {
		cin >> v[i][j];
		h[i][j] = v[i][j];
		//next.push({v[i][j], { i, j }});
	}
	REP (i, 0, r) REP (j, 0, c) {
		int height = h[i][j];
		int cnt = 1;
		while (height-- > 0) {
			if (j + cnt < c) h[i][j+cnt] = max(h[i][j+cnt], height);
			if (j - cnt >= 0) h[i][j-cnt] = max(h[i][j-cnt], height);
			if (cnt++ > c) break;
		}
	}
	REP (j, 0, c) REP (i, 0, r) {
		int height = h[i][j];
		int cnt = 1;
		while (height-- > 0) {
			if (i + cnt < r) h[i + cnt][j] = max(h[i+cnt][j], height);
			if (i - cnt >= 0) h[i - cnt][j] = max(h[i-cnt][j], height);
			if (cnt++ > r) break;
		}
	}
	REP (i, 0, r) {
		//cout << "\n";
		REP (j, 0, c) {
			ans += ((ll)h[i][j] - (ll)v[i][j]);
			//cout << h[i][j] << " ";
		}
	} 
	//cout << "\n";
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int c = 1;
	while (c <= t) {
		cout << "Case #" << c << ": ";
		solve();
		c++;
	}
	
	return 0;
}


