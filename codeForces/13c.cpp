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
	ll ans = 0;
	ll n;
	cin >> n;
	queue<int> q;
	vector<ll> s(n + 1); s[0] = 1;
	REP (i, 1, n + 1) {
		cin >> s[i];
		//if (s[i] > 1) q.push(i);
		
	}
	bool ok = false;
	while (!ok) {
		ok = true;
		ans++;
		for (ll i = s[0]; i < n + 1; i++) {
			if (s[i] > 1) {
				if (ok) s[0] = i; 
				if (s[i] + i > n && ok) {
					ll tmp = i + s[i] - (n );// n- 1
					s[i] -= tmp;
					ans += (tmp - 1);
					//if (!ok) ans--;
					//ans--;
					if (s[i] == 0) {
						s[i]++;
						ans--;
					}
					ok = false;
					break;
				}
				ok = false;
				s[i]--;
				i += (s[i]);
			} 
		}
		if (ok) ans--;
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

