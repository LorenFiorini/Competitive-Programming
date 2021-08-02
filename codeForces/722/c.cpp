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


struct Node {
	pii range;
	vint adj;
};

int dfs (vector<Node> &nodes, vector<bool> &visited, int lastval, int sum, int idx, vint &values) {
	visited[idx] = true;
	int l = nodes[idx].range.ff, r = nodes[idx].range.ss;
	int newval = abs(l - lastval) > abs(r - lastval) ? l : r;
	
	values[idx] = newval;
	
	//sum += abs(newval - lastval);
	//show("Node");
	//show(idx);
	vint v(all(nodes[idx].adj));
	rep (i, 0, len(v)) {
		int nxt = v[i];
		if (visited[nxt]) {
			sum += abs(values[nxt] - newval);
		} else {
			sum += dfs(nodes, visited, newval, 0, nxt, values);
		}
	}
	return sum;
}


void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vector<Node> nodes(n);
	rep (i, 0, n) {
		pii ran;
		cin >> ran.ff >> ran.ss;
		//v[i]->range = ran;
		nodes[i].range.ff = ran.ff;
		nodes[i].range.ss = ran.ss;
	}
	rep (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		nodes[u].adj.pb(v);
		nodes[v].adj.pb(u);
	}
	vector<bool> vis(n, false);
	vis[0] = true;
	vint values(n);
	values[0] = nodes[0].range.ff;
	ans = dfs(nodes, vis, values[0], 0, nodes[0].adj[0], values);
	
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

