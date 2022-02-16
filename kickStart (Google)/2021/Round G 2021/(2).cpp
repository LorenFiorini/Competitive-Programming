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
#define X first
#define Y second

ll k;
ll n;

ll distance(vvi &v, ll x, ll y) {
	ll ans = 0;
	for (vint fur : v){
		ll px = 0;
		if (x <= fur[0]) {
			px = fur[0];
		} else if (x >= fur[2]) {
			px = fur[2];
		} else {
			px = x;
		}
		ll py = 0;
		if (y <= fur[1]) {
			py = fur[1];
		} else if (y >= fur[3]) {
			py = fur[3];
		} else {
			py = y;
		}
		ans += (abs(x - px) + abs(y - py));
	}
	return ans;
}

ll a[4] = {1, -1, 0, 0};
ll b[4] = {0, 0, -1, 1};

ll bfs(vvi &v, ll x, ll y, set<pii> &vis, pii &ans, ll dis) {
	//pii ans = {0, 0};
	//ll dis = 1e12;
	vis.insert({x, y});
	
	queue<pii> q;
	q.push({x, y});
	
	
	while (!q.empty()) {
		pii pos = q.front();
		q.pop();
		
		ll dit = distance(v, pos.X, pos.Y);
		if (dit <= dis) 
		{
			if (dit < dis || ((pos.X < ans.X && pos.Y <= ans.Y) || (pos.X <= ans.X && pos.Y < ans.Y))) {
				dis = dit;
				ans = pos;
			}
			
			// add adjacent
			rep (i, 0, 4) {
				pii nxt = {a[i] + pos.X , b[i] + pos.Y};
				auto it = vis.find(nxt);
				if (it == vis.end()) {
					q.push(nxt);
					vis.insert(nxt);
				}
			}
		}
		
	}
	
	return dis;
}

void solve () {
	ll zero = 0;
	ll mn[2] = {INF, INF};
	ll mx[2] = {-INF, -INF};
	
	cin >> k;
	vvi v(k, vint(4, 0));
	rep (i,0,k) {
		rep (j,0,4) {
			cin >> v[i][j];
			mn[j%2] = min(mn[j%2], v[i][j]); 
			mx[j%2] = max(mx[j%2], v[i][j]); 
			zero = min(zero, v[i][j]);
		}
	}
	
	// make all positive
	zero = abs(zero);
	rep (i,0,k) {
		rep (j,0,4) {
			v[i][j] += zero;
		}
	}
	
	//Brute force
	set<pii> vis;
	ll midX = (mx[0] + mn[0]) / 2 ;
	ll midY = (mx[1] + mn[1]) / 2 ;
	pii ans;
	ll d1 = bfs(v, midX, midY, vis, ans,  1e12);
	ll d2 = bfs(v, midX+1000, midY+1000, vis, ans, d1);
	ll d3 = bfs(v, midX-1000, midY+1000, vis, ans, d2);
	ll d4 = bfs(v, midX+1000, midY-1000, vis, ans, d3);
	ll d5 = bfs(v, midX-1000, midY+1000, vis, ans, d4);
	
	ans.X -= zero;
	ans.Y -= zero;
	
	showp(ans.X, ans.Y);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
