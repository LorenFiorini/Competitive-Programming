#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
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
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";



int n, k;

int dfs(vvi &adj, vint &vis, int p, seti &st) {
	vis[p] = 1;
	if (st.find(p) != st.end())
		st.erase(p);
	if (st.empty()) return 1;
	for (auto nxt: adj[p]) {
		if (!vis[nxt]) {
			int t = dfs(adj, vis, nxt, st);
			if (t) return t + 1;
		}
	}
	return 0;
}

int same_component(vvi &adj, vint &c) {
	vint vis(n, 0);
	seti st(all(c));
	return dfs(adj, vis, c[0], st);
}

void bfs(vvi &adj, vint &c, vvi &floyd) {
  	mpii st;
  	rep (i, 0, k) st[c[i]] = i;

  	rep (start, 0, k)
  	{
  		vint vis(n,0);
  		queue<int> q;

  		q.push(c[start]);
  		vis[c[start]] = 1;
  		int dis = 0;

  		while (!q.empty()) {
  			queue<int> qn;
  			bool ok = 0;
  			dis++;

	  		while (!q.empty()) {
	  		 	int cur = q.front();
	  		 	q.pop();
	  		 	
	  		 	
	  		 	for (auto nxt: adj[cur]) {
	  		 	 	if (!vis[nxt]) {
	  		 	 		if (st.find(nxt) != st.end()) {
	  		 	 			floyd[start][st[nxt]] = dis;
	  		 	 			floyd[st[nxt]][start] = dis;
	  		 	 		}
	  		 	 	  	vis[nxt] = 1;
	  		 	 	  	qn.push(nxt);
	  		 	 	}
	  		 	}
	  		}
	  		q.swap(qn);
	  		if (ok) break;
	  	}
  	}
  	

	return ;
}

void solve (void) {
	int ans = 1;
	int m, a, b;
	cin >> n >> m;
  	vvi adj(n);
  	rep (i, 0, m) {
  	  	cin >> a >> b;
  	  	a--; b--;
  	  	adj[a].pb(b);
  	  	adj[b].pb(a);
  	}
	cin >> k;
	vint c(k);
	rep (i, 0, k) {
	  	cin >> c[i];
	  	c[i]--;
	}

	int tmp = same_component(adj, c);
	if (!tmp) {
		show(-1);
		return;
	}

	vvi floyd(k, vint(k, 1e9));
	rep (i, 0, k) floyd[i][i] = 0;
	bfs(adj, c, floyd);

	//showmat(floyd);
	//show("");
	rep (K, 0, k) {
		rep (i, 0, k) {
			rep (j, 0, k) {
				if (floyd[i][j] > floyd[i][K] + floyd[K][j]) 
					floyd[i][j] = floyd[i][K] + floyd[K][j];
			}
		}
	}
	//showmat(floyd);

	ans = 1e9;
	int i = k-1;
	rep (j, 0, k) {
		int cnt = 1;
		rep (K, 0, k) {
			cnt += floyd[(i - K)][(j + K) % k];
		}
		ans = min(ans, cnt);
	}


	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
