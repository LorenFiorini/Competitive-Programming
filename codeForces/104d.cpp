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
	int ans = 0;
	int n;
	cin >> n;
	vector<int> a;
	int tmp = 1;
	while (tmp <= n) {
		tmp *= tmp;
		a.push_back(tmp);
		tmp++;
	}
	REP (i, 0, a.size()) {
		//a[i];
		REP (j, 1, a[i]) {
			int cc = j * j;
			//if (cc > n) break;
			int bb = pow(a[i] - j, 2);
			if (cc == a[i] + bb) ans++;
		}
	}
	
	cout << ans << "\n";
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
