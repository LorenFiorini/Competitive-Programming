#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORD(i, a, b) for (ll i=a-1; i>=(b); i--)

/*
2
3 3
3 6 9
3 3
6 4 11
*/

void solve () {
    ll ans;
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    ll tog = 0, sep = 0;
    ll min = 0;
    FOR(i,0,n) {
        cin >> v[i];
        tog += v[i];
        sep += ceil((double)v[i] / x);

        min += tog / x;
        tog %= x;        
    }
    tog = ceil((double) tog / x);
    tog += min;
    cout << tog << " " << sep << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name