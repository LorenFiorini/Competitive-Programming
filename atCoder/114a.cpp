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

ll ar[51];
set<ll> st;
set<ll> zt;
set<ll> :: iterator it;

void sieve() {
	int mx = 51;
	REP (i, 1, mx) ar[i] = -1;
	
	REP (i, 2, mx) {
		if (ar[i] == -1) 
		{
			FOR (j, i, mx, i) {
				if (ar[j] == -1) 
					ar[j] = i;
			}
		}
	}
	REP (i, 0, mx) cout << ar[i] << "  ";
}

void solve () {
	ll ans = 1;
	int n;
	cin >> n;
	vector<ll> v(n);
	REP (i, 0, n) cin >> v[i];
	REP (i, 0, n) {
		ll num = v[i];
		bool there = false;
		vector<ll> tmp;
		while (num > 1) {
			tmp.push_back(ar[num]);
			it = st.find(ar[num]);
			if (it != st.end()) {
				there = true;
				break;
			}
			num /= ar[num];
		}
		if (there) continue;
		//ll tmp = ar[v[i]];
		it = st.find(tmp[0]);
		if (it == st.end()) {
			st.insert(tmp[0]);
		}
	}
	REP (i, 0, n) {
		ll num = v[n-1 - i];
		bool there = false;
		vector<ll> tmp;
		while (num > 1) {
			tmp.push_back(ar[num]);
			it = zt.find(ar[num]);
			if (it != zt.end()) {
				there = true;
				break;
			}
			num /= ar[num];
		}
		if (there) continue;
		//ll tmp = ar[v[i]];
		it = zt.find(tmp[0]);
		if (it == zt.end()) {
			zt.insert(tmp[0]);
		}
	}
	
	FOREACH(it, st) {
		ans *= (ll) (*it);
	}
	ll ann = 1;
	FOREACH(it, zt) {
		ann *= (ll) (*it);
	}
	ans = min(ans, ann);
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name
