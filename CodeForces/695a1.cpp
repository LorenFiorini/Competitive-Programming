
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    string ans = "9876543210";
    string san = "123456789";
    int j = 0;
    int n;
    cin >> n;
    string as;
    if (n > 0) {
        int r = n % 10;
        n /= 10;
        while (n > 0) {
            as += ans;
            n--;
        }
        string tmp;
        FOR(i,0,r) tmp.push_back(ans[i]);
        as += tmp;
    }

    cout << as << "\n";
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