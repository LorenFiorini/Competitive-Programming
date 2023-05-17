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

// index to vertices that fulfill requiement
map<int, set<int>> miv;
int n, m, k;

bool bfs(vvi &adj, vvi &ver, int start, int dis) {
	vector<bool> vis(n, 0);
	queue<int> q;
	int d = 0;
	q.push(start);
	vis[start] = 1;

	if (dis == 0) {
		if (ver[start][0] == 0) return 0;
		ver[start][0] = 1;
		ver[start].pb(start);
		return 1;
	}
	//showp("start:", start);

	if (ver[start][0] == 1) {
		int sz = ver[start].size();
		rep(id, 1, sz) {
			miv[ver[start][id]].erase(start);
			if (miv[ver[start][id]].size() == 0) {
				return 0;
			}
		}
	} 
	ver[start][0] = 0;

	while (d < dis) {
		queue<int> qn;
		d++;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			//show(cur);
			ver[cur][0] = 0;

			for (int nxt: adj[cur]) {
				if (vis[nxt]) continue;
				vis[nxt] = 1;
				qn.push(nxt);
				if (ver[nxt][0] == 1) {
					int sz = ver[nxt].size();
					rep(id, 1, sz) {
						miv[ver[nxt][id]].erase(nxt);
						if (miv[ver[nxt][id]].size() == 0) {
							return 0;
						}
					}
				} 
			}
		}
		//showmat(ver);
		swap(q, qn);
	}

	bool ok = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//show(cur);

		if (ver[cur][0] != 0) {
			ok = 1;
			ver[cur][0] = 1;
			ver[cur].pb(start);
			miv[start].insert(cur);
		}
	}


	return ok;
}

void solve (void) {
	cin >> n >>  m;
	vvi adj(n);
	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	//showmat(adj);
	cin >> k;
	vvi pd(k, vint(2));
	rep (i, 0, k) cin >> pd[i][0] >> pd[i][1];

	vvi ver(n, vint(1, -1));
	
	rep(i, 0, k) {
		if (!bfs(adj, ver, pd[i][0] - 1, pd[i][1])) {
			show("No");
			return;
		}
		//show("Matrix")
		//showmat(ver);
	}

	show("Yes");
	rep (i, 0, n) {
		if (ver[i][0] == 0) {
			cout << "0";
		} else {
			cout << "1";
		}
	}
	cout << endl;

	//showmat(ver);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
