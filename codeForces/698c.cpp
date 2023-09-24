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
	vector<int> v(2 * n);
	map<int, pair<int, int>> mp;
	map<int, pair<int, int>>:: iterator it;
	
	REP (i, 0, 2 * n) {
		int tmp;
		cin >> tmp;
		it = mp.find(tmp);
		if (it == mp.end()) {
			mp[tmp] = pair<int,int>(i, 0);
		} else {
			it->second.second = i;
		}
	}
	if (mp.size() > n) {
		cout < "NO\n";
		return;
	}
	
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name
