#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 998244353
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
	multiset<ll> st;
	multiset<ll>::iterator iti;
	REP (i, 0, n) {
		ll num;
		cin >> num;
		st.insert(num);
 	}
 	 	
 	vector<ll> f(n, 1);
 	REP (i, 1, n) {
		if (i % 2 == 0) {
			f[i] = f[i/2] * f[i/2];
		} else {
			f[i] = f[i/2] * f[i/2];
			f[i] %= MOD;
			f[i] *= 2;
		}
		f[i] %= MOD;
	}
 	for (iti = st.begin(); iti != st.end(); iti++)
 	{
		
		int i = 0; 
		multiset<ll>::iterator itj = iti;
		for (itj; itj != st.end(); itj++) 
		{
			ll tmp = (*iti) * (*itj);
			//cout << tmp << "\n";
			tmp %= MOD;
			if (i - 1 >= 0)
			tmp *= f[i - 1];
			tmp %= MOD;
			
			ans += tmp;
			ans %= MOD;
			i++;
		}
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}

