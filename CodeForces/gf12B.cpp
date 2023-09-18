#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int t, n, k;

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<int>> xy(n, vector<int> (2));
        FOR (i, 0, n){
            cin >> xy[i][0] >> xy[i][1];
        }
        //________________________
        int ans = n;
        vector<vector<int>> dist(n, vector<int> (n));
        int d;
        FOR (i, 0, n)
        {
            bool tooFar = true;
            FOR (j, 0, n)
            {
                d = abs(xy[i][0] - xy[j][0]) + abs(xy[i][1] - xy[j][1]);
                if (d <= k) {
                    dist[i][j] = d;
                    if (i!=j) tooFar = false;
                } else {
                    dist[i][j] = d;
                } 
            }
            if (tooFar) {
                ans = -1;;
                break;
            }
        }
        if (ans != -1){
        do 
        {
            int charged = 0;
            vector<int> pl(n, 1);
            FOR (i, 0, n) 
            {
                if (pl[i] == 1) {
                    charged++;
                    FOR (j, 0, n) 
                    {
                        //cout << dist[i][j];
                        // distance lesthan or equal to k
                        if (dist[i][j] <= k && dist[i][j] > 0) {
                            pl[j] = 0;
                        }
                    }

                    //cout << "\n";
                }
            }
            // cout << charged << "\n";
            int nok = 0;
            //check if more thn one point;
            FOR (i, 0, n){
                if (pl[i]) ++nok;
            }
            if (nok == 1){
                ans = min(ans, charged);
            }
            FOR(k,0,n) {
                next_permutation(dist[k].begin(), dist[k].end());
            }
        } while(next_permutation(dist.begin(), dist.end()));
        }
        if (ans==n) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name