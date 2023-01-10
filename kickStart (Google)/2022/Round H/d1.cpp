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

int dfs(vint &per, vint &vis, int pos) {
	vis[pos] = 1;

	int ans = 1;
	if (!vis[per[pos]]) {
		ans += dfs(per, vis, per[pos]);
	}
	return ans;
}


void solve () {
	int n;
	cin >> n;
	vint per(n);
	rep (i,0,n) {
		cin >> per[i];
		per[i]--;
	}
	// computing circles
	vint vis(n, 0);
	vint v;
	rep (i,0,n) {
		if (!vis[i]) {
			v.pb(dfs(per, vis, i));
		}
	}
	sort(allg(v));
	int N = len(v);

	// finding minimums
	vint ans(n+1, 1e9);
	rep (i, 0, N) ans[v[i]] = 0;
	
	int sum = 0;
	rep (i, 0, N) {
		rep (j, i, N) {
			ans[sum+v[j]] = min(ans[sum+v[j]], i);
		}
		rep (id, sum, sum+v[i]) {
			ans[id] = min(ans[id], i+1);
		}
		sum += v[i];
	}

	rep (i, 1, n+1) cout << ans[i] << " ";
	cout << endl;
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
/*
12
2 3 4 5 1 7 8 6 10 11 9 12
*/