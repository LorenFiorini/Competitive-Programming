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

ll ans, dist;
vector<int> vx(1001);
vector<int> vy(1001);
set<int> st;
set<int> :: iterator it;

void check(int n, int x, int y) {
	if (x < 0 || y < 0) return;
	int xy = x * 10 + y;
	it = st.find(xy);
	if (it == st.end()) {
		st.insert(xy);
	} else return;
	int di = 0;
	REP (i, 0, n) {
		di += abs(vx[i] - x);
		di += abs(vy[i] - y);
	}
	if (di == dist) {
		ans++;
		check(n, x, y + 1);
		check(n, x + 1, y);
		check(n, x, y - 1);
		check(n, x - 1, y);
		check(n, x + 1, y + 1);
		check(n, x + 1, y - 1);
		check(n, x - 1, y + 1);
		check(n, x - 1, y - 1);
	}
	return;
}

void solve () {
	int n;
	cin >> n;
	vx.resize(n);
	vy.resize(n);
	st.clear();
	int xx = 0, yy = 0;
	int x = 0, y = 0;
	REP (i, 0, n) {
		cin >> vx[i] >> vy[i];
		xx += vx[i];
		yy += vy[i];
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
		dist += (ll) abs(vx[i] - x);
		dist += (ll) abs(vy[i] - y);
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


