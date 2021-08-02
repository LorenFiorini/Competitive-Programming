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


ll f (ll x) {
	ll g1 = 0, g2 = 0;
	vector<int> v;
	while (x > 0) {
		v.push_back(x % 10);
		x /= 10;
	}
	sort(v.begin(), v.end());
	int n = v.size();
	REP (i, 0, n) {
		g1 += v[n-1 - i];
		g1 *= 10;
		g2 += v[i];
		g2 *= 10;
		//cout << g1 << "  " << g2 << "	 \n";
	}
	g1 /= 10;
	g2 /= 10;
	return (g1 - g2);
}


void solve () {
	ll n , k;
	cin >> n >> k;
	while (k > 0) {
		//cout << n << "	 \n";
		n = f(n);
		k--;
	}
	cout << n << "\n";
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

