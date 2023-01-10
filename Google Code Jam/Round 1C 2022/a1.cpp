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

bool check(string s) {
	set<char> st;
	int m = len(s);
	char c = c[0];
	rep(i,1,m+1) {
		if (i == m || s[i] != s[i-1]) {
			if (st.find(c) != st.end()) return false;
			st.insert(c);			
			if (i < m) c = s[i];
		}
	}
	return true;
}

int up (vvi &adj, int n, int pos) {
	
	rep(i, 0, n){
		for (int nxt: adj[i]) {
			if (nxt == pos) {
				return up(); 
			}
		}
	}
	return pos;
}

void solve () {
	int n;
	cin >> n;
	vstr v(n);
	map<char,int> start;
	rep(i,0,n) {
		cin >> v[i];
		ok &= check(v[i]);
	}
	if (!ok) {
		show("IMPOSSIBLE");
		return;
	}
	vvi adj(n);
	rep(i,0,n) {
		int m = len(v[i]);
		rep(j,0,n) {
			if (i == j) continue;
			if (v[i][m-1] == v[j][0]) {
				adj[i].pb[j];
			} 
		}
	}
	// is it valid directed
	rep(i,0,n) {
		if (len(adj[i]) > 1) {
			int cnt = 0;
			for (int nxt : adj[i]) {
				int m = v[nxt].size();
				cnt += (v[nxt][0] != v[nxt][m-1]);
			}
			if (cnt > 1) {show("IMPOSSIBLE");return;}
		}
	}
	
	vector<bool> vis(n,0);
	
	rep(i,0,n) {
		if (!vis[i]) {
			dfs(adj, n, i);
			
		}
	}
	
	
	show(ans);
}
struct Node{
	char first;
	char last;
	set<char> st;
	
};
int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
