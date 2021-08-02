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
	int h, w;
	cin >> h >> w;
	vector<vector<int>> v(h, vector<int> (w, 0));
	REP (i, 0, h) {
		string row;
		cin >> row;
		REP (j, 0, w) {
			if (row[j] == '#') {
				v[i][j] = 1;
			}
		}
	}
	REP (i, 1, h) {
		int cnt = 0;
		int cons = 0;
		int cona = 0;
		//int conant = 0;
		REP (j, 1, w) {
			if (v[i][j] && v[i-1][j] == 0) {
				cons = 1;
			} else {
				if (cons) {
					cnt += 1;
					cons = 0;
				}
			}
			if (v[i-1][j] && v[i][j] == 0) {
				cona = 1;
			} else {
				if (cona) {
					cnt += 1;
					cona = 0;
				}
			}
		}
		ans += cnt;
	}
	REP (i, 1, h) {
		int cnt = 0;
		int cons = 0;
		int cona = 0;
		//int conant = 0;
		REP (j, 1, w) {
			if (v[j][i] && v[j][i-1] == 0) {
				cons = 1;
			} else {
				if (cons) {
					cnt += 1;
					cons = 0;
				}
			}
			if (v[j][i-1] && v[j][i] == 0) {
				cona = 1;
			} else {
				if (cona) {
					cnt += 1;
					cona = 0;
				}
			}
		}
		ans += cnt;
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


