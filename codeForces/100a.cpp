
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
    int a,b,c;
    SCd(a); SCd(b); SCd(c);
    int tot = a+b+c;
    if (tot % 9 != 0 || tot < 9) {
        cout << "No\n";
        return;
    }
    int k = tot / 9;
    if (min(a, min(b, c)) < k) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; SCd(t);
    while (t--) solve();
    
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name