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

int n;
int ans = INF;
set<string> mp;

void dfs(vvi &v1, vvi &v2, vint &vis, int px, int py, int x, int y) {
	int cnt = accumulate(all(vis), 0);
	//if (cnt >= ans) return;
	if (x <= 0 && y <= 0) {
		ans = min(cnt, ans);
		return;
	} 
	
	//check whether this combination already done
	//map<vint, int>::iterator set<string>::iterator
	string s;
	rep (i,0,n) {	s.pb((char)vis[i] + '0');	}
	auto it = mp.find(s);
	if (it != mp.end()) return;
	else mp.insert(s);
	
	// Fix position of pointers
	// v1[px][2] is the original position of the box
	px = py = 0;
	while (vis[v1[px][2]]) px++; 
	while (vis[v2[py][2]]) py++;
	
	if (x > 0) {
		vis[v1[px][2]] = true;
		dfs(v1, v2, vis, px + 1, py, x-v1[px][0], y-v1[px][1]); 
		vis[v1[px][2]] = false;
	}
	
	if (y > 0) {
		vis[v2[py][2]] = true;
		dfs(v1, v2, vis, px, py + 1, x-v2[py][1], y-v2[py][0]); 
		vis[v2[py][2]] = false;
	}
	
	
	return;
}
	
void solve () {
	cin >> n;
	int x, y;
	cin >> x >> y;
	
	int cntA = 0, cntB = 0;
	vvi v1(n);
	vvi v2(n);
	rep (i, 0, n) {
		int a, b;
		cin >> a >> b;
		cntA += a;
		cntB += b;
		v1[i] = {a, b, i};
		v2[i] = {b, a, i};
	}
	
	// whenever -1 or N
	if (cntA < x || cntB < y) {
		show(-1);
		return;
	} else if (cntA == x || cntB == y) {
		show(n);
		return;
	}
	
	// Sort max first 
	sort(allg(v1)); // X, Y, i
	sort(allg(v2)); // Y, X, i
	
	
	vint vis(n, 0);	
	dfs(v1, v2, vis, 0, 0, x, y);
	
	
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
