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

void solve () {
	ll n, m;
	cin >> n >> m;
	vint v(m);
	rep(i, 0, m) cin >> v[i];
	sort(all(v));

	vint dis(m);
	rep(i, 1, m) {
		dis[i] = abs(v[i] - v[i-1]) - 1;
	}
	dis[0] = v[0] + (n - v[m-1]) - 1;
	sort(allg(dis));

	showv(dis, m);
	ll ans = m;
	if (dis[0] > 1) ans++;

	int inf = 1;
	rep(i, 1, m) {
		// inf = 1, 3, 5, ...
		inf += 2;
		if (dis[i] > inf) {
			ans += inf;
		} else if (dis[i] == inf){
			ans += inf - 1;	
		} else {
			ans += dis[i];
		}
		//show(ans);
	}
	
	show(ans);
	show("-");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
