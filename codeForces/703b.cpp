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


struct plane {
	int x;
	int y;
};

vector<plane> v(1001);
ll ans, dist;

void check(int n, int x, int y) {
	if (x < 0 || y < 0) return;
	int di = 0;
	REP (i, 0, n) {
		di += abs(v[i].x - x);
		di += abs(v[i].y - y);
	}
	if (di == dist) {
		ans++;
		check(n, x, y + 1);
		check(n, x + 1, y);
		check(n, x, y - 1);
		check(n, x - 1, y);
	}
	return;
}

void solve () {
	int n;
	cin >> n;
	v.resize(n);
	int xx = 0, yy = 0;
	int x = 0, y = 0;
	REP (i, 0, n) {
		cin >> v[i].x >> v[i].y;
		xx += v[i].x;
		yy += v[i].y;
		x += (xx / n);
		y += (yy / n);
		xx %= n; 
		xx %= n; 
	}
	//x /= n;
	//y /= n;
	dist = 0;
	ans = 0;
	REP (i, 0, n) {
		dist += (ll)abs(v[i].x - x);
		dist += (ll)abs(v[i].y - y);
	}
	check(n, x, y);
	
	
	cout << ans << "\n";
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

