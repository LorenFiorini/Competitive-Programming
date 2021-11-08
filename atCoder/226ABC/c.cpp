#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second


void dfs(vvi &v, ll pos, vint &vis) {
	if (vis[pos]) {
		return;
	}
	vis[pos] = true;
	rep (i, 1, len(v[pos])) {
		dfs(v, v[pos][i], vis);
	}
}


void solve () {
	ll ans = 0, n;
	cin >> n;
	vvi v;
	
	rep (moves, 0, n) {
		ll t, k;
		cin >> t >> k;
		vint a(k+1, t);
		rep (i, 1, k+1) {
			cin >> a[i];
			a[i]--;
		}
		v.pb(a);		
	}
	/*
	rep (r, 0, n) {
		showv(v[r], len(v[r]));
	}*/
	vint vis(n, 0);
	
	dfs(v, n-1, vis);
	rep (i, 0, n){
		if (vis[i]) ans += v[i][0];
	}
	
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
