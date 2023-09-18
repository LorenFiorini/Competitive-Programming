
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

struct val {
    int total;
    int value;
    int mn;
    int mx;
};


void solve () {
    int ans;
    int n, m;
    cin >> n >> m;
    vector<val> v(n + 1); 
    v[0].value = 0; v[0].mn = 0; v[0].mx = 0; v[0].total = 0;
    string s;
    cin >> s;
    REP (i, 1, n + 1) {
        // s [i - 1]
        if (s[i - 1] == '+') {
            v[i].value = (1);
        } else {
            v[i].value = (-1);
        }
        v[i].total = v[i - 1].total + v[i].value;
        v[i].mn = min(v[i].total, v[i-1].mn);
        v[i].mx = max(v[i].total, v[i-1].mx);
    }
    int l, r;
    while (m--) {
        cin >> l >> r;
        int tmp = v[l - 1].total;
        int tmx = v[l - 1].mx;
        int tmn = v[l - 1].mn;
        //cout << tmn;
        for (int i = r + 1; i <= n; i++) {
            tmp += v[i].value;
            tmx = max(tmx, tmp);
            tmn = min(tmn, tmp);
        }
        //cout <<  "\n" << tmx << "   " <<tmn << "\n";
        ans = tmx - tmn + 1;
        cout << ans << "\n";
    }

    //cout << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name