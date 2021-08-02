#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int t, n;
string s;

/*bool checkPal(string pal) {
    int nn = pal.size();
    FOR(i, 0, nn/2) {
        if (pal[i] != pal[n-1-i]) return false;
    }
    return true;
}*/

void solve () {
    cin >> s;
    n = s.size();
    int ans = 0;
    string sub;
    string c = "0123456789.,+-*/_?;#&@{}][()"; 
    int cnt = 0, diez = c.size();
    FOR(tr,0,2){
    FOR(i, 0, n) 
    {
        FOR(j, 2, n - i + 1)
        {
            sub = s.substr(i, j);
            bool ok = true;
            //cout << sub << "\n";
            FOR(k, 0, j/2) {
                if (sub[k] != sub[j-1-k]) {
                    ok = false; break;}
            }
            if (ok) {
                int idx;
                if (j % 2 == 0) {
                    idx = i + j / 2 + 0;
                } else {
                    idx = i + j / 2 + 1;
                }
                s[idx] = c[cnt]; cnt++; cnt%=diez;
                ans++;
                //i = idx - 1;
            }
        }
    }}
    cout << ans << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name