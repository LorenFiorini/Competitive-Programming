#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    ll n;
    cin >> n;
    ll a = 0, b = 0;
    vector<ll> v(n);
    FOR(i,0,n) cin >> v[i];
    sort(v.begin(), v.end(), greater<>());
    FOR(i,0,n) {
        if (i % 2 == 0) {
            if (v[i] % 2 == 0) a += v[i];
        } else {
            if (v[i] % 2 == 1) b += v[i];
        }
    }
    if (a == b) {
        cout << "Tie\n";
    } else if (a > b) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    return;
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name