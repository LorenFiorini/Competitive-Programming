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
#define pb push_back
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
#define n first
#define w second

//set<pii> st;
//set<pii>::iterator it;
ll ans = 0;


void dfs(vector<vpii> &v, int pos, vpii &mx, int we, vint &vis) {
	if (vis[pos]) return;
	vis[pos] = 1;
	// Weights up to node i
	ll sum = we;
	rep (i, 0, len(mx) ) {
		mx[i].w = max(mx[i].w, we);
		sum += (ll) mx[i].w;
	}
	
	// sumar 
	ans += sum;
	
	rep (i, 0, len(v[pos])) {
		int nxt = v[pos][i].n;
		if (vis[nxt]) continue;
		
		mx.pb(v[pos][i]);
		dfs(v, nxt , mx, v[i][0].w, vis);

	}
	return;
}


void solve () {
	int ans = 0;
	int N;
	cin >> N;
	vector<vpii> v(N);
	rep (i, 0, N-1) {
		int u, uu, ww;
		cin >> u >> uu >> ww;
		u--; uu--;
		v[u].pb({uu, ww});
		v[uu].pb({u, ww});
	}
	
	vpii mx;
	vint vis(N);
	rep (i, 0, N) {
		if (len(v[i]) == 1) {
			vis[i] = true;
			
			mx.pb(v[i][0]);
			dfs(v, v[i][0].n , mx, v[i][0].w, vis);
			
			break;
		}
	}
	
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
