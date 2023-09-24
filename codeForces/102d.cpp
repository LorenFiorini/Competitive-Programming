
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
    int ans;
    int n, m;
    cin >> n >> m;
    vector<int> values(n + 1, 0); 
    string s;
    cin >> s;
    REP (i, 0, n) {
        int tmp = -1;
        if (s[i] == '+') tmp = 1;
        values[i + 1] = values[i] + tmp;
    }
    int l, r;
    while (m--) 
    {
        cin >> l >> r;
        set<int> z;
        set<int>::iterator it;
        bool before = true;
        int last = values[l - 1];
        REP (i, 0, n + 1) 
        {
            if (i == l) {
                i = r;
                before = false;
                continue;
            }
            //insert different
            if (before){
                it = z.find(values[i]);
                if (it == z.end())
                    z.insert(values[i]);
            } else {
                int tmp = -1;
                if (s[i - 1] == '+') tmp = 1; // correct +1 val
                last += tmp;
                it = z.find(last);
                if (it == z.end())
                    z.insert(last);
            }
        }
        ans = z.size();
        cout << ans << "\n";
    }
    cout << "\n";
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