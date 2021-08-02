#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

ll t, n, k;


int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll mx = 2 * k - 1;
        vector<ll> h(n);
        bool cot = false;
        FOR (i, 0, n) {
            cin >> h[i];
            if (i > 0 && !cot) {
                if (i == 1) {
                    if (n==2) {
                        if (k + h[i] <= h[i-1] || h[i] >= h[i-1] + k) {
                        cout << "NO\n";
                        cot = true;
                    }
                    }
                    if (mx + h[1] <= h[0] || h[1] >= h[0] + k) {
                        cout << "NO\n";
                        cot = true;
                    }
                } 
                else if (i == n - 1) {
                    if (k + h[i] <= h[i-1] || h[i] >= h[i-1] + mx) {
                        cout << "NO\n";
                        cot = true;
                    }
                }
                else if (h[i] >= h[i-1] + mx || h[i] + mx <= h[i-1]) {
                    cout << "NO\n";
                    cot = true;
                }
            }
        }
        if(!cot)
        cout << "YES\n";
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name