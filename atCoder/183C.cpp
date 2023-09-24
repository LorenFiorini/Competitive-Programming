#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int k, n;

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int> (n));
    FOR (i, 0, n) {
        FOR (j, 0, n){
            cin >> t[i][j];
        }
    }
    vector<int> v(n, 0);
    //greek leter iota
    iota(v.begin(), v.end(), 0);
    int ret = 0;
    do {
        if (v[0] != 0) continue;
        ll tmp = t[v.back()][0];
        FOR (i, 0, n - 1) {
            tmp += t[v[i]][v[i + 1]]; 
        }
        ret += (tmp == k);
    } while (next_permutation(v.begin(), v.end()));
    cout << ret << '\n';
    return 0;
}