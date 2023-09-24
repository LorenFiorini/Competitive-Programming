
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    ll ans = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) {
        ll tmp;
        cin >> tmp;
        a[i] *= tmp;
        ans += a[i];
    }
    if(ans==0)
    cout << "Yes\n";
    else 
    cout << "No\n";
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