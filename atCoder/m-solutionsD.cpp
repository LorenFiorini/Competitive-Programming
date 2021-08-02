#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

ll t, n;

void solve () {
    vector<ll> v(n);
    FOR(i, 0, n) cin >> v[i];
    //int with = -2e9, without = 1000;
    ll ans = 1000;
    FOR (i, 1, n) {
        if (v[i] > v[i-1]) {
            ll tmp = ans / v[i-1];
            ans += tmp * (v[i] - v[i-1]);
        }
    }
    cout << ans << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    solve();
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name