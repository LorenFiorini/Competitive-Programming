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
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	vector<int> cnt(2, 0);
	REP (i, 0, n) {
		cin >> v[i];
		cnt[v[i]]++;
	}
	REP (i, 0, q) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			x--;
			if (v[x] == 1) {
				cnt[1]--;
				cnt[0]++;
				v[x] = 0;
			} else {
				cnt[1]++;
				cnt[0]--;
				v[x] = 1;
			}
		} else {
			if (x <= cnt[1]) {
				cout << "1\n";
			} else {
				cout << "0\n";				
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
//$ sudo g++ -o name name.cpp
//$ ./name

