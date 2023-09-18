
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 998244353
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

int H, W, K;

struct sqr {
    int h;
    int w;
    char c;
};

void numPath(vector<vector<int>>& v) {
    vector<vector<int>> (H+1, vector<int> (W+1, 0));
    if (v[1][1])
        paths[1][1] = 1;
}

void solve () {
    int ans;
    cin >> H >> W >> K;
    vector<vector<int>> mat(H+1, vector<int> (W+1, 0)); 
    //vector<srq> inf(K);
    REP (i, 0, K) 
    {
        sqr tmp;
        cin >> tmp.h >> tmp.w >> tmp.c;
        int num;
        if (tmp.c == 'R') num = 1;
        else if (tmp.c == 'D') num = 2;
        else if (tmp.c == 'X') num = 3;
        mat[tmp.h][tmp.w] = num;
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