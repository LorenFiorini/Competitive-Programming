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
typedef map<int,int> mpii;
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

ll N = 3001;
vll sq(N);

void help() {
	rep(i, 0, N) {
		sq[i] = i*i;
	}
}

void solve () {
	ll ans = 0;
	ll n, q, x, y, id;
	cin >> n;
	vll row(N, 0);
	vll col(N, 0);

	rep (k, 0, n) {
		cin >> x;
		id = 0;
		while (x + id < N) {row[x + id] += sq[id]; id++;}
		id = 0;
		while (x - id >= 0) {row[x - id] += sq[id]; id++;}

		cin >> x;
		id = 0;
		while (x + id < N) {col[x + id] += sq[id]; id++;}
		id = 0;
		while (x - id >= 0) {col[x - id] += sq[id]; id++;}

	}

	rep (i, 0, N) {
		row[i] %= mod;
		col[i] %= mod;
	}
	
	cin >> q;
	while (q--) {
		cin >> x >> y;
		ans += (row[x] + col[y]);
		ans %= mod;

	}
	cout << ans << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();

	int T; 
	cin >> T; 
	for (int C = 1; C <= T; C++) {
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
