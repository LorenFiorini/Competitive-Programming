#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define mod (ll) 1000000007
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

void fib(vll &f, vll &sz, int n) {
	f[1] = 1;
	rep (i, 2, n+1) {
		f[i] = f[i-1] + f[i-2];
		sz[i] = sz[i-1] + sz[i-2];
	}
}

void solve (ll ans, ll n) {
	ll p = 1;
	while (--n) {
		p <<= (ll) 1;
		p %= mod;
	}
	
	ans *= p;
	ans %= mod;
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, mx = 0; 
	cin >> t;
	vpii nums(t);
	rep (i, 0, t) {
		cin >> nums[i];
		mx = max(mx, nums[i]);
	}
	
	vll f(mx+1, 0);
	vll sz(mx+1, 1);
	fib(f, sz, mx);
	
	rep (i, 0, t) {
		solve(f[nums[i]], sz[nums[i]]);
	}
	
	return 0;
}

// Lorenzo Fiorini
