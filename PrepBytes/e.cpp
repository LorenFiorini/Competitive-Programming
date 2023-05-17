#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
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
#define ff first
#define ss second
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

int n;
int bfs(vvi &adj, int from, int to1, int to2) {
  vint dis(n, 1e9);
  queue<int> q;
  
  q.push(from);
  dis[from] = 0;
  
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    
    
    for (auto nxt: adj[cur]) {
      if (dis[nxt] > dis[cur] + 1) {
        dis[nxt] = dis[cur] + 1;
        q.push(nxt);
      }
    }
    
    if (max(dis[to1], dis[to2]) < 1e9) {
      return dis[to1] + dis[to2];
    }
  }
  if (max(dis[to1], dis[to2]) == 1e9) return 1e9;
  
  return dis[to1] + dis[to2];
}

void solve (void) {
	int ans = 1;
	int m, a, b, k;
	cin >> n >> m;
  vvi adj(n);
  rep (i, 0, m) {
    cin >> a >> b;
    a--; b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
	cin >> k;
	vint c(k);
	rep (i, 0, k) {
	  cin >> c[i];
	  c[i]--;
	}
	
	for (int i = 1; i < k; i += 2) {
	  int to2 = c[i];
	  if (i+1 < k) to2 = c[i+1];
	  ans += bfs(adj, c[i], c[i-1], to2);
	  if (ans >= 1e9) {
	    ans = -1;
	    break;
	  }
	}
	
	
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
