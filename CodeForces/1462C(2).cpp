#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int t, n;

void solve () {
    vector<int> ans;
    int sum = 0, lst = 9;
    while (sum < n && lst > 0) {
        ans.push_back(min(n - sum, lst));
        sum += lst;
        lst--;
    }
    if (sum < n) {
        cout << "-1\n";
    } else {
        reverse(ans.begin(), ans.end());
        for (int i : ans) {
            cout << i;
        }
    }
    cout << "\n";
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