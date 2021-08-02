
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
    //
    int m = pow(2, n);
    //vector<int> v(m);
    int ti, ls;
    vector<int> vec(m); // was m / 2
    map<int, int> mapa;
    map<int, int>::iterator it;
    FOR(i,0,m) 
    {
        if (i) ls = ti; // pass
        cin >> ti;
        it = mapa.find(ti);
        if(it == mapa.end()) mapa.insert({ti, i}); // mapa
        vec[i] = ti;
        /*if (i % 2 == 1) {
            vec[i/2] = max(ti, ls);
        }*/
    }
    int tam = vec.size();
    while (true) 
    {
        FOR(i, 1, tam) {
            vec[i / 2] = max(vec[i], vec[i-1]);
        }
        tam /= 2; // mazbe divide by 2
        if (tam == 2) {
            it = mapa.find(min(vec[0], vec[1]));
            ans = it->second + 1;
            break;
        }
    }

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