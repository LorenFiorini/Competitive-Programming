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
	ll ans = 1e17;
	int n;
	cin >> n;
	vector<ll> v(n);
	REP (i, 0, n) cin >> v[i];
	
	set<ll> st;
	set<ll> :: iterator it;
	int c = 0;
	while (c != n) {
		REP (i, 0, n) {
			st.clear();
			int p = (i + c) % n;
			ll num = v[p];
			//cout << num << "\n";
			bool there = false;
			//vector<ll> tmp;
			ll mum = num;
			while (num > 1) {
				//tmp.push_back(ar[num]);
				it = st.find(ar[num]);
				if (it != st.end()) {
					there = true;
					break;
				}
				num /= ar[num];
			}
			if (there) continue;
			//ll tmp = ar[v[i]];
			it = st.find(ar[mum]);
			if (it == st.end()) {
				st.insert(ar[mum]);
			}
		}
		
		ll ann = 1;
		FOREACH(it, st) {
			ann *= (ll) *it;
			cout << *it << "\n";
		}
		cout << "\n" << ann << "\n";
		ans = min(ans, ann);
		c++;
	}
	c = 0;
	while (c != n) {
		st.clear();
		REP (i, 0, n) {
			int p = ((n - 1 - i) + c) % n;
			ll num = v[p];
			cout << num << "\n";
			bool there = false;
			//vector<ll> tmp;
			ll mum = num;
			while (num > 1) {
				//tmp.push_back(ar[num]);
				it = st.find(ar[num]);
				if (it != st.end()) {
					there = true;
					break;
				}
				num /= ar[num];
			}
			if (there) continue;
			//ll tmp = ar[v[i]];
			it = st.find(ar[mum]);
			if (it == st.end()) {
				st.insert(ar[mum]);
			}
		}
		
		ll ann = 1;
		FOREACH(it, st) {
			ann *= (ll) (*it);
		}
		cout << "\n" << ann << "\n";
		ans = min(ans, ann);
		c++;
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

