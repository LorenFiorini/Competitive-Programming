#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD 1000000007
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

struct day 
{
    ll a;
    ll b;
    ll c;
};

bool diaSort (day const& a, day const& b) {
    if (a.a < b.a)
    return true;
    else 
    return false;
}

void solve () 
{
    ll ans = 0;
    ll n, premium;
    cin >> n >> premium;
    vector<day> dia(n);
    FOR (i, 0, n) {
        cin >> dia[i].a >> dia[i].b >> dia[i].c;
        ans += (dia[i].b - dia[i].a + 1) * dia[i].c; //TOTAL no premium
    } // dont know why +1 up here (0-index, include last day)
    sort(dia.begin(), dia.end(), &diaSort);
    map<ll, int> mp;
    map<ll, int>:iterator it;
    FOR (i, 0, n) {
        //write your code here :)
        //or elsewhere
        //cause this is a mess
    }
    /*FOR (i, 0, n) {
        cout << dia[i].a << "  " <<dia[i].b << "  "<<dia[i].c<<"\n" ;
    }*/

    cout << ans << "\n";
}

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name