#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int t, n;

void solve () {
    int ans = 0;
    vector<int> v(n);
    set<int> z;
    set<int>::iterator it;
    FOR(i,0,n) {
        cin >> v[i];
        it = z.find(v[i]);
        if (it == z.end()) {
            z.insert(v[i]);
        } else {
            z.insert(v[i] + 1);
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
        
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name