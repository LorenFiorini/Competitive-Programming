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
// pos -> [L, R]
int val = 1;
vpii ans;
int n;
vvi v;
vector<bool> vis;

pii dfs(int pos) {
	
	bool leaf = true;
	pii p = {val, val};
	for (int nxt: v[pos]) {
		if (!vis[nxt]) {
			leaf = false;
			vis[nxt] = 1;
			pii sub = dfs(nxt);
			
			p.ff = min(p.ff, sub.ff);
			p.ss = max(p.ss, sub.ss);
		}		
	}
	ans[pos] = p;
	if (leaf) {
		val++;
	}
	return ans[pos];
}

void solve () {
	cin >> n;
	v.resize(n);
	ans.resize(n);
	vis.resize(n, false);
	
	rep(i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	vis[0] = 1;
	dfs(0);
	
	for (pii p: ans) {
		showp(p.ff, p.ss);
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

/*
7
1 2
1 3 
2 4 
2 5 
4 6 
4 7

*/
