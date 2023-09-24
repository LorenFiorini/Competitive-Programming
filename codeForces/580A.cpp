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
    ll n, cur, last = 0, ans = 0, seq = 0;
    cin >> n;
    FOR (i, 0, n) {
        cin >> cur;
        if (cur >= last) seq++;
        else {
            seq = 1;
        }
        ans = max(ans, seq);
        last = cur;
    }
    cout << ans << '\n';
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name