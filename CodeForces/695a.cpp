#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)
//BBB

void solve () {
    int ans = 0;
    int n;
    cin >> n;
    vector<int> v(n, 0);
    vector<int> a(n);
    FOR (j,0,n) {
        cin >> a[j];
    }
    FOR(i,1,n-1) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) {
            v[i]++;
            v[i-1]++;
            v[i+1]++;
            ans++;
        } else if (a[i] < a[i-1] && a[i] < a[i+1]) {
            v[i]++;
            v[i-1]++;
            v[i+1]++;
            ans++;
        }
    }
    int mn = 0;
    FOR (i,0,n) {
        if (mn == 3) break;
        mn = max(mn, v[i]);
    }
    ans -= mn;
    if (ans<0) ans = 0;
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