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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	REP (i, 0, n) {
		cin >> v[i];
	}
	sort (all(v));
	vector<int> cnt (n, 2);
	ans = n;
	REP (i, 0, n) {
		int p = -1;
		REP (j, i + 1, n) {
			if ((v[i] + v[j]) % m == 0 && cnt[j] > 0) {
				if (cnt[i] + cnt[j] <= 2) continue;
				ans--;
				cnt[j]--;
				if (p != -1) break;
				p = j;
			}
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

