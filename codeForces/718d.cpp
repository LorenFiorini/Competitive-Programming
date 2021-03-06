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
#define ff first
#define ss second
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
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;



int n, m, k;
int a[4] = { -1, 0, 1, 0 };
int b[4] = { 0, -1, 0, 1 };

bool notvalid(int i , int j) {
	if (i < 0 || j < 0 || i >= n || j >= m) return true;
	return false;
}


int bfs (vvi &ho, vvi &ve, int i, int j, int ans, int cnt) {
	if (cnt == 0) return ans;
	
	//ans += 
	
	mn = 
	rep (i, 0, 4) {
		int ii = i + a[p];
		int jj = j + b[p];
		if (notvalid(ii, jj)) continue;
		
		mn = min( mn, dfs (ho, ve, ii, jj ));
	}
	
	return ans;
}
/*
int bfs (vvi &ho, vvi &ve, int i, int j, int ans, int cnt) {
	
	q.push(mk(i, j));
	while (!q.empty()) {
		pii ver = q.front();
		q.pop();
		 
		 for 
		 
	}
	
	
}*/


void solve () {
	cin >> n >> m >> k;
	vvi ho( n, vint(m - 1) );
	rep (i, 0, n) rep (j, 0, m - 1) cin >> ho[i][j]
	vvi ve( n - 1 , vint(m) );
	rep (i, 0, n - 1) rep (j, 0, m) cin >> ve[i][j]
	
	
	vvi ans(n, vint(m), 0);
	
	rep (i, 0, n) {
		rep (j, 0, m) {
			if (k & 1) {
				ans[i][j] = -1;
				continue;
			}
			ans[i][j] = dfs(ho, ve, i, j, 0, k / 2);
		}
	}
	
	
	
	
	// answer
	rep (i, 0, n) {
		rep (j, 0, m) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}


