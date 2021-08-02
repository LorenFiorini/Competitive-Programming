#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

struct voters {
    ll a;
    ll b;
    ll total;
};

void quick(vector<voters> v, int low, int high) {
    if (low < high) {
        voters pi = partition(v.total, low, high);
        quick(v.total low, pi - 1);
        quick(v.total, pi+1, high);
    }
}


void solve () {
    ll n;
    cin >> n;
    vector<voters> v(n);
    ll ans = 0;
    ll sumA = 0, sumT = 0;
    FOR (i, 0, n) {
        cin >> v[i].a >> v[i].b;
        v[i].total = v[i].a + v[i].b;
        sumA += v[i].a;
    }
    /*FOR(i, 0, n-1) {
        FOR (j, 0, n-1-i) {
            if (v[j].total < v[j+1].total) {
                voters tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }*/
    quick(v.total, 0, n-1);
    

    while (sumA >= sumT) {
        sumT += v[ans].total;
        sumA -= v[ans].a;
        ans++;
    }
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