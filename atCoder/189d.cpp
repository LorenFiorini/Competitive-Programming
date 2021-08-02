#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define SCd(t) scanf("%d",&t)
#define SClld(t) scanf("%lld",&t)
#define SCc(t) scanf("%c",&t)
#define SCs(t) scanf("%s",t)
#define SClf(t) scanf("%lf",&t) //double
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


ll dp[2];
ll cop[2];

void solve () {
	int n; cin >> n;
	vector<string> s(n);
	REP (i, 0, n) cin >> s[i];
	
	dp[0] = dp[1] = 1;
	REP (i, 0, n) // Every expression (logical opeators AND or OR)
	{
		REP (j, 0, 2) { 						// 0 0 
			REP (x, 0, 2) {						// 0 1
				if (s[i] == "AND") 				// 1 0	
				{								// 1 1
					cop[j & x] += dp[j];
										// 0 0 0 1
				} else 
				{
					cop[j | x] += dp[j];
										// 0 1 1 1 
				}
			}
		}
		REP (j, 0, 2) {
			//finish this
			dp[j] = cop[j];
			cop[j] = 0;
		}
	}
	
	cout << dp[1] << "\n";
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
