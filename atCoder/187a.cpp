#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORD(i, a, b) for (int i=a-1; i>=(b); i--)

int t, a,b;

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans;
    cin >> a >> b;
    int suma = 0, sumb = 0;
    while (a > 0) {
        suma += (a % 10);
        sumb += (b % 10);
        a /= 10;
        b /= 10;
    }
    ans = max(suma, sumb);
    cout << ans;
    return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name