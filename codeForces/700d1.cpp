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
	vector<int> a(n);
	vector<int> b(n);
	REP (i, 0, n) cin >> a[i];
	int pa = 0, ca = 1;
	int pb = 0, cb = 0;
	REP (i, 1, n) 
	{
		if (a[i] == a[i-1]) 
		{
			b[pb] = a[i];
			if (pb > 0) {
				if (b[pb] != b[pb-1]) {
					cb++;
				}				
			} else if (pb == 0) {
				cb++;
			}
			pb++;
		} else {
			ca++;
		}
		
	}
	ans = ca + cb;
	cout << ans << "\n";
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
//$ sudo g++ -o name name.cpp
//$ ./name

