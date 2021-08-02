#include <bits/stdc++.h>
using namespace std;

void solve () 
{
    string ans = "0123456789";
    string stopTheSecondAt8 = "989";
    int n;
    cin >> n;
    for (int i = 0, j = 0; i < n; i++){
        if (i < 3) {
            cout << stopTheSecondAt8[i];
            continue;
        } 
        cout << ans[j];
        j++;
        j %= 10;
    }
    cout << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}