#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
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
#define x first
#define y second
ll b, k;

ll UP(ll y) {
	return k * (b - (y % b));
}
ll DOWN(ll y) {
	return k * (y % b);
}
ll RI(ll x) {
	return k * (b - (x % b));
}
ll LE(ll x) {
	return k * (x % b);
}
vpii points(ll x, ll y) {
	vpii A(4);
	A[0] = {x, UP(y)};
	A[1] = {x, DOWN(y)};
	A[2] = {LE(x), y};
	A[3] = {RI(x), y};
	return A;
}

ll distance(pii s, pii t) {
	ll ans = 0;
	// s.y % b or 
	// kB - dy = s.y
	//ll row = b - (s.y % b) + 
	//if ( t.y - s.y < b) 
	return t.x - s.x + t.y - s.y;
	//return ans;
}

void solve () {
	ll ans = 0;
	
	cin >> b >> k;
	pii s;	cin >> s.x >> s.y;
	pii t;	cin >> t.x >> t.y;
	if (t.x < s.x) swap(t.x, s.x);
	if (t.y < s.y) swap(t.y, s.y);
	// start
	ans = k * (t.x - s.x + t.y - s.y);
	// != square -> move to nearest road
	
	// points to right and up 
	vpii A = points(s.x, s.y);
	vpii B = points(t.x, t.y);

	rep(i, 0, 4) {
		rep(j, 0, 4) {
			ll d = distance(A[i], B[j]);
			d += k * (abs(s.x - A[i].x) + abs(s.y - A[i].y));
			d += k * (abs(t.x - B[j].x) + abs(t.y - B[j].y));
			ans = min (ans, d);
		}
	}

	show(ans);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
