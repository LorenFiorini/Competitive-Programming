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
	//REP (i, 0, mx) cout << ar[i] << "  ";
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
			if (it == st.end()) {
				st.insert(ar[num]);
			}
			num /= ar[num];
		}
	}
	ll tot = 1;
	int m = st.size();
	vector<ll> fac(m); int p = 0;
	FOREACH (it, st) {
		fac[p] = *it;
		tot *= fac[p];
		cout << fac[p] << " ";
		p++;
	}
	bool ok= true;
	ll pointer;
	while (1) {
		ok = false;
		m = fac.size();
		RREP (i, m, 0) {
			ll tmp = tot / fac[i];
			cout << "\n" << tmp;
			ok = true;
			REP (j, 0, n) {
				if (tmp % v[i] != 0) {
					ok = false;
					break;
				}
			}
			if (ok) {
				pointer = (ll) i;
				tot /= fac[i];
				break;
			}
		}
		if (ok) {
			fac.erase(fac.begin() + pointer);
		} else break;
	}
	REP (i, 0, fac.size()) {
		ans *= fac[i];
	}
	
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

