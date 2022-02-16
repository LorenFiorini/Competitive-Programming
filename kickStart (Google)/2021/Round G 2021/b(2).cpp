#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vint;
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
#define X first
#define Y second

ll k;
ll n;

ll distance(vvi &v, pii par) {
	ll x = par.X;
	ll y = par.Y;
	ll ans = 0;
	for (vint fur : v){
		ll px = 0;
		if (x <= fur[0]) {
			px = fur[0];
		} else if (x >= fur[2]) {
			px = fur[2];
		} else {
			px = x;
		}
		ll py = 0;
		if (y <= fur[1]) {
			py = fur[1];
		} else if (y >= fur[3]) {
			py = fur[3];
		} else {
			py = y;
		}
		ans += (abs(x - px) + abs(y - py));
	}
	//show("distance");
	//show(ans);
	return ans;
}

pii bin(vvi &v, ll x, ll y) {
	pii ans = {0, 0};
	
	pii l = {0, 0};
	pii r = {0, y};
	pii dl, dr;
	while (dl.Y <= dr.Y) {
		dl = distance(v, l);
		dr = distance(v, r);
		pii mid = {0, (dl.Y + dr.Y) / 2};
		
		if (dl == dr ) {
			ans.Y = mid.Y;
			break;
		} else if (dl > dr) {
			dl = mid;
		} else {
			dr = mid;
		}
		
	}
	
	pii u = {0, 0};
	pii d = {x, 0};
	pii dd, du;
	while (dl.Y <= dr.X) {
		du = distance(v, u);
		dd = distance(v, d);
		pii mid = {(du.X + dd.X) / 2, 0};
		
		if (du == dd) {
			ans.X = mid.X;
			break;
		} else if (du > dd) {
			du = mid;
		} else {
			dd = mid;
		}
		
	}
	
	return ans;
}

void solve () {
	ll zero = 0;
	ll mx[2] = {-INF, -INF};
	
	cin >> k;
	vvi v(k, vint(4, 0));
	rep (i,0,k) {
		rep (j,0,4) {
			cin >> v[i][j];
			mx[j%2] = max(mx[j%2], v[i][j]); 
			zero = min(zero, v[i][j]);
		}
	}
	
	// make all positive
	zero = abs(zero);
	rep (i,0,k) {
		rep (j,0,4) {
			v[i][j] += zero;
		}
	}
	
	//Brute force
	pii ans = bin(v, mx[0], mx[1]);
	
	ans.X -= zero;
	ans.Y -= zero;
	
	showp(ans.X, ans.Y);
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
