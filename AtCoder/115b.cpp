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
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int> (n));
	REP (i, 0, n) {
		REP (j, 0, n) {
			cin >> v[i][j];
		}
	}
	//MAXIMUM VALUES THEY CON HOLD
	vector<int> row(n, 1e9);
	vector<int> col(n, 1e9);
	REP (i, 0, n) {
		REP (j, 0, n) {
			row[i] = min(row[i], v[i][j]);
			col[j] = min(col[j], v[i][j]);
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
//$ sudo g++ -o name name.cpp
//$ ./name


