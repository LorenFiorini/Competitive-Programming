#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n;
    cin >> n;
    int ans = 20;
    int k = n.size();
    FOR (i, 1, 1 << k) {
        int num = 0;
        int sum = 0;
        FOR (j, 0, k) {
            if (i >> j & 1) {
                num++;
                sum += n[j] - '0';
            }
        }
        if (sum % 3 == 0) {
            ans = min(ans, k - num);
        }
    }
    if (ans == 20) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}