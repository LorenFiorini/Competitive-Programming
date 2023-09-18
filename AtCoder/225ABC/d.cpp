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

void dfs(vpii &v, int pos, vint &ans) {
	ans.pb(pos);
	if (v[pos].ss > 0) {
		dfs(v, v[pos].ss, ans);
	}
}

void solve () {
	int n, q;
	cin >> n >> q;
	
	vpii v(n+1, {0, 0});
	
	while (q--) {
		int cas, x, y;
		cin >> cas;
		switch (cas) {
		case 1:
			cin >> x >> y;
			v[x].ss = y;
			v[y].ff = x;
			break;
		case 2:
			cin >> x >> y;
			v[x].ss = 0;
			v[y].ff = 0;
			break;
		case 3:
			cin >> x;
			while (v[x].ff != 0) {
				x = v[x].ff;
			}
			
			vint ans;
			dfs(v, x, ans);
			int N = len(ans);
			cout << N << " ";
			showv(ans, N);
			break;
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
