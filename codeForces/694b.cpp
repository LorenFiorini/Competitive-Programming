#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    ll n, x;
    cin >> n >> x;
    ll ans = 0;
    //map<ll, ll> m;
    //map<ll, ll>:: iterator it;
    bool shoutoff = 0;
    vector<ll> v;
    FOR (i,0,n) {
        ll tmp, c = x;
        cin >> tmp;
        ans += tmp;
        if (tmp % x != 0) {
            shoutoff = true;
        }
        if (!shoutoff) {
            ll temp = tmp % c;
            if (temp == 0) {
                v.push_back(tmp / x);
            }
        }
    }
    ll m = v.size();
    ll ori = m;
    ll kk = 1;
    FOR (i,0,m) {
        if (i == ori) {
            ori = m;
            kk++;
        }
        ll tmp = v[i];
        ll c = x;
        ans += (tmp * pow(x, kk));
        if (tmp % x != 0) {
            shoutoff = true;
        }
        if (!shoutoff) {
            ll temp = tmp % c;
            if (temp == 0) {
                v.push_back(tmp / x);
            }
            m = v.size();
        }
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