#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define pii pair<int, int> 
#define fi first
#define se second
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()

pair<int, int>  check (int ar, int ac, int br, int bc) {
	pair<int, int> ans = 
	if (field[ar][bc] && !field[br][ac]) {
		field[ar][bc] = 0;
		ans++;
	} else if (!field[ar][bc] && field[br][ac]) {
		field[br][ac] = 0;
		ans++;
	} else if (field[ar][bc] && field[br][ac]) {
		vacas.push_back(cows[i]);
		vacas.push_back(cows[j]);				
	}
}


void solve () {
	int ans = 0;
	// INPUT
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int> (m, 0));
	vector< pair<int, int> > cows;
	REP (i, 0, n ) {
		string str;
		cin >> str;
		REP (j, 0, m) {
			if (str[j] == '.') field[i][j] = 1;
			else if (str[j] == 'C') {
				pair<int, int> coor = make_pair(i, j);
				cows.push_back(coor);
			}
		}
	}
	// Combinaciones de vacas
	vector< pair<int, int> > vacas;
	int sz = cows.size();
	REP (i, 0, sz - 1) {
		REP (j, i + 1, sz) {
			int ar = cows[i].fi;
			int ac = cows[i].se;
			int br = cows[j].fi;
			int bc = cows[j].se;
			
		}
	}
	sz = vacas.size();
	while (sz > 0)
	{
		cows.swap(vacas);
		vacas.clear();
		int cmp = ans;
		FOR (i, 0, sz, 2) {
			int j = i+1;
			int ar = cows[i].fi;
			int ac = cows[i].se;
			int br = cows[j].fi;
			int bc = cows[j].se;
			if (field[ar][bc] && !field[br][ac]) {
				field[ar][bc] = 0;
				ans++;
			} else if (!field[ar][bc] && field[br][ac]) {
				field[br][ac] = 0;
				ans++;
			} else if (field[ar][bc] && field[br][ac]) {
				vacas.push_back(cows[i]);
				vacas.push_back(cows[j]);				
			}
		}
		if (cmp == ans) {
			ans += (sz / 2);
			break;
		}
		sz = vacas.size();
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



