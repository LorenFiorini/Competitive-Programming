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
//
ifstream input("full-input.txt");
ofstream output("full-OUTPUT.txt");

int dfs(vvi &v, vint &gold, vint &vis, int pos) {
	vis[pos] = true;
	
	int mx = 0;
	for (int nxt : v[pos]) {
		if (vis[nxt]) continue;
		mx = max(mx, dfs(v, gold, vis, nxt));
	}
	
	return gold[pos] + mx;
}

void solve (){
	int n;
	input >> n;
	vint gold(n);
	rep (i, 0 ,n) input >> gold[i];
	vvi v(n);
	rep (i, 0, n-1) {
		int a, b;
		input >> a >> b;
		a--; b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	vint paths(len(v[0]));
	rep (i, 0, len(v[0])) {
		vint vis(n, 0);
		vis[0] = true;
		paths[i] = dfs(v, gold, vis, v[0][i]);
	}
	
	sort(allg(paths));
	int ans = gold[0];
	rep (i, 0, min(2, len(paths))) ans += paths[i];
	
	output << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T, CASE = 0;
	input >> T;
	while (CASE++ < T) {
		output << "Case #" << CASE << ": ";
		solve();
	}
	output.close();
	return 0;
}


// Lorenzo Fiorini
