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
	int r, c;
	cin >> r >> c;
	vector<vector<bool>> v(r, vector<bool> (c, false));
	REP (i, 0, r) {
		REP (j, 0, c) {
			int tmp;
			cin >> tmp;
			if (tmp) v[i][j] = true;
		}
	}
	vector<vector< map<int, int> >> L(r, vector<map<int, int>> (c));
	map<int, int> :: iterator it;
	REP (i, 0, r) {
		int st = -1;
		REP (j, 0, c) {
			//START
			if (v[i][j] && st == -1) {
				st = j;
			}
			//END
			if (v[i][j] == 0 && st != -1 ) {
				if (j-st <2) {
					st=-1;
					continue;
				}
				//insert if
				REP (pr, st, j - 1) {
					REP (ul, pr + 1, j) {
						//begin
						int len = ul - pr + 1;
						it = L[i][pr].find(len);
						if (it == L[i][pr].end()) {
							L[i][pr].insert(pair<int,int> (len,1));
						} else {
							it->second++;
						}
						//end
						it = L[i][ul].find(len);
						if (it == L[i][ul].end()) {
							L[i][ul].insert(pair<int,int> (len,1));
						} else {
							it->second++;
						}
					}
				}
				st = -1;
			}
		}
		if (st != -1 && c - st >= 2) {
				REP (pr, st, c - 1) {
					REP (ul, pr + 1, c) {
						//begin
						int len = ul - pr + 1;
						it = L[i][pr].find(len);
						if (it == L[i][pr].end()) {
							L[i][pr].insert(pair<int,int> (len,1));
						} else {
							it->second++;
						}
						//end
						it = L[i][ul].find(len);
						if (it == L[i][ul].end()) {
							L[i][ul].insert(pair<int,int> (len,1));
						} else {
							it->second++;
						}
					}
				}
		}
	}
	/*
	REP (i, 0, r) {
		REP (j, 0, c) {
			for (it = L[i][j].begin(); it != L[i][j].end(); it++) {
				cout << it->first << "  " << it->second << "\n";
			}
		}
	}*/
	
	REP (col, 0, c) {
		int st = -1;
		REP (row, 0, r) {
						//START
			if (v[row][col] && st == -1) {
				st = row;
			}
			//END
			if (v[row][col] == 0 && st != -1 ) {
				if (row-st <2) {
					st=-1;
					continue;
				}
				//insert if
				REP (pr, st, row - 1) {
					REP (ul, pr + 1, row) {
						//begin
						int len = 2 * (ul - pr + 1);
						it = L[pr][col].find(len);
						if (it != L[pr][col].end()) {
							ans += it->second;
						}
						//end
						it = L[ul][col].find(len);
						if (it != L[ul][col].end()) {
							ans += it->second;							
						}
						 //begin
						len = (ul - pr + 1);
						if (len%2==0) len/=2;
						else continue;
						it = L[pr][col].find(len);
						if (it != L[pr][col].end()) {
							ans += it->second;
						}
						//end
						it = L[ul][col].find(len);
						if (it != L[ul][col].end()) {
							ans += it->second;							
						} 
					}
				}
				st = -1;
			}
		}
		if (st != -1 && r - st >= 2) {
				REP (pr, st, r - 1) {
					REP (ul, pr + 1, r) {
						//begin
						int len = 2 * (ul - pr + 1);
						it = L[pr][col].find(len);
						if (it != L[pr][col].end()) {
							ans += it->second;
						}
						//end
						it = L[ul][col].find(len);
						if (it != L[ul][col].end()) {
							ans += it->second;							
						} 
						//begin
						len = (ul - pr + 1);
						if (len%2==0) len/=2;
						else continue;
						it = L[pr][col].find(len);
						if (it != L[pr][col].end()) {
							ans += it->second;
						}
						//end
						it = L[ul][col].find(len);
						if (it != L[ul][col].end()) {
							ans += it->second;							
						} 
					}
				}
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


