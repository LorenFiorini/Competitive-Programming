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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

ll ans, n, x;
map<pii, ll> mp;


ll dfs(vll &v, int l, int r, ll cost, ll k) {

	// END conditions
	if (l == r) {
		cost += v[r];
		ans = min(ans, cost);
		if (mp.find({l, r}) == mp.end()) 
			mp[{l, r}] = cost;
		else
			mp[{l, r}] = min(mp[{l, r}], cost);
			
		return cost;
	} else if (l > r) {
		ans = min(ans, cost);
		if (mp.find({l, r}) == mp.end()) mp[{l, r}] = cost;
		else mp[{l, r}] = min(mp[{l, r}], cost);
		return cost;
	}
	
	ll best = 1e18;
	// Take out both
	if (k > 0 && v[l]+v[r] <= x) {
		best = min(dfs(v, l+1, r-1, cost + x, k-1), best);
	}
	
	// LEFT
	best = min(dfs(v, l+1, r, cost + v[l], k), best);
	// RIGTH
	best = min(dfs(v, l, r-1, cost + v[r], k), best);
	
	if (mp.find({l, r}) == mp.end()) mp[{l, r}] = cost;
	else mp[{l, r}] = min(mp[{l, r}], cost);
	
	return best;
}

void solve () {
	ans = 1e18;
	mp.clear();
	ll n, k, x;
	cin >> n >> k >> x;
	vll v(n);
	rep (i,0,n) cin >> v[i];
	
	int l = 0;
	int r = n-1;
	dfs(v, l, r, 0, k);
	
	show(ans / 2);
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
