#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define min first
#define max second
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
	int n, k;
	cin >> k >> n;
	vector<string> name(n);
	vector<vector<int>> v(n , vector<int> (n, 0));
	map<string, int> mp;
	map<string, int>> :: iterator it;
	
	REP (i, 0, n) {
		string s;
		cin >> s;
		name[i] = s;
		it = mp.find(s);
		if (it == mp.end()) {
			mp.insert(make_pair(s, i));
		}
	}
	
	REP (papers, 0, k) 
	{
		vector<string> str(n);
		vector<int> pos(n);
		REP (i, 0, n) 
		{
			// name
			cin >> str[i];
			pos[i] = i;
			if (i && str[i-1] < str[i]) {
				p[i] = p[i - 1];
			}
		}
		REP (i, 0, n) {
			REP ( j, 0, n) {
				if (i == j)
			}
		}
	}
	
	
	
	
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
