#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int t;
string s;

void solve () {
    int n = s.size();
    if (n % 2 || s[0] == ')' || s[n-1] == '(') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;

        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name