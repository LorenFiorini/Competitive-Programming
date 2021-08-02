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
	int ans = -1;
	int n;
	cin >> n;
	map<int, int> mp;
	map<int, int> :: iterator it;
	REP (i, 0, n) {
		int num;
		cin >> num;
		it = mp.find(num);
		if (it == mp.end()) {
			mp.insert(pair<int, int> (num, 1));
		} else {
			it->second++;
		}
	}
	REP (i, 0, 101) {
		it = mp.find(i);
		if (it != mp.end()) {
			cout << i << " ";
			it->second--;
		} else if (ans == -1) {
			ans = i;
		}
	}
	REP (i, 0, 101) {
		it = mp.find(i);
		if (it != mp.end()) {
			while (it->second > 0) {
				cout << i << " ";
				it->second--;
			}
		}
	}
	
	cout << "\n";
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

