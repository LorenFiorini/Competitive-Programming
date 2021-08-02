#include <bits/stdc++.h>
using namespace std;
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define REP(i, a, b) por(i, a, b, 1)
#define notin(c, x) ((c).find(x) == (c).end())
#define mk make_pair
typedef pair<int, int> pii;

int n, m;
set<pair<int, int>> fr;
map<pair<int, int>, int> mp;
set<pair<int, int>> :: iterator sit;
map<pair<int, int>, int> :: iterator mit;

void bfs(int r, int c, vector<vector<int>> &mat) {
	pair<int, int> cowUP = mk(r - 1, c);
	pair<int, int> cowL = mk(r, c - 1);
	pair<int, int> cowR = mk(r, c + 1);
	pair<int, int> cowD = mk(r + 1, c);
	bool oka = 0, okd = 0, okb = 0, okc = 0;
	// 3 _______________________________________________________________
	if (!notin(mp, cowUP)) {
		// 1 2
		if (!notin(mp, cowL)) 
		{
			int row = r - 1;
			int col = c - 1;
			pair<int, int> pf = mk(mp.at(cowUP), mp.at(cowL));
			pair<int, int> pfr = mk(mp.at(cowL), mp.at(cowUP));
			if (mat[row][col]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[row][col] = 0;
				}
			} else if (mat[r][c]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r][c] = 0;
				}
			}
		}
		// 1 3
		if (!notin(mp, cowR)) 
		{
			int row = r - 1;
			int col = c + 1;
			pair<int, int> pf = mk(mp.at(cowUP), mp.at(cowR));
			pair<int, int> pfr = mk(mp.at(cowR), mp.at(cowUP));
			if (mat[row][col]) {
				if (notin(fr, pf) && notin(fr, pfr)){
					fr.insert(pf);
					mat[row][col] = 0;
				}
			} else if (mat[r][c]) {
				if (notin(fr, pf) && notin(fr, pfr)){
					fr.insert(pf);
					mat[r][c] = 0;
				}
			}
		}
		// 1 4
		if (!notin(mp, cowD)) 
		{
			pair<int, int> pf = mk(mp.at(cowUP), mp.at(cowD));
			pair<int, int> pfr = mk(mp.at(cowD), mp.at(cowUP));
			if (mat[r][c]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r][c] = 0;
				}
			}
		}
	}
	// 2 _______________________________________________________________
	if (!notin(mp, cowL)) 
	{
		// 2 3
		if (!notin(mp, cowR)) 
		{
			pair<int, int> pf = mk(mp.at(cowL), mp.at(cowR));
			pair<int, int> pfr = mk(mp.at(cowR), mp.at(cowL));
			if (mat[r][c]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r][c] = 0;
				}
			}
		}
		// 2 4
		if (!notin(mp, cowD)) 
		{
			if (mat[r][c]) oka = true;
			if (mat[r+1][c-1]) okd = true;
		}
	}
	// 3 _______________________________________________________________
	if (!notin(mp, cowR)) 
	{
		if (!notin(mp, cowD)) 
		{
			if (mat[r][c]) okb = true;
			if (mat[r+1][c-1]) okc = true;
		}
	}
	if (oka && !okb) {
		pair<int, int> pf = mk(mp.at(cowD), mp.at(cowL));
		pair<int, int> pfr = mk(mp.at(cowL), mp.at(cowD));
		if (mat[r][c]) {
			if (notin(fr, pf) && notin(fr, pfr)) {
				fr.insert(pf);
				mat[r][c] = 0;
			}
		}
		return;
	} else if (!oka && okb) {
		pair<int, int> pf = mk(mp.at(cowD), mp.at(cowR));
		pair<int, int> pfr = mk(mp.at(cowR), mp.at(cowD));
		if (mat[r][c]) {
			if (notin(fr, pf) && notin(fr, pfr)) {
				fr.insert(pf);
				mat[r][c] = 0;
			}
		}
		return;
	}
	if (!oka && !okb) {
		if (okd) {
			pair<int, int> pf = mk(mp.at(cowD), mp.at(cowL));
			pair<int, int> pfr = mk(mp.at(cowL), mp.at(cowD));
			if (mat[r + 1][c - 1]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r + 1][c - 1] = 0;
				}
			}
		}
		if (okc) {
			pair<int, int> pf = mk(mp.at(cowD), mp.at(cowR));
			pair<int, int> pfr = mk(mp.at(cowR), mp.at(cowD));
			if (mat[r + 1][c + 1]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r + 1][c + 1] = 0;
				}
			}
		}
		return;
	}
	if (oka && okb) {
		if (okd && !okc) {
			pair<int, int> pf = mk(mp.at(cowD), mp.at(cowR));
			pair<int, int> pfr = mk(mp.at(cowR), mp.at(cowD));
			if (mat[r][c]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r][c] = 0;
				}
			}
			pf = mk(mp.at(cowD), mp.at(cowL));
			pfr = mk(mp.at(cowL), mp.at(cowD));
			if (mat[r + 1][c - 1]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r + 1][c - 1] = 0;
				}
			}
			return;			
		}
		if (!okd && okc) {
			pair<int, int> pf = mk(mp.at(cowD), mp.at(cowL));
			pair<int, int> pfr = mk(mp.at(cowL), mp.at(cowD));
			if (mat[r][c]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r][c] = 0;
				}
			}
			pf = mk(mp.at(cowD), mp.at(cowR));
			pfr = mk(mp.at(cowR), mp.at(cowD));
			if (mat[r + 1][c + 1]) {
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
					mat[r + 1][c + 1] = 0;
				}
			}
			return;			
		} else {
			bfs(r + 1, c - 1, mat);
			bfs(r + 1, c + 1, mat);
			int ava = 0;
			if (mat[r][c]) ava++;
			if (mat[r+1][c-1]) ava++;
			if (mat[r+1][c+1]) ava++;
			if (ava >= 2) {
				pair<int, int> pf = mk(mp.at(cowD), mp.at(cowL));
				pair<int, int> pfr = mk(mp.at(cowL), mp.at(cowD));
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
				}
				pf = mk(mp.at(cowD), mp.at(cowR));
				pfr = mk(mp.at(cowR), mp.at(cowD));
				if (notin(fr, pf) && notin(fr, pfr)) {
					fr.insert(pf);
				}
			}
		}
	}
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<int>> mat(n, vector<int> (m, 0));
	int num = 1;
	REP (i, 0, n) {
		string line; cin >> line;
		REP (j, 0, m) {
			if (line[j] == 'G') mat[i][j] = 1;
			if (line[j] == 'C') {
				mp[mk(i, j)] = num;
				num++;
			}
		}
	}
	REP (i, 0, n) REP (j, 0, m)
			if (mat[i][j]) bfs(i, j, mat);
	cout << fr.size();
	return 0;
}




