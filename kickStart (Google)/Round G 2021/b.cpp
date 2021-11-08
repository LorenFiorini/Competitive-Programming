#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

int k;
int n = 201;

int distance(vvi &v, int x, int y) {
	int ans = 0;
	for (vint fur : v){
		int px = 0;
		if (x <= fur[0]) {
			px = fur[0];
		} else if (x >= fur[2]) {
			px = fur[2];
		} else {
			px = x;
		}
		int py = 0;
		if (y <= fur[1]) {
			py = fur[1];
		} else if (y >= fur[3]) {
			py = fur[3];
		} else {
			py = y;
		}
		ans += (abs(x - px) + abs(y - py));
	}
	return ans;
}

void solve () {
	cin >> k;
	vvi v(k, vint(4, 0));
	rep (i,0,k) {
		rep (j,0,4) {
			cin >> v[i][j];
			v[i][j] += 100;
		}
	}
	
	//Brute force
	int dis = INF;
	int ans[2] = {0,0};
	
	rep (i, 0, n) {
		rep (j ,0, n) {
			int D = distance(v, i, j);
			if (D < dis) {
				dis = D;
				ans[0] = i;
				ans[1] = j;
			}
		}
	}
	ans[0] -= 100;
	ans[1] -= 100;
	
	showp(ans[0], ans[1]);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
