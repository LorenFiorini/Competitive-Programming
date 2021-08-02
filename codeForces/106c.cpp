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
	int n;
	cin >> n;
    vector<int> v(n);
    int par = 1e5 + 1;
    int impar = 1e5 + 1;
    int pp, pi ;
    REP (i, 0, n) {
        cin >> v[i];
        if (i % 2 == 0) {
            if (v[i] < par) {
                par = v[i];
                pp = i;
            }
        } else {
            if (v[i] < impar) {
                impar = v[i];
                pi = i;
            }
        }
    }
    int cpar = n;
    int cimpar = n;
	REP (i, 0, max(2, max(pi, pp))) {
        ans += (ll) v[i];
        if (i % 2 == 0) {
            cpar--;
        } else {
            cimpar--;
        }
    }
    ans += (ll) cpar * (ll) par;
    ans += (ll) cimpar * (ll) impar;
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
