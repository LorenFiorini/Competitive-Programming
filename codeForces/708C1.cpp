
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
	int n, k;
	cin >> n >> k;
	if (n % 2) {
		cout << 1 << " " << n / 2 << " " << n / 2;
	} else {
		if (n % 4 == 0) {
			cout << n / 4 << " " << n / 4 << " " << n / 2;			
		} else {
			cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1;
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
