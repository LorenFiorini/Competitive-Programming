#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

ll n;

void solve () {
    int ans = 0;
    ll tmp;
    while (n != 0) 
    {
        tmp = n;
        ll mx = 0;
        while (tmp > 0) {
            mx = max(mx, tmp%10);
            tmp /= 10;
        }
        n -= mx;
        ans++;
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