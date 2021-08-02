#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> v(n);
    int a = 0, b = 0;
    FOR (i,0,n) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            if (a<b) a += 2;
            else b += 2;
        } else
        sum += v[i];
    }
    if (a != b) {
        if (sum > 0 && sum % 2 == 0)
            cout << "YES\n";
        else 
            cout << "NO\n";
    } else {
        if (sum % 2 == 0)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return;
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