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
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define x first
#define y second

void solve () {
	int W, H;
	cin >> W >> H;
	pii a;
	pii b;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	int w, h;
	cin >> w >> h;
	
	int alt = h + b.y - a.y;
	int anc = w + b.x - a.x;
	if (alt > H and anc > W) {
		show(-1);
		return;
	}
	
	//=========
	
	double ans = 0;
	double dx = 0;
	double dy = 0;
	// cuadrados mas grandes
	int X = max(a.x, W - b.x);
	int Y = max(a.y, H - b.y);
	
	if (X >= w or Y >= h) {
		// Nada ya entra
		if(Y < h)dy = h - Y;
		if (X < w)dx = w - X;
	} else if (X < w and Y < h) {
		if (anc > W) {
			dy = h - Y;
		} else if (alt > Y) {
			dx = w - X;
		} else {
			dy = h - Y;
			dx = w - Y;
		}
	}
	
	ans = sqrt(dx*dx + dy*dy);
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	precision(8);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
