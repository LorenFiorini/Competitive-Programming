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
#define showv(v, n) rep(i, 0, n) {cout << v[i];} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

vint ans;
int n;

bool dfs(vvi &v, vint &can, int pos, vint &s) {
	int left = 0;
	for (int a : can) left += a;
	if (pos == n) {
		ans.swap(s);
		return true;
	}
	
	// if I choose s[i] = 1
	s[pos] = 0;
	queue<int> q;
	rep (i, 0, n) {
		if (can[i] && v[i][pos] != 0) {
			q.push(i);
			can[i] = 0;
		}
	}
	if (dfs(v, can, pos+1, s)) 
		return true;
	
	
	// Returning to can[i] = true;
	while (!q.empty()) {
		int i = q.front();
		can[i] = 1;
		q.pop();		
	}
	
	// if I choose s[i] = 0
	s[pos] = 1;
	rep (i, 0, n) {
		if (can[i] && v[i][pos] != 1) {
			can[i] = 0;
		}
	}	
	if (dfs(v, can, pos+1, s)) 
		return true;
	
	return 1;
}

void solve () {
	cin >> n;
	vvi v(n, vint (n));
	rep (i,0,n) {
		string str;
		cin >> str;
		rep (j,0,n) {
			v[i][j] = str[j] - '0';
		}
	}
	
	vint s(n, 0);
	vint can(n, 1);
	
	dfs(v, can, 0, s);
	
	showv(ans, n);
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
