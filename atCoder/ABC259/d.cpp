#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
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
#define x first
#define y second

vvi get(vvi &v, int n) {
	vvi ans(n);
	double ra, D;
	ll dx, dy;
	rep(i, 0, n) {
		rep(j, i+1, n) {
			dx = abs(v[i][0] - v[j][0]);
			dy = abs(v[i][1] - v[j][1]);
			//if (dx + dy == 0) continue;

			ra = v[i][2] + v[j][2];
			D = sqrt(dx*dx + dy*dy);

			if (ra >= D) {
				if (!((D + (double)v[j][2] < (double)v[i][2]) 
					|| (D + (double)v[i][2] < (double)v[j][2]))) {
					ans[i].pb(j);
					ans[j].pb(i);
				}
			}
		}
	}
	/*
	rep(p, 0, n) {
		int m = len(ans[p]);
		showv(ans[p], m);
	}
	//cout << endl;*/
	return ans;
}

int point(pii s, vvi &v, ll n) {
	ll D, dx, dy;
	rep(i, 0, n) {
		dx = abs(v[i][0] - s.x);
		dy = abs(v[i][1] - s.y);
		D = dx*dx + dy*dy;

		if (D == v[i][2] * v[i][2]) return i;
	}
	//while (1) d++;
	return 0;
}

bool dfs(ll e, vvi &v, ll n, ll pos, vector<bool> &vis) {
	if (pos == e) return 1;
	
	vis[pos] = 1;
	for (int nxt: v[pos]) {
		if (!vis[nxt]) {
			if (dfs(e, v, n, nxt, vis)) return 1;
		}
	}
	return 0;
}


void solve () {
	ll n;
	cin >> n;
	pii s; pii t;
	cin >> s.x >> s.y >> t.x >> t.y;

	vvi v(n, vint(3));
	rep(i, 0, n) {
		rep(j, 0, 3) cin >> v[i][j];
	}
	vvi adj = get(v, n);

	int a = point(s, v, n);
	int b = point(t, v, n);

	vector<bool> vis(n, 0);
	if (dfs(b, adj, n, a, vis)) {
		show("Yes");
	} else {
		show("No");
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
