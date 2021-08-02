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


void solve () {
	ll a,b;
	int c = 0;
	cin >> a >> b;
	ll ans = a - b + 2;
	if (b == a) {
		cout << "2\n";
		return;
	} else if (b > a) {
		cout << "1\n";
		return;
	}
	REP (i, 0, a - b + 2) {
		if (b + i == 1) continue;
		ll sum = i;
		ll aa = a;
		while (aa > 0) {
			aa = aa / (b + i);
			sum++;
		}
		ans = min(ans, sum);
		if (sum > ans * 2) break;
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

