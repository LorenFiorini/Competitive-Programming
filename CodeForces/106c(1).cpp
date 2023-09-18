
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
    vector<ll> par(n % 2 == 0 ? n / 2 : n / 2 + 1);
    vector<ll> impar(n / 2);
    vector<ll> cpar(n % 2 == 0 ? n / 2 : n / 2 + 1);
    vector<ll> cimpar(n / 2);
    REP (i, 0, n) {
        if (i % 2 == 0) {
            cin >> par[i / 2];
        } else {
            cin >> impar[i / 2];
        }
    }
    ll spar = 0;
    ll simpar = 0;

    REP (i, 0, n) {
        if (i % 2 == 0) {
            if (i == 0) {
                cpar[0] = n * par[0];
            } else {
                cpar[i / 2] = min(cpar[i/2 - 1], spar + par[i/2] * (n - (i/2)));
            }
            spar += par[i / 2];
        } else {
            if (i == 1) {
                cimpar[0] = n * impar[0];
            } else {
                cimpar[i / 2] = min(cimpar[i/2 - 1], simpar + impar[i/2] * (n - (i/2)));
            }
            simpar += impar[i / 2];
        }
    }
    ans += (ll) cimpar[n / 2 - 1];
    ans += (ll) cpar[n % 2 == 0 ? n/2 - 1: n / 2];
    
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
