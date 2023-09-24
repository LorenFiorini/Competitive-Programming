#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    ll n, w, h;
    cin >> w >> h >> n;
    ll ans = 1;
    while (true) {
        if (w % 2 == 0) {
            w /= 2;
            ans *= 2;
        } else if (h % 2 == 0) {
            h /= 2;
            ans *= 2;
        } else 
            break;
    }
    if (ans >= n)
        cout << "YES\n";
    else
        cout << "NO\n";

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