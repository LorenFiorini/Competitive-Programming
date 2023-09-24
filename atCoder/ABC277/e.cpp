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

// node -> { [node, on/off], ...}
map<int, vpii> mp;
// node -> [on, off]
map<int, pii> swi;
int n, m, k;

int bfs() {
	int ans = 0;

	map<int, pii> vis;
	queue<int> q;
	q.push(1);
	swi[1].ff = 1;
 
	while (!q.empty()) {
		queue<int> nxt;
		ans++;

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			showp(ans, node);
			
			for (auto par: mp[node]) {
				//if (vis.find(par.ff) != vis.end()) continue;
				if (!((swi[node].ff && par.ss == 1) || 
					(swi[node].ss && par.ss == 0))) continue;
				if (vis[par.ff].ff == 0) {
					
				}
				vis.insert(par.ff);
				nxt.push(par.ff);
				if (par.ff == n) return ans;
				if (swi[node].ff && par.ss == 1) {
				  // if it's currently on
					swi[par.ff].ff = 1;
				}
				if (swi[node].ss && par.ss == 0) {
				  // if it's OFF
					swi[par.ff].ss = 1;
				}
			}
		}
		q.swap(nxt);
		/*
		while (!nxt.empty()) {
			int node = nxt.front();
			nxt.pop();
			vis.insert(node);
			q.push(nxt);
		}*/
	}
	return -1;
}

void solve () {
	int a, b, c;
	cin >> n >> m >> k;
	rep (i, 0, n) {
		cin >> a >> b >> c;
		mp[a].pb({b, c});
		mp[b].pb({a, c});
	}
	
	rep(i, 0, k) {
		cin >> a;
		swi[a] = {1, 1};
	}
	for (auto p: mp) {
		if (swi.find(p.ff) == swi.end()) {
			swi[p.ff] = {0, 0};
		}
	} 
	
	int ans = -1;
	ans = bfs();
	
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
