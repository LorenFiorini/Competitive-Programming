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
	//vector<ll> a;
	//vector<ll>:: iterator it;
	int a = 1;
	int b = 4;
	int tmp = 3;
	int c;
	while (tmp <= n) {
		c = tmp * tmp;
		if (a + b == c) {
			ans++;
		}
		a = b;
		b = c;
		tmp++;
	}
	/*int m = a.size();
	REP (i, 0, m) {
		REP (j, i + 1, m) {
			ll tmp = a[i] + a[j];
			it = find(a.begin(), a.end(), tmp);
			if (it != a.end()) ans++;
		} 
	}*/
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
