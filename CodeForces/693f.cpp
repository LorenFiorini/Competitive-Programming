#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    ll n, m;
    cin >> n >> m;
    int ans, r, c;
    vector<vector<ll>> v(2, vector<ll> (n, 1));
    FOR(i,0,m) {
        cin >> r >> c;
        v[r-1][c-1] = 0;
    }
    FOR(i,0,2) {
        FOR(j,0,n) {
            if (v[i][j] == 1) {
                if (j+1 < n == 1) {
                    if (v[i][j+1]) {
                        v[i][j] = 0;
                        v[i][j+1] = 0;
                    }
                }else if (i+1 < 2) {
                        if (v[i+1][j] == 1) {
                        v[i][j] = 0;
                        v[i+1][j] = 0;
                    }
                }
            }
        }
    }FOR(i,0,m) {
        FOR(j,0,2) {
            if (v[i][j] == 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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