#include <bits/stdc++.h>
using namespace std;

#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define mk make_pair
#define notin(c, x) ((c).find(x) == (c).end())

set<pair<int, int>> fff;
set<pair<int, int>> :: iterator sit;
map<pair<int, int>, int> mp;
map<pair<int, int>, int> :: iterator mit;
int n, m;

void check_around(vector<vector<int>> &field, int r, int c) {
	bool oka = 0, okd = 0, okb = 0, okc = 0;
	pair<int, int> v1 = mk(r - 1, c);
	pair<int, int> v2 = mk(r, c - 1);
	pair<int, int> v3 = mk(r, c + 1);
	pair<int, int> v4 = mk(r + 1, c);
	// 1
	if (!notin(mp, v1)) {
		// 1 2
		if (!notin(mp, v2)) 
		{
			int row = r - 1;
			int col = c - 1;
			pair<int, int> par = mk(mp.at(v1), mp.at(v2));
			pair<int, int> rap = mk(mp.at(v2), mp.at(v1));
			if (field[row][col]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[row][col] = 0;
				}
			} else if (field[r][c]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r][c] = 0;
				}
			}
		}
		// 1 3
		if (!notin(mp, v3)) 
		{
			int row = r - 1;
			int col = c + 1;
			pair<int, int> par = mk(mp.at(v1), mp.at(v3));
			pair<int, int> rap = mk(mp.at(v3), mp.at(v1));
			if (field[row][col]) {
				if (notin(fff, par) && notin(fff, rap)){
					fff.insert(par);
					field[row][col] = 0;
				}
			} else if (field[r][c]) {
				if (notin(fff, par) && notin(fff, rap)){
					fff.insert(par);
					field[r][c] = 0;
				}
			}
		}
		// 1 4
		if (!notin(mp, v4)) 
		{
			pair<int, int> par = mk(mp.at(v1), mp.at(v4));
			pair<int, int> rap = mk(mp.at(v4), mp.at(v1));
			if (field[r][c]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r][c] = 0;
				}
			}
		}
	}
	// 2
	if (!notin(mp, v2)) 
	{
		// 2 3
		if (!notin(mp, v3)) 
		{
			pair<int, int> par = mk(mp.at(v2), mp.at(v3));
			pair<int, int> rap = mk(mp.at(v3), mp.at(v2));
			if (field[r][c]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r][c] = 0;
				}
			}
		}
		// 2 4
		if (!notin(mp, v4)) 
		{
			if (field[r][c]) oka = true;
			if (field[r+1][c-1]) okd = true;
		}
	}
	// 3
	if (!notin(mp, v3)) 
	{
		// 3 4
		if (!notin(mp, v4)) 
		{
			if (field[r][c]) okb = true;
			if (field[r+1][c-1]) okc = true;
		}
	}
	if (oka && !okb) {
		pair<int, int> par = mk(mp.at(v4), mp.at(v2));
		pair<int, int> rap = mk(mp.at(v2), mp.at(v4));
		if (field[r][c]) {
			if (notin(fff, par) && notin(fff, rap)) {
				fff.insert(par);
				field[r][c] = 0;
			}
		}
		return;
	} else if (!oka && okb) {
		pair<int, int> par = mk(mp.at(v4), mp.at(v3));
		pair<int, int> rap = mk(mp.at(v3), mp.at(v4));
		if (field[r][c]) {
			if (notin(fff, par) && notin(fff, rap)) {
				fff.insert(par);
				field[r][c] = 0;
			}
		}
		return;
	}
	if (!oka && !okb) {
		if (okd) {
			pair<int, int> par = mk(mp.at(v4), mp.at(v2));
			pair<int, int> rap = mk(mp.at(v2), mp.at(v4));
			if (field[r + 1][c - 1]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r + 1][c - 1] = 0;
				}
			}
		}
		if (okc) {
			pair<int, int> par = mk(mp.at(v4), mp.at(v3));
			pair<int, int> rap = mk(mp.at(v3), mp.at(v4));
			if (field[r + 1][c + 1]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r + 1][c + 1] = 0;
				}
			}
		}
		return;
	}
	if (oka && okb) {
		if (okd && !okc) {
			pair<int, int> par = mk(mp.at(v4), mp.at(v3));
			pair<int, int> rap = mk(mp.at(v3), mp.at(v4));
			if (field[r][c]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r][c] = 0;
				}
			}
			par = mk(mp.at(v4), mp.at(v2));
			rap = mk(mp.at(v2), mp.at(v4));
			if (field[r + 1][c - 1]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r + 1][c - 1] = 0;
				}
			}
			return;			
		}
		if (!okd && okc) {
			pair<int, int> par = mk(mp.at(v4), mp.at(v2));
			pair<int, int> rap = mk(mp.at(v2), mp.at(v4));
			if (field[r][c]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r][c] = 0;
				}
			}
			par = mk(mp.at(v4), mp.at(v3));
			rap = mk(mp.at(v3), mp.at(v4));
			if (field[r + 1][c + 1]) {
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
					field[r + 1][c + 1] = 0;
				}
			}
			return;			
		} else {
			check_around(field, r + 1, c - 1);
			check_around(field, r + 1, c + 1);
			int ava = 0;
			if (field[r][c]) ava++;
			if (field[r+1][c-1]) ava++;
			if (field[r+1][c+1]) ava++;
			if (ava >= 2) {
				pair<int, int> par = mk(mp.at(v4), mp.at(v2));
				pair<int, int> rap = mk(mp.at(v2), mp.at(v4));
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
				}
				par = mk(mp.at(v4), mp.at(v3));
				rap = mk(mp.at(v3), mp.at(v4));
				if (notin(fff, par) && notin(fff, rap)) {
					fff.insert(par);
				}
			}
		}
	}
	return;
}


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int> (m, 0));
	int cnt = 1;
	
	rep (i, 0, n) {
		string line;
		cin >> line;
		rep (j, 0, m) {
			if (line[j] == 'C') {
				pair<int, int> xy = mk(i, j);
				mp[xy] = cnt;
				cnt++;
			}
			if (line[j] == 'G') field[i][j] = 1;
		}
	}
	
	rep (i, 0, n) rep (j, 0, m)
			if (field[i][j]) check_around(field, i, j);

	cout << fff.size();
	
	return 0;
}




