#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int t, n;
string s;

void solve () {
    string year = "2020";
    int b=0, e=0;
        if (s[0] == '2'){
            FOR(j,0,4){
                if(year[j] == s[j]) b++;
                else break;
            }
        }
        if (s[n-1] == '0'){
            FOR(j,0,4){
                if(year[4-1-j] == s[n-1-j]) e++;
                else break;
            }
        }
    if(b+e >= 4) {
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name