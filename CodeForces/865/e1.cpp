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

vint bfs(vvi &adj, int n) {
	vint dis(n+1, 1e9);
	queue<int> q;
	q.push(1);
	dis[0] = 0;
	dis[1] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt: adj[cur]) {
			if (dis[nxt] > dis[cur] + 1) {
				dis[nxt] = dis[cur] + 1;
				q.push(nxt);
			}
		}
	}
	return dis;
}

void solve (void) {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	vvi vp(n, vint(2));

	// No rules case
	if (m == 0) {
		if (n == 1) {show("FINITE\n1\n1");}
		else {show("INFINITE");}
		return;
	}

	// input
	vvi adj(n + 1);
	vvi req(n + 1);
	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		adj[b].pb(a);
		req[a].pb(b);
	}
	
	// Distance from 1
	vint dis = bfs(adj, n);
	rep (i, 1, n+1) {
		if (dis[i] == 1e9) {show("INFINITE");return;}
		ans += dis[i];
		vp[i-1][0] = dis[i];
		vp[i-1][1] = i;
	}
	
	show("FINITE");
	show(ans);

	vint v(1, 1);
	sort(all(vp));

	rep (id, 1, n) {
		int num = vp[i][1];
		int cnt = vp[i][0];

		// Requirements
		// for all i 
		req[num][i]
	}


	showv(v);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
