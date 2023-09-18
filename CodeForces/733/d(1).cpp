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
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
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

int n;

//void dfs (vint &v, vint &to, vector<bool> vis) 
void dfs(vint &v, vint vis, int pos, int &h) {
	h++;
	vis[pos] = true;
	if (vis[v[pos]] == false) dfs(v, vis, v[pos], h);
}

void DFS(vint &v, vint &vis, int pos, vint &A, int &last) {
	vis[pos] = true;
	if (vis[v[pos]] == false) {
		DFS(v, vis, v[pos], A, last);
		A[pos] = v[pos] + 1;
	} else {
		last = pos;
	}
}

void dfs3(vint &A, vint &vis, int last) {
	vis[last] = true;
	rep (i ,0, n) {
		if (vis[i]) continue;
		if (A[i] == 0) {
			dfs3(A, vis, i);
			A[last] = i + 1;
			return;
		}
		
	}
}

void solve () {
	int ans = 0;
	cin >> n;
	vint v(n);
	rep (i, 0, n) {
		cin >> v[i];
		v[i]--;
	}
	
	int sta;
	vint vis(n, 0);
	rep (i, 0, n) {
		int h = 0;
		dfs(v, vis, i, h);
		//showp(i+1, h );
		if (h > ans) {
			ans = h;
			sta = i;
		}
	}
	show(ans - 1);
	
	
	int last;
	vint A(n, 0);
	DFS(v, vis, sta, A, last);
	
	dfs3(A, vis, last);
	
	rep (i, 0, n) {
		if (A[i]) {
			cout << A[i] << " ";
		} else {
			cout << sta+1 << " ";
		}
	}
	
	cout << "\n";
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
