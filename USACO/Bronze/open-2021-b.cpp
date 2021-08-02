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
	int ans;
	int n, k;
	cin >> k >> n;
	vector<string> name(n);
	map<string, pair<int, int>> mp;
	map<string, pair<int, int>> :: iterator it;
	REP (i, 0, n) {
		string s;
		cin >> s;
		name[i] = s;
		it = mp.find(s);
		if (it == mp.end()) {
			mp.insert(make_pair(s, make_pair(0 , 0)));
		}
		//mp[s].min = 0;
		//mp[s].max = 0;
	}
	
	// LEER PAPERS NAMES
	REP (papers, 0, k) 
	{
		// CIN && SET
		vector<string> str(n);
		vector<pair<int, int>> po(n);
		REP (i, 0, n) {
			cin >> str[i];
			po[i].min = i;
			po[i].max = i;
		}
		// IDA
		REP (i, 1, n) {
			if (str[i - 1] <= str[i]) {
				po[i].min = po[i - 1].min;
			}
		}
		// VUELTA
		RREP (i, n, 1) {
			if (str[i - 1] <= str[i]) {
				po[i - 1].max = po[i].max;
			}
		}
		// SUM IN MAP
		REP (i, 0, n) {
			/*cout << str[i] << "\n";
			cout << po[i].min << " ";
			cout << po[i].max << "\n\n";*/
			mp[ str[i] ].min += po[i].min;
			mp[ str[i] ].max += po[i].max;
		}
	}
// SHOW -------------------------------------------
	/*FOREACH(mp, it) {
		cout << it->first << "\n\n";
	}
	REP (i, 0, n) {
		cout << name[i] << "\n";
		cout << mp[ name[i] ].min << " ";
		cout << mp[ name[i] ].max << "\n\n";
	}*/
// SHOW -------------------------------------------
	REP (i, 0, n) {
		REP (j, 0, n) 
		{
			if (i == j) {
				cout << "B";
				continue;
			}
			int mii = mp[ name[i] ].min;
			int mai = mp[ name[i] ].max;
			int midi = (mii + mai) / 2;
			int mij = mp[ name[j] ].min;
			int maj = mp[ name[j] ].max;
			int midj = (mij + maj) / 2;
			
			if (midi > midj) { 
				cout << "1";
			} else if (midi < midj) {
				cout << "0";				
			} else {
				cout << "?";				
			}
			//if (mai > mij || mii < maj)
		}
		cout << "\n";
	}
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
