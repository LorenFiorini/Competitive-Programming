
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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

struct truck {
    ll mx;
    //ll mn;
};

void solve () {
    //ll ans;
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    REP (i, 1, n + 1) {
        ll tmp;
        cin >> tmp;
        a[i] = max(a[i-1], tmp);  
        //a[i].mn = min(a[i-1].mn, tmp);  
    }
    //vector<truck> b(n + 1, 0);
    ll bmx = 0;
    ll sf = 0;
    REP (i, 1, n + 1) {
        ll tmp;
        cin >> tmp;
        //bmx = tmp > bmx ? tmp : bmx;
        //b[i].mx = max(b[i-1].mx, tmp);  
        //b[i].mn = min(b[i-1].mn, tmp); 
        ll th = a[i] * tmp;
        sf = th > sf ? th : sf;
        cout << sf << "\n";
    }
    //cout << ans << "\n";
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
