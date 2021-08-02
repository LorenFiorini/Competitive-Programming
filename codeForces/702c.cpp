#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()

set<ll> cub;

void help() {
	ll c = 1;
	ll tmp = 1;
	while (tmp <= 1e12) {
		cub.insert(tmp);
		c++;
		tmp = pow(c, 3);
	}
	return;
}


void solve () {
	string ans = "NO";
	ll n;
	cin >> n;
	set<ll>:: iterator it;
	ll m = cub.size();
	REP (i, 1, n) {
		ll tmp = n - pow(i, 3);
		if (tmp < 0) break;
		it = cub.find(tmp);
		if (it != cub.end()) {
			cout << "YES\n";
			return;
		}
	}
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	help();
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

