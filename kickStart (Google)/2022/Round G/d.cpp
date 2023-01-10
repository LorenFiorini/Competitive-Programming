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

ll e, n;

void dfs(vvi &v, ll p, vint &vis, ll sum, ll &ans, bool ri) {
	ans = max(ans, sum);

	rep(i, 0, n) {
		if (vis[i] == 0 && v[i][1] <= v[p][1]) {
			ll s = sum + v[i][2];
			bool right = (v[p][0] <= v[i][0]);
			vis[i] = 1;
			if (right == ri) {
				dfs(v, i, vis, s, ans, ri);
			} else {
				dfs(v, i, vis, s-e, ans, !ri);
			}
			vis[i] = 0;
		}
	}
}

void solve () {
	ll ans = 0;
	cin >> n >> e;
	// X, Y, C

	vvi v(n, vint(3));
	rep(i, 0, n) {
		rep(j, 0, 3) cin >> v[i][j];
	} 

	rep (i, 0, n) {
		vint vis(n, 0);
		vis[i] = 1;
		dfs(v, i, vis, v[i][2], ans, 1);
	}

	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T; 
	rep(C, 1, T+1) {
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
