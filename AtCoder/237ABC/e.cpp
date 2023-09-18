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
int n, m;

int bfs(vvi &v, vint &h) {
	// happiness level 
	vint hap(n, -1e9);
	hap[0] = 0;
	// maybe -1e9
	queue<int> q;
	q.push(0);
	
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		
		for (int nxt : v[pos]) {
			if (h[nxt] <= h[pos] && hap[nxt] < hap[pos] + (h[pos] - h[nxt])) {
				hap[nxt] = hap[pos] + (h[pos] - h[nxt]);
				q.push(nxt);
			} else if (h[nxt] > h[pos]) {
				int num = 2 * (h[pos] - h[nxt]) ; // negative
				if (hap[nxt] < hap[pos] + num) {
					hap[nxt] = hap[pos] + num;
					q.push(nxt);
				}
			}
		}
		
	}
	
	int ans = 0;
	for (int a : hap) {
		///cout << a << " ";
		ans = max(ans, a);
	}
	
	return ans;
}

void solve () {
	cin >> n >> m;
	vint h(n);
	rep(i,0,n) cin >> h[i];
	
	vvi v(n);
	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	int ans = bfs(v, h);
	
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
