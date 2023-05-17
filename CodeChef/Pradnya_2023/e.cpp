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


int n;

int bfs(vint &v, vvi &adj) {
	vint ti(n, 1e9);

	ti[0] = 0;
	queue<int> q;
	q.push(0);
	int ans = -1;

	while (!q.empty()) {
		ans++;
		queue<int> qn;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			int ene = 0;
			for (int nxt: adj[cur]) {
				if (ti[nxt] > ti[cur] + 1) {
					ti[nxt] = ti[cur] + 1;
					qn.push(nxt);
					ene++;
				}
			}
			if (ene > v[cur]) return -1;
		}
		q.swap(qn);
	}

	return ans;
}

void solve (void) {
	int ans = 0;

	cin >> n;
	vint v(n);
	vvi adj(n);
	rep (i, 0, n) cin >> v[i];


	rep (i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	


	ans = bfs(v, adj);
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
