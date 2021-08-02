
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)


void solve () {
    int ans;
    int n;
    cin >> n;
    int mx1 = 0, mx2 = 0;
    int nnn = pow(2, n);

    map<int, int> mapa;
    map<int, int>::iterator it;
    FOR (i, 0, nnn) 
    {
        int tmp;
        cin >> tmp;
        it = mapa.find(tmp);
        if(it == mapa.end()) mapa.insert({tmp, i});
        //______________________________
        if (i < nnn / 2) {
            mx1 = max(mx1, tmp);
        } else {
            mx2 = max(mx2, tmp);
        }
        it = mapa.find(tmp);
        if(it == mapa.end()) mapa.insert({tmp, i});
    }
    it = mapa.find(min(mx1, mx2));
    ans = it->second + 1;
    cout << ans << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    solve();
    
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name