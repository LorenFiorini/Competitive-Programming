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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "\n";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

int MX = 1e3 + 1;
vint to(MX, 1e9);

void make() {
	to[1] = 0;
	
	rep (i, 1, MX) {
		rep(j, 1, i+1) {
			int p = i + i/ j;
			if (p > 1e3) break;
			to[p] = min(to[p], to[i] + 1);
		}
	}
}
ll n, k;

void dfs(vint &a, vint &b, vint &c, ll &ans,, ll cnt int p) {
	
	if (p == n) {
		ans = max(ans, p);
		return;
	}
	
	if (to[p] < 1e9) {
		
	}
}

void solve () {
	// Maximum number of coins c[i]
	ll ans = 0;
	
	cin >> n >> k;
	// turn a[i] into b[i] using at most k
	vint b(n);
	rep(i, 0, n) cin >> b[i];
	vint c(n);
	rep(i, 0, n) cin >> c[i];
	
	vint a(n, 1);
	
	dfs(a,b,c, ans, cnt, 0);
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	make();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
