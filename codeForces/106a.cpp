
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()


void solve () {
	int ans;
    string answer = "No";
	int n, k1, k2, w, b;
	cin >> n >> k1 >> k2;
    cin >> w >> b;

    //inpar NO
    ans = abs(k1 - k2);
    /*if (ans % 2 == 1) {
        cout << answer << "\n";
        return;
    }*/

    //white
    int mn = min (k1, k2);
    w -= mn;
    //k1 -= mn;
    //k2 -= mn;
    w -= (ans / 2);
    if (w > 0) {
        cout << answer << "\n";
        return;
    }

    //black
    int mx = max(k1, k2);
    b -= (n - mx);
    b -= (ans / 2);
    if (b > 0) {
        cout << answer << "\n";
        return;
    }

	cout << "Yes\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name
