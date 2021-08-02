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
	int n, k;
	cin >> n >> k;
	if (n % 2 == 0) {
		int tmp = k % n ? k % n : n; 
		cout << tmp << "\n";
		return;
	} else {
		int kk = k;
		while (1) {
			if (kk - n >= 0) {
				k++;
				kk++;
				kk -= n;
			} else {
				break;
			}
			
		}
		if (k % n > n / 2) k++;
		int tmp = k % n ? k % n : n; 
		cout << tmp << "\n";
	}
	
	//cout << ans << "\n";
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

