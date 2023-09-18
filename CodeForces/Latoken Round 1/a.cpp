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
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;


int n, m;

void mat(vvi &v) {
	string color = ".RW";
	show("YES");
	rep (i, 0, n) {
		rep (j, 0, m) {
			cout << color[v[i][j]] ;
		}
		cout << "\n";
	}
	return;
}




void solve () {
	cin >> n >> m;
	vvi v(n, vint (m));
	
	rep (i, 0, n) rep (j, 0, m) {
		char ch;
		cin >> ch;
		if (ch == '.') v[i][j] = 0;
		else if (ch == 'R') v[i][j] = 1;
		else v[i][j] = 2;
	} 
	
	vvi a(n, vint (m));
	vvi b(n, vint (m));
	
	rep (i, 0, n) {
		rep (j, 0, m) {
			if ((i+j) % 2 == 0) {
				a[i][j] = 1;
				b[i][j] = 2;
			} else {
				a[i][j] = 2;
				b[i][j] = 1;
			}
		}
	}
	bool oka = true;
	bool okb = true;
	
	rep (i, 0, n) {
		rep (j, 0, m) {
			if (v[i][j] != 0) {
				if (v[i][j] != a[i][j]) oka = false;
				if (v[i][j] != b[i][j]) okb = false;
			}
		}
		if (!(oka || okb)) {
				show("NO");
				return;
			}
	}
	if (oka) mat(a);
	else if (okb) mat(b);
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
