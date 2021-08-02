#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int t, n, m;

void solve (vector<int> r, vector<int> b) {
    vector<vector<int>> ans(n + 1, vector<int> (m + 1, 0));
    FOR(i, 0, n+1) {
        FOR(j, 0, m+1) {
            if (i+j == 0) continue;
            if (!i)ans[i][j] = ans[i][j-1] + b[j];
            else ans[i][j] = ans[i-1][j] + r[i];
        }
    }
    int mx = 0;
    FOR(i, 0, n+1) {
        FOR(j, 0, m+1) {
            mx = max(mx, ans[i][j]);
        }
    }
    cout << mx << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> r(n+1);
        r[0] = 0;
        FOR(i, 1, n+1) cin >> r[i];
        cin >> m;
        vector<int> b(m+1);
        b[0] = 0;
        FOR(i, 1, m+1) cin >> b[i];
        solve(r, b);
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name