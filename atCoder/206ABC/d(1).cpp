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
typedef map<ll, ll> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
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
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;


ll n;

ll dfs(vll &v, ll pos, mpii mp) {
	if (pos >= n / 2) return 0;
	mpii :: iterator it;
	
	//show("Mapa");
	//showmap(it, mp);
	
	// Check if changed
	ll a = v[pos];
	it = mp.find(a);
	while (it != mp.end()) {
		a = it->ss;
		it = mp.find(a);
	}
	ll b = v[n-1-pos];
	it = mp.find(b);
	while (it != mp.end()) {
		b = it->ss;
		it = mp.find(b);
	}
	
	// SUM NEW WAYS
	ll ways = 0;
	if (a == b) {
		ways += dfs(v, pos+1, mp);
	} else {
		// sumar un cambio && add num to map
		ways = 1;
		mp[a] = b;
		ways += dfs(v, pos+1, mp);
	}
	
	return ways;
}



void solve () {
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];
	
	
	mpii mp;
	ll ans = dfs(v, (ll) 0, mp);
	
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
