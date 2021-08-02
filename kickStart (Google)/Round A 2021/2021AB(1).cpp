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
	vector< map<int, map<int,int> > > mapas;
	map<int, int> :: iterator it;
	map<int, map<int, int> > :: iterator itt;
	REP (i, 0, r) {
		map<int, map<int,int> > pos;
		int st = -1;
		REP (j, 0, c) {
			//START
			if (v[i][j] && st == -1) {
				st = j;
			}
			//END
			if (v[i][j]==0 && st != -1) {
				int len = j - st;
				if (j - st < 2){
					st=-1;
					continue;
				}
				//QUE ES ESTO (int -> position  pair <len , times>)
				//map<int, map<int,int> > pos;
				REP (pr, st, j - 1) {
					REP (ul, pr + 1, j) {
						int sz = ul - pr + 1;
						itt = pos.find(pr);
						if (itt != pos.end()) {
							//ENCUENTRO POSITION
							it = itt->second.find(sz);
							if (it == itt->second.end()) {
								// NO ENCUNETRO LEN
								itt->second.insert(pair<int, int> (sz, 1));
							} else {
								it->second++;
							}
						} else {
							//NO ENCUNETRO POSITION
							pos.insert(pair<int, map<int, int> (pr, pair<int,int> (sz, 1)));
						}
						itt = pos.find(ul);
						if (itt != pos.end()) {
							it = itt->second.find(sz);
							if (it == itt->second.end()) {
								itt->second.insert(pair<int, int> (sz, 1));
							} else {
								it->second++;
							}
						} else {
							pos.insert(pair<int, map<int, int> (pr, pair<int,int> (sz, 1)));
						}
					}
				}
			}
			
		}
		//insert if end line
		if (st != -1 && c - st >= 2) {
				REP (pr, st, c - 1) {
					REP (ul, pr + 1, c) {
						int sz = ul - pr + 1;
						itt = pos.find(pr);
						if (itt != pos.end()) {
							//ENCUENTRO POSITION
							it = itt->second.find(sz);
							if (it == itt->second.end()) {
								// NO ENCUNETRO LEN
								itt->second.insert(pair<int, int> (sz, 1));
							} else {
								it->second++;
							}
						} else {
							//NO ENCUNETRO POSITION
							pos.insert(pair<int, map<int, int> (pr, pair<int,int> (sz, 1)));
						}
						itt = pos.find(ul);
						if (itt != pos.end()) {
							it = itt->second.find(sz);
							if (it == itt->second.end()) {
								itt->second.insert(pair<int, int> (sz, 1));
							} else {
								it->second++;
							}
						} else {
							pos.insert(pair<int, map<int, int> (pr, pair<int,int> (sz, 1)));
						}
					}
				}
		}
		
		mapas.push_back(pos);
	}
	
	REP (i,0,r) {
		cout << "\n";
		for (itt = mapas[i].begin(); itt != mapas[i].end(); itt++){
			for (it = iit->second.begin(); it != itt->second.end(); it++)
			cout << it->first << "  " << it->second << "\n";
		}
	}
	/*
	REP (col, 0, c) {
		int st = -1;
		REP (i, 0, r) {
			if (v[i][col] && st == -1) {
				st = i;
			}
			if (v[i][col] == 0 && st != -1) {
				int len = i - st;
				if (len < 2) {
					st=-1;
					continue;
				}
				it = mapas[st].find(col);
				if (it != mapas[st].end()) {
					if (it->second == 2 * len || it->second * 2 == len){
						ans++;
					}
				} 
				it = mapas[i - 1].find(col);
				if (it != mapas[i - 1].end()) {
					if (it->second == 2 * len || it->second * 2 == len){
						ans++;
					}
				}
				st = -1;
			}
			
		}
		if (st != -1 && r-st >= 2) {
				int len = r - st;
				it = mapas[st].find(col);
				if (it != mapas[st].end()) {
					if (it->second == 2 * len || it->second * 2 == len){
						ans++;
					}
				} 
				it = mapas[r - 1].find(col);
				if (it != mapas[r - 1].end()) {
					if (it->second == 2 * len || it->second * 2 == len){
						ans++;
					}
				}
		}
		cout << ans <<"\n";
	}
	
	cout << ans << "\n";*/
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

