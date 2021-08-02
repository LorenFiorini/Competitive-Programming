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


string s;
string t;
int n, m;

bool dfs(int ps, int pt) {
	// chequear next char equal
	// si ps + i es par
	if (pt+1 == m) {
		if ((n-(ps+1)) % 2 == 0) {
			return true;
		} else {
			return false;
		}
	}
	
	for (int i = 1; ps+i < n; i+=2) 
	{
		if (n-(ps+i) < m-(pt+1)) {
			return false;
		}
		if (s[ps+i] == t[pt+1]) {
			if (dfs(ps + i, pt + 1)) return true;
		}
		//largo de lo que me queda de S
		// menor o igual
		// largo de lo que tengo que chequear en t
		
	}
	return false;
}


void solve () {
	cin >> s;
	cin >> t;
	n = len(s);
	m = len(t);
	
	
	for (int i = 0; i <= n-m; i++)
	{
		if (s[i] == t[0]) {
			if (dfs(i, 0)) {
				show("YES");
				return;
			}
		}
	}
	
	
	show("NO");
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
