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
ll bfs(vll &a, vvi& v, int beg) {
	ll ans = 0;
	vint vis(n, 0);
	vis[beg] = 1;

	queue<int> q;
	q.push(beg);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans++;

		for (int nxt: v[cur]) {
			if (!vis[nxt]) {
				vis[nxt] = 1;
				q.push(nxt);
			}
		}
	}

	return ans;
}

void solve () {
	ll ans = 0;
	ll x, y;
	cin >> n;
	vll a(n);
	seti st;
	rep (i,0,n) {
		cin >> a[i];
	}
	vvi v(n);
	rep (i, 0, n-1) {
		cin >> x >> y;
		x--; y--;
		if (a[x] > a[y]) {
			v[x].pb(y);
			st.insert(y);
		}
		if (a[x] < a[y]) {
			v[y].pb(x);
			st.insert(x);
		}
	}

	vint val(n, 0);
	rep (i, 0, n) {
		if (st.find(i) == st.end()) {
			// i is source
			ans = max(ans, bfs(a, v, i));
		}
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
