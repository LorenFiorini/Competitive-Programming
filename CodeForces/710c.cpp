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
	string a, b;
	cin >> a;
	cin >> b;
	int na = a.size();
	int nb = b.size();
	
	REP (len, 1, min(na + 1, nb+1)) {
		// lenght of substring
		REP (i, 0, na) {
			if (i + len > na) break;
			string sub = a.substr(i, len);
			
			if (b.find(sub) < nb) {
				ans = len;
				break;
			}
			
		}
		if (ans != len) break;
	}
	//cout << ans << "\n\n";
	int answer = na + nb - 2 * ans;
	
	cout << answer << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

