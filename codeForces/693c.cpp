#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORD(i, a, b) for (ll i=a-1; i>=(b); i--)
/*
ll help(vector<ll> v; vector<ll> dp, ll num, ll i) {
    if (i > num) {
        return sum;
    }

}
*/

void solve () {
    ll n;
    cin >> n;
    vector<ll> v(n+1);
    FOR (i,1,n+1) cin >> v[i];
    vector<ll> dp(n+1, 0);
    ll mx = 0;
    /*FORD(i, n+1, 1) {
        ll sum = 0;
        while (num <= n) {
            if (dp[num] != 0) {
                sum += dp[num];
            } else{
                dp[num] =  
            }

        }
        dp[i] = v[i];
    }*/
    ll ans = 0;
    FORD(i, n+1, 1){
        ll sum = 0;
        ll num = i;
        while (num <= n) {
            if (dp[num] != 0) {
                sum += dp[num];
                break;
            } else {
                sum += v[num];
                num += sum;
            }
        }
        dp[i] = sum;
        ans = max(sum, ans);
    }
    cout << ans << "\n";
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