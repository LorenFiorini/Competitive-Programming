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
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;


//void dfs(vvi &v, vint vis, )


void solve () {
	int n, Q;
	cin >> n >> Q;
	vvi v(n, vint(0));
	rep (i, 0, n - 1) {
		int from, to;
		cin >> from >> to;
		from--; to--;
		v[from].pb(to);
		v[to].pb(from);
	}
	
	// BFS
	queue<int> q;
	vector<bool> used(n);
	vint d(n), p(n);
	
	q.push(0);
	used[0] = true;
	p[0] = -1;
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (int to : v[from]) {
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[from] + 1;
				p[to] = from;
			}
		}
	}
	
	
	
	// ANSWERS
	while (Q--) 
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		
		int ans = d[a] + d[b];
		
		if (ans %2 == 0) {
			show("Town");
		} else {
			show("Road");
		}
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
