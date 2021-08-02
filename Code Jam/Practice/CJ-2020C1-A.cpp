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
	int X, Y;
	cin >> X >> Y;
	string M;
	cin >> M; // N, S, E or 'W' char
	int n = M.size();
	int dist = abs(X) + abs(Y);
	REP (i, 0, n) {
		if (M[i] == 'N') {
			Y++;
		} else if (M[i] == 'S') {
			Y--;
		} else if (M[i] == 'E') {
			X++;
		} else if (M[i] == 'W') {
			X--;
		} 
		dist = abs(X) + abs(Y);
		if (dist <= i+1) {
			cout << i + 1 << "\n";
			return;
		}
		
	}
	
	cout << "IMPOSSIBLE\n";
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

