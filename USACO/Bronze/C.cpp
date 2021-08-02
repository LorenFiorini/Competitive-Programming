#include <bits/stdc++.h>
using namespace std;
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define REP(i, a, b) por(i, a, b, 1)
#define notin(c, x) ((c).find(x) == (c).end())

int N, M;
set<pair<int, int>> friends;
map<pair<int, int>, int> mp;
set<pair<int, int>> :: iterator sit;
map<pair<int, int>, int> :: iterator mit;

void bfs(vector<vector<int>> &field, int r, int c) {
	bool oka = 0, okd = 0, okb = 0, okc = 0;
	pair<int, int> v1 = make_pair(r - 1, c);
	pair<int, int> v2 = make_pair(r, c - 1);
	pair<int, int> v3 = make_pair(r, c + 1);
	pair<int, int> v4 = make_pair(r + 1, c);
	// 1
	if (!notin(mp, v1)) {
		// 1 2
		if (!notin(mp, v2)) 
		{
			int row = r - 1;
			int col = c - 1;
			pair<int, int> par = make_pair(mp.at(v1), mp.at(v2));
			pair<int, int> rap = make_pair(mp.at(v2), mp.at(v1));
			if (field[row][col]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[row][col] = 0;
				}
			} else if (field[r][c]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[r][c] = 0;
				}
			}
		}
		// 1 3
		if (!notin(mp, v3)) 
		{
			int row = r - 1;
			int col = c + 1;
			pair<int, int> par = make_pair(mp.at(v1), mp.at(v3));
			pair<int, int> rap = make_pair(mp.at(v3), mp.at(v1));
			if (field[row][col]) {
				if (notin(friends, par) && notin(friends, rap)){
					friends.insert(par);
					field[row][col] = 0;
				}
			} else if (field[r][c]) {
				if (notin(friends, par) && notin(friends, rap)){
					friends.insert(par);
					field[r][c] = 0;
				}
			}
		}
		// 1 4
		if (!notin(mp, v4)) 
		{
			pair<int, int> par = make_pair(mp.at(v1), mp.at(v4));
			pair<int, int> rap = make_pair(mp.at(v4), mp.at(v1));
			if (field[r][c]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
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
			pair<int, int> par = make_pair(mp.at(v2), mp.at(v3));
			pair<int, int> rap = make_pair(mp.at(v3), mp.at(v2));
			if (field[r][c]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
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
		pair<int, int> par = make_pair(mp.at(v4), mp.at(v2));
		pair<int, int> rap = make_pair(mp.at(v2), mp.at(v4));
		if (field[r][c]) {
			if (notin(friends, par) && notin(friends, rap)) {
				friends.insert(par);
				field[r][c] = 0;
			}
		}
		return;
	} else if (!oka && okb) {
		pair<int, int> par = make_pair(mp.at(v4), mp.at(v3));
		pair<int, int> rap = make_pair(mp.at(v3), mp.at(v4));
		if (field[r][c]) {
			if (notin(friends, par) && notin(friends, rap)) {
				friends.insert(par);
				field[r][c] = 0;
			}
		}
		return;
	}
	if (!oka && !okb) {
		if (okd) {
			pair<int, int> par = make_pair(mp.at(v4), mp.at(v2));
			pair<int, int> rap = make_pair(mp.at(v2), mp.at(v4));
			if (field[r + 1][c - 1]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[r + 1][c - 1] = 0;
				}
			}
		}
		if (okc) {
			pair<int, int> par = make_pair(mp.at(v4), mp.at(v3));
			pair<int, int> rap = make_pair(mp.at(v3), mp.at(v4));
			if (field[r + 1][c + 1]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[r + 1][c + 1] = 0;
				}
			}
		}
		return;
	}
	if (oka && okb) {
		if (okd && !okc) {
			pair<int, int> par = make_pair(mp.at(v4), mp.at(v3));
			pair<int, int> rap = make_pair(mp.at(v3), mp.at(v4));
			if (field[r][c]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[r][c] = 0;
				}
			}
			par = make_pair(mp.at(v4), mp.at(v2));
			rap = make_pair(mp.at(v2), mp.at(v4));
			if (field[r + 1][c - 1]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[r + 1][c - 1] = 0;
				}
			}
			return;			
		}
		if (!okd && okc) {
			pair<int, int> par = make_pair(mp.at(v4), mp.at(v2));
			pair<int, int> rap = make_pair(mp.at(v2), mp.at(v4));
			if (field[r][c]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[r][c] = 0;
				}
			}
			par = make_pair(mp.at(v4), mp.at(v3));
			rap = make_pair(mp.at(v3), mp.at(v4));
			if (field[r + 1][c + 1]) {
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
					field[r + 1][c + 1] = 0;
				}
			}
			return;			
		} else {
			bfs(field, r + 1, c - 1);
			bfs(field, r + 1, c + 1);
			int ava = 0;
			if (field[r][c]) ava++;
			if (field[r+1][c-1]) ava++;
			if (field[r+1][c+1]) ava++;
			if (ava >= 2) {
				pair<int, int> par = make_pair(mp.at(v4), mp.at(v2));
				pair<int, int> rap = make_pair(mp.at(v2), mp.at(v4));
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
				}
				par = make_pair(mp.at(v4), mp.at(v3));
				rap = make_pair(mp.at(v3), mp.at(v4));
				if (notin(friends, par) && notin(friends, rap)) {
					friends.insert(par);
				}
			}
		}
	}
	return;
}


int main () {
	cin >> N >> M;
	vector<vector<int>> field(N, vector<int> (M, 0));
	int cnt = 1;
	REP (i, 0, N) {
		string line;
		cin >> line;
		REP (j, 0, M) {
			if (line[j] == 'C') {
				pair<int, int> xy = make_pair(i, j);
				mp[xy] = cnt;
				cnt++;
			}
			if (line[j] == 'G') field[i][j] = 1;
		}
	}
	REP (i, 0, N) REP (j, 0, M)
			if (field[i][j]) bfs(field, i, j);
	int answer = friends.size();	
	cout << answer;
	return 0;
}




