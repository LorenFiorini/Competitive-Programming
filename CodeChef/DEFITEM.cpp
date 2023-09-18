#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define SCd(t) scanf("%d",&t)
#define SClld(t) scanf("%lld",&t)
#define SCc(t) scanf("%c",&t)
#define SCs(t) scanf("%s",t)
#define SClf(t) scanf("%lf",&t) //double
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
	int ans;
	ll n, q;
	cin >> n >> q;
	vector<ll> v(n);
	map<ll, ll> mp;
	map<ll, ll>::iterator it;
	REP (i, 0, n) {
		cin >> v[i];
	}
	ll sum = 0, mus = 0;
	REP (i, 0, n) {
		sum += v[i];
		it = mp.find(v[i]);
		if (it == mp.end()) {
			mp.insert(make_pair(v[i], sum));
		} else {
			it->second = min(it->second, sum); 
		}
		//
		mus += v[n-1-i];
		it = mp.find(v[n-1-i]);
		if (it == mp.end()) {
			mp.insert(make_pair(v[n-1-i], mus));
		} else {
			it->second = min(it->second, mus);
		}
	}
	REP (i, 0, q) {
		ll tmp;
		cin >> tmp;
		it = mp.find(tmp);
		cout << it->second << "\n";
	}
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
