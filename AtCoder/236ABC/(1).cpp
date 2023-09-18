#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
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

ll n;
ll ans = 0;
map<vint, ll> mp;

void dfs(vvi &v, vint &vis, ll suma) {
	
	ll tot = accumulate(all(vis), 0);
	if (tot == 2*n) {
		ans = max(ans, suma);
		cout << ans << "\n";
		return;
	}
	
	vint vec(2*n);
	rep(i, 0, 2*n) {
		if (vis[i] == 0){
			vec[i] = 1;
		}
	}
	
	rep (i, 0, 2*n) {
		if (vis[i]) continue;
		rep (j, i+1, 2*n) {
			if (vis[j] == 0) {
				vis[i] = 1;
				vis[j] = 1;
				vec[i] = 0;
				vec[j] = 0;
				
				auto it = mp.find(vec);
				if (it == mp.end() || it->ss <= (ll)(suma ^ v[i][j])) {
					mp[vec] = (suma ^ v[i][j]);
					dfs(v, vis, suma ^ v[i][j]);
				}
				vis[i] = 0;
				vis[j] = 0;
				vec[i] = 1;
				vec[j] = 1;				
			}
		}
	}
}

void solve () {
	cin >> n;
	
	vvi v(2*n, vint(2*n, 0));
	
	rep (i, 0, 2*n) {
		rep(j, i+1, 2*n) {
			cin >> v[i][j];
		}
	}
	
	vint vis(2*n, 0);
	dfs(v, vis, (ll) 0);
	
	
	each(it, mp) {
		showv(it->ff, 2*n);
		show(it->ss);
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
