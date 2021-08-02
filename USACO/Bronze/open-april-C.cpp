#include <bits/stdc++.h>
using namespace std;

#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define showp(x, y) cout << x << " "<< y << "\n";
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define rep(i, a, b) for (int i=a; i<b ; i++)
#define rrep(i, a, b) for (int i=a-1 ; i>=b ; i--)
set<pair<int, int>> friends;
set<pair<int, int>> :: iterator setit;
map<pair<int, int>, int> mp;
map<pair<int, int>, int> :: iterator mapit;
map<pair<int, int>, int> :: iterator it;
int n, m;

void bfs(int r, int c, vector<vector<char>> &v, int cow) {
	it = mp.find(make_pair(r + 1, c - 1));
	queue <pair<int, int> > q;
	if (it != mp.end()) {
		pair<int, int> cc = make_pair(it->second, cow);
		setit = friends.find(cc);
		if (v[r][c - 1] == 'G' && setit != friends.end()) {
			v[r][c - 1] = '.';
			friends.insert(cc);
			swap(cc.first, cc.second);
			friends.insert(cc);
		} else if (v[r + 1][c] == 'G') {
			q.push(make_pair(r + 1, c - 1));
		}
	}
	it = mp.find(make_pair(r + 1, c + 1));
	if (it != mp.end()) {
		pair<int, int> dd = make_pair(it->second, cow);
		setit = friends.find(dd);
		if (v[r][c + 1] == 'G' && setit != friends.end()) {
			v[r][c + 1] = '.';
			friends.insert(dd);
			swap(dd.first, dd.second);
			friends.insert(dd);
		} else if (v[r + 1][c] == 'G') {
			q.push(make_pair(r + 1, c + 1));
		}
	}
	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;
		pair<int, int> vaca = make_pair(row, col);
		it = mp.find(vaca);
		bfs(row, col, v, it->second);
		if (v[r+1][c] == 'G') {
			v[r+1][c] = '.';
			pair<int, int> ee = make_pair(it->second, cow);
			friends.insert(ee);
			swap(ee.first, ee.second);
			friends.insert(ee);
		}
		q.pop();
	}
	pair<int, int> vak = make_pair(r, c);
	it = mp.find(vak);
	mp.erase(it);
}


int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int answer = 0;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char> (m));
	int number = 1;
	rep (i, 0, n) {
		string str;
		cin >> str;
		rep (j, 0, m) {
			v[i][j] = str[j];
			if (str[j] == 'C') {
				pair<int, int> pos = make_pair(i, j);
				mp[pos] = number;
				number++;
			}
		}
	}
	while(!mp.empty()) {
		mapit = mp.begin();
		int r = mapit->first.first;
		int c = mapit->first.second;
		int cow = mapit->second;
		bfs(r, c, v, cow);		
	}
	for (setit = friends.begin(); setit != friends.end(); setit++){
		int x = setit->first;
		int y = setit->second;
		cout << x << " "<< y << "\n";
	}
	answer = friends.size();	
	cout << answer;
	return 0;
}




