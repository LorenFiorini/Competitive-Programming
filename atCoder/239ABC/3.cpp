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

void dfs(vvi &adj, vvi &v, int pos, vector<bool> &vis) {
	
	for (int nxt : adj[pos]) {
		if (not vis[nxt]) {
			vis[pos] = true;
			dfs(adj,  v, nxt, vis);
			
			for (int a : v[nxt]) {
				v[pos].pb(a);
			}
		}
	}
}

void solve () {
	int n, q;
	cin >> n >> q;
	vvi v(n);
	rep(i, 0, n) {
		int val;
		cin >> val;
		v[i].pb(val);
	}
	
	vvi adj(n);
	rep(i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vector<bool> vis(n, 0);
	vector<bool> sorted(n,0);
	
	while (q--) {
		int ver, k;
		cin >> ver >> k;
		ver--; k--;
		
		if (not vis[ver]) {
			vis[ver] = true;
			dfs(adj, v, ver, vis);
		}
		if (!sorted[ver]) {
			sort(allg(v[ver]));
		}
		show(v[ver][k]);
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
