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


void show(vector<bool> v) {
	int n = v.size();
	REP (i, 0, n)  cout << v[i] << " ";
	cout << "\n";
}

void solve () {
	int ans = 0;
	int x, y;
	string s;
	cin >> x >> y >> s;
	int n = s.size();
	vector<bool> v;
	REP (i, 0, n) {
		if (s[i] == 'C') {
			v.push_back(1);
		} else if (s[i] == 'J') {
			v.push_back(0);
		}
	}
	//show(v);
	REP (i, 1, v.size()) {
		if (!v[i-1] && v[i]) {
			// JC
			ans += y;
		} else if (v[i-1] && !v[i]) {
			// CJ
			ans += x;
		}
	}
	
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

