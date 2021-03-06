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
#define ff first
#define ss second

ll lar = 1e9, ans = 0;
int n, m;
/*
void dfs(vvi &v, vector<bool> vis, int pos, ll cnt) {
	vis[pos] = true;
	if (cnt > lar) return;
	if (pos == n) {
		ans++;
		ans %= MOD;
		return;
	}
	
	rep (i, 0, len(v[pos])) {
		int nxt = v[pos][i];
		if (vis[nxt]) continue;
		if (cnt == lar && nxt != n) continue;
		
		dfs(v, vis, nxt, cnt + (ll)1);
	}
}*/

int bfs(vvi &v) {
	vint d(n+1, INF);	d[n] = 0;
	vll ways(n+1, 0);	ways[n] = 1;
	queue<int> q;	q.push(n);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int dist = d[node] + 1;
		for (int u : v[node]) {
			if (dist == d[u]) {
				ways[u] += ways[node];
				ways[u] %= MOD;
				//if (u != 1) q.insert(u);
			}else if (dist < d[u]) {
				d[u] = dist;
				ways[u] = ways[node];
				if (u != 1) q.push(u);
			} 
		}
		//show(node);
		//showv(d, n+1);
		//showv(ways, n+1);
	}
	return ways[1];
}

void solve () {
	cin >> n >> m;
	vvi v(n+1);
	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	//rep (i, 1 n+1) {sort(allg(v[i]));}
	
	ll ans = bfs(v);
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
