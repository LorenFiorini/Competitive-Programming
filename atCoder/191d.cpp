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
	ll ans = 0;
	float x, y, r;
	cin >> x >> y >> r;
	
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	int tmp = x;
	x -= (float)tmp;
	tmp = y;
	y -= (float)tmp;
	x += r; y += r;
	float rad = pow(r, 2);
	REP (i, 0, r * 2 + 1) {
		REP (j, 0, r * 2 + 1) {
			float term1 = pow((float)j - x, 2);
			float term2 = pow((float)i - y, 2);
			if (term1 + term2 <= rad) ans++;
		}
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}


