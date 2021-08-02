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

int h, w;
pair<int, int> x = {0, 0};

void closer(vector<vector<bool>> v) {
	int r = x.first;
	int c = x.second;
	int dist = (h-1) - r + (w-1) - c;
	//pair<int, int> x = {h-1, w-1};
	x = {h-1, w-1};
	REP (i, r, h) {
		REP (j, c, w) {
			if (v[i][j]) 
			{
				int d = (i - r) + (j - c);
				if (d < dist) {
					dist = d;
					x.first = i;
					x.second = j;
				}
			}
		}
	}
}

void solve () {
	int ans = 0;
	cin >> h >> w;
	vector<vector<bool>> v(h, vector<bool> (w, 0));
	REP (i, 0, h) {
		string tmp;
		cin >> tmp;
		REP (j, 0, w) {
			if (tmp[j] == '*') v[i][j] = true;
		}
	}
	do {
		closer(v);
		if (v[x.first][x.second]) {
			v[x.first][x.second] = false;
			//cout << x.first << " " << x.second << "\n";
			ans++;
		}
	} while (x.first != h-1 && x.second != w-1);
	cout << ans << "\n";
}


int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}

