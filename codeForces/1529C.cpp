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
typedef vector<vll> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
//
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
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
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define f first
#define s second
/*
void dfs(vvi &adj, vpii &ver, ll pos, ll prev, ll &sum, vll &val) {
	if (abs(val[prev] - ver[pos].f)	> abs(val[prev] - ver[pos].s)) {
		val[pos] = ver[pos].f;
	} else {
		val[pos] = ver[pos].s;
	}
	
	sum += abs(val[pos] - val[prev]);
	
	rep (i, 0, len(adj[pos])) {
		if (val[adj[pos][i]]) continue;
		dfs(adj, ver, adj[pos][i], pos, sum, val);
	}
}*/

void dfs(vpii &ver, vvi &adj, ll pos, ll prev, vvi &dp) {
	for (ll  u : adj[pos]) {
		if (u == prev) continue;
		dfs(ver, adj, u, pos, dp);
		dp[pos][0] += max(abs(ver[pos].f - ver[u].s) + dp[u][1], abs(ver[pos].f - ver[u].f) + dp[u][0]); 
		dp[pos][1] += max(abs(ver[pos].s - ver[u].s) + dp[u][1], abs(ver[pos].s - ver[u].f) + dp[u][0]); 
	}
}

void solve () {
	ll n;
	cin >> n;
	vpii ver(n+1);
	rep (i, 0, n) {
		ll left, right;
		cin >> left >> right;
		if (!i) ver[i] = {left, right};
		ver[i+1] = {left, right};
	}
	vvi adj(n+1);
	rep (i ,0, n-1) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	/*
	ll sum, ans = 0, leaf = 0;
	rep (i, 1, n+1) {
		if (len(adj[i]) > 1) continue;
		sum = ver[i].f - ver[i].s;
		vll val(n+1, 0);
		val[0] = ver[i].s;
		dfs(adj, ver, i, 0, sum, val);
		ans = max(ans, sum);
		
		sum = ver[i].f - ver[i].s;
		fill(all(val), 0);
		val[0] = ver[i].f;
		dfs(adj, ver, i, 0, sum, val);
		ans = max(ans, sum);
		leaf++;
		if (leaf > 3) break;
	}*/
	
	vvi dp(n+1, vll (2, 0));
	
	dfs(ver, adj, 1, -1, dp);
	
	
	show(max(dp[1][0], dp[1][1]));
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

