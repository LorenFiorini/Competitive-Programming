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
#define one first
#define sz second

pair<ll, ll> fib(int n) {
	vector<vll> v(2, vll(2, 1));
	v[0][0] = 0;
	rep (i, 2, n+1) {
		ll ones = v[0][0] + v[0][1];
		ll sz = v[1][0] + v[1][1];
		// move to first
		v[0][0] = v[0][1];
		v[1][0] = v[1][1];
		// move to second
		v[0][1] = ones;
		v[1][1] = sz;
	}
	return {v[0][1], v[1][1]};
}

void solve () {
	ll n;
	cin >> n;
	pair<ll, ll> par = fib(n);
	
	ll ans = par.one;
	ll p = 1;
	while (--(par.sz)) {
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
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
