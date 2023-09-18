#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
	// input
	string s; ll m;
	cin >> s; cin >> m;
	// basic stuff
	int sz = s.size();
	vector<ll> v(sz);
	ll d = 0;
	REP (i, 0, sz) {
		string ch = s.substr(i, 1);
		ll tmp = stoi(ch);
		v[sz-1 - i] = tmp;
		d = max(d, tmp);
	}
	//
	vector<ll> base(sz);
	int k = 1;
	while (1) {
		ll sum = 0;
		base[0] = 1;
		REP (i, 0, sz) {
			// first term
			if (i > 0) base[i] = base[i-1] * (d + k);
			if (base[i] > m) {
				cout << (k - 1) << "\n";
				return;
			}
			// this digit conversion
			//ll tmp = pow(base[i], i);
			ll tmp = v[i] * base[i];
			if (tmp > m) {
				cout << (k - 1) << "\n";
				return;
			}
			// yeah the sum
			sum += tmp;
			if (sum > m) {
				
				cout << (k - 1) << "\n";
				return;
			}
		}
		//cout << sum << " ";
		k++;
	}
	
	//cout << ans << "\n";
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

