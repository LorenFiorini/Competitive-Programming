#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<b; i++)
#define FORD(i, a, b) for (int i=a-1; i>=b; i--)

int t, n;
vector<ll> ans(51, 223456789);

/*
void solve () {
    if(ans[n]) {
        cout << ans << "\n";
        return;
    }
    
    
    cout << "-1\n";
}*/

int main () 
{
    FOR(k,1,46){
for (ll i=0; i<123456790; i++) {
    string tmp = to_string(i);
    ll sum= 0;
    set<ll> r;
    FOR(j,0,tmp.size()){
        if (r.find(tmp[j]) == r.end()){
            r.insert(tmp[j]);
        } else {
            sum=0;
            break;
        }
        sum += tmp[i];
    }
    if (sum == k) ans[k] = min(ans[k], sum);
}}
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if(n>=46){
        cout << "-1\n";
        continue;
        }
        cout << ans[n] << "\n";
        //olve();
    }
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name