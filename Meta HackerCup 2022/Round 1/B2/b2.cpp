#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll, ll> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
//
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)  
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i];} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second


void solve () {
	ll ans = 0;
	ll n, q, x, y, dis;
	mpii row; mpii col;

	// INPUT
	cin >> n;
	vvi v(n, vint(2));
	rep (i, 0, n) cin >> v[i][0] >> v[i][1];
	cin >> q;
	vvi a(q, vint(2));
	rep (i, 0, q) {
		cin >> a[i][0] >> a[i][1];
		row[a[i][0]] = 0;
		col[a[i][1]] = 0;
	}

	// computng
	each (it, row) {
		rep (i, 0, n) {
			dis = abs(v[i][0] - it->ff);
			it->ss += dis * dis;
			it->ss %= mod;
		}
	}

	each (it, col) {
		rep (i, 0, n) {
			dis = abs(v[i][1] - it->ff);
			it->ss += dis * dis;
			it->ss %= mod;
		}
	}

	rep (i, 0, q) {
		dis = (row[a[i][0]] + col[a[i][1]]) % mod;
		ans += dis;
		ans %= mod;
	}

	cout << ans << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int T; 
	cin >> T; 
	for (int C = 1; C <= T; C++) {
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
