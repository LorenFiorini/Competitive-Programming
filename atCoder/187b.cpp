#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

struct coor {
    float x;
    float y;
};
void solve () {
    int n;
    cin >> n;
    vector<coor> v(n);
    int ans = 0;
    FOR (i, 0, n) {
        cin >> v[i].x >> v[i].y;
    }
    FOR (i, 0, n) {
        FOR (j, i, n) {
            if (i != j) {
                float tmp = (v[i].y - v[j].y) / (v[i].x - v[j].x);
                if (tmp >= -1 && tmp <= 1)
                    ans++; 
            }
        }
    }
    //ans /= 2;
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