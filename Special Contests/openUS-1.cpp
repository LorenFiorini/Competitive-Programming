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
	int ans;
	int n;
	cin >> n;
	string str; string tmp;
	map<string, int> mp;
	map<string, int>:: iterator it;
	REP (i, 0, n) {
		getline(cin, str);
		stringstream ss(str);
		while (getline(ss, tmp, ' ')) {
			it = mp.find(tmp);
			if (it == mp.end()) {
				mp.insert(pair<string, int> (tmp, 1));
			} else {
				it->second++;
			}
		}
	}
	int mx = 0;
	FOREACH (it, mp) {
		if (it -> second > mx) mx = it->second;
	}
	cout << n - mx << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int t; cin >> t;
	//while (t--) 
	solve();
	
	return 0;
}
