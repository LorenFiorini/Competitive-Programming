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

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vint v(n);
	rep (i,0,n) cin >> v[i];
	
	int m;
	cin >> m;
	vvi adj(n);
	map<vint, int> mp;
	rep(i,0,m) {
		int a, b;
		cin >> a >> b;
		if (b > a) swap(a,b);
		a--; b--;
		mp.insert({ {a,b}, i+1 });
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	// Special cases
	rep (i, 0, n) {
		if (v[i] != i+1 && len(adj[v[i]-1]) == 0) {
			show(-1);
			return;
		}
	}
	bool zero = 1;
	rep (i,0,n) {
		zero &= (v[i] == i+1);
	}
	if (zero) {
		show(0);
		return;
	}
	
	
	while(1);
	
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
