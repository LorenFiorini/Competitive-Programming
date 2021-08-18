#include <bits/stdc++.h>
using namespace std;
#define INF (ll)1e18
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vll> vvi;
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
#define ci first
#define co second

ll n, m, k;

void bfs(vll &c, vector<vpii> &v, ll start) {
	queue<ll> q;
	q.push(start);
	
	while (! q.empty()) {
		ll i = q.front();
		q.pop();
		
		ll N = len(v[i]);
		rep (j, 0, N) 
		{
			// cost this hospt + cost road
			ll cost = c[i] + v[i][j].co;
			// if less than cost there ( cr.ci )
			if (cost < c[ v[i][j].ci ]) {
				//update cost
				c[ v[i][j].ci ] = cost;
				q.push( v[i][j].ci );
			}
		}
		
	}
}


void solve () {
	cin >> n >> m >> k; 
	// COST OF TEST 
	vll c(n, INF);
	vll start;
	rep (i, 0, k) {
		ll city, cost;
		cin >> city >> cost;
		c[city-1] = cost;
		start.pb(city-1);
	}
	//ROADS
	vector<vpii> v(n);
	rep (i, 0, m) {
		ll a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		v[a].pb({b, d});
		v[b].pb({a, d});
	}
	
	rep (i, 0, n){
		bfs(c, v, (ll)i);
	}
		
	showv(c, n);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
