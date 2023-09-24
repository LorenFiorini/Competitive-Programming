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
	ll ans = 0;
	ll n;
	cin >> n;
	ll l = sqrt(n);
	
	set<ll> st;
	set<ll> :: iterator it;
	REP (i, 2, l + 1) {
		double a = ((double) log((double) n) ) / ( (double) log((double) i));
		//cout << a << " ";
		int m = a;
		if (m < 2) break;
		REP (j, 2, m + 1) {
			ll tmp = pow((ll) i, (ll) j);
			it = st.find(tmp);
			if (it == st.end()) {
				st.insert(tmp);
				ans++;
			}
		}
	}
	ll answer = n - ans;
	cout << answer << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

