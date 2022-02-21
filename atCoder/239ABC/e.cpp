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

vint dfs(vvi &adj, vint &val, vvi &v, int pos, vint &vis) {
	vis[pos] = true;
	
	vint ans(1, val[pos]);
	for (int nxt : adj[pos]) {
		if (not vis[nxt]) {
			vint sub = dfs(adj, val, v, nxt, vis);
			
			for (int a : sub) {
				ans.pb(a);
			}
		}
	}
	v[pos] = ans;
	//show("");
	//show(pos);
	//showv(ans, len(ans));
	return ans;
}

void solve () {
	int n, q;
	cin >> n >> q;
	vint val(n);
	rep(i, 0, n) cin >> val[i];
	
	vvi adj(n);
	rep(i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vvi v(n);
	vint vis(n, 0);
	dfs(adj, val, v, 0, vis);
	
	// sort
	rep(i, 0, n) {
		sort(allg(v[i]));
		//showv(v[i], len(v[i]));
	}
	
	while (q--) {
		int ver, k;
		cin >> ver >> k;
		ver--; k--;
		
		int ans = v[ver][k];
		show(ans);
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
