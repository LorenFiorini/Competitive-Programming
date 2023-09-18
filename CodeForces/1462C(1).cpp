#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int t, n;

void solve () {
    vector<int> ans(45);
    if(n<=18){
    FOR(i,0,10){
        FOR(j,0,10){
            if(i==j) continue;
            if(i+j==n){
                if(i)
                cout << i << j <<"\n";
                else
                cout << j <<"\n";
                return;                
            }
        }
    }}
    
    cout << "-1\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;

        solve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name