
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

int prime[8] = {2, 3, 5, 7, 11, 13, 17, 19};

void solve () {
    int ans;
    string s; string t;
    cin >> s >> t;
    int sn = s.size();
    int tn = t.size();
    int mcd = 1;
    while (sn > 1 || tn > 1) {
        REP(i, 0, 8) {
            if (sn % prime[i] == 0 || tn % prime[i] == 0) {
                if (sn % prime[i] == 0) sn /= prime[i];
                if (tn % prime[i] == 0) tn /= prime[i];
                mcd *= prime[i];
            }
        }
    }
    sn = s.size();
    tn = t.size();
    REP (i, 0, mcd) {
        if (s[i % sn] != t[i % tn]) {
            cout << "-1\n";
            return;
        }
    }
    while (mcd > 0) {
        cout << t;
        mcd -= tn;
    }
    cout << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c; cin >> c;
    while (c--) solve();
    
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name