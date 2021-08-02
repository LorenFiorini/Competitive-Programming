#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int t, n;

void solve (vector<float> v) {
    set<float> z;
    set<float>::iterator it;
    int ans = 0;
    FORD(i,n,0) {
        FORD(j,i,0) {
            z.insert((v[i] - v[j]) / 2);
        }
    }
    for (it = z.begin(); it != z.end(); it++) {
        ans++;
    }
    cout << ans << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<float> v(n);
        FOR(i,0,n) cin >> v[i];
        solve(v);
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name