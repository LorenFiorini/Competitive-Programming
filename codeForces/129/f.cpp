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

int n;
void bfs(vvi &adj, vint &dis) {
	
	queue<int> q;
	rep(i,0,n) {
		if (len(adj[i]) == 1) {
			dis[i] = 1;
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		queue<int> Q;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			
			for (int nxt: adj[cur]) {
				if (dis[nxt] == 1e9) {
					dis[nxt] = dis[cur] + 1;
					Q.push(nxt);
				} else if (dis[nxt] > dis[cur]) {
					dis[nxt]++;
				}
			}
		}
		q.swap(Q);
	}
}

void solve () {
	ll ans = 0;
	cin >> n;
	// edge to weight
	map<pii, int> mp;
	vvi adj(n);
	rep(i, 0, n-1) {
		int a,b,w;
		cin >> a >> b >> w;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		pii p = make_pair(min(a,b), max(a,b));
		mp[p] = w;
	}
	vint dis(n, 1e9);
	bfs(adj, dis);
	
	each(it, mp) {
		ll W = it->ss * dis[it->ff.ff] * dis[it->ff.ss];// min(dis[it->ff], dis[it->ss]);
		ans += W;
	}
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
