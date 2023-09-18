
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define SCd(t) scanf("%d",&t)
#define SClld(t) scanf("%lld",&t)
#define SCc(t) scanf("%c",&t)
#define SCs(t) scanf("%s",t)
#define SClf(t) scanf("%lf",&t) //double
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
    ll ans = 0;
    int n, k, kk = 0;
    cin >> n >> k;
    int zeroes = 0;
    vector<vector<int>> v(n, vector<int> (k, 0));

    REP (i, 0, n) 
    {
        int tmp;
        cin >> tmp;
        bool ok = false;
        int j = 0;
        while (j < k) {
            if (v[tmp][j] == 0) {
                v[tmp][j] = 1;
                break;
            }
            j++;
            kk = j > kk ? j : kk;
        }
    }
    REP (j, 0, kk + 1) {
        ll mxC = 0;
        REP (i, 0, n) {
            if (v[i][j] != 1) {
                break;
            } else {
                mxC++;
            }
        }
        ans += mxC;
    }

    cout << ans << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //int t; cin >> t;
    //while (t--) 
    solve();
    
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name