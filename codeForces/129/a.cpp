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

bool f(vint &a, vint &b, int n, int m) {
	int i = 0, j = 0; 
	int c = 0;
	while (i < n && j < m) {
		if (!c) {
			// alice
			while (i < n && a[i] <= b[j]) i++;
			if (i == n) return false;
		} else {
			while (j < m && a[i] >= b[j]) j++;		
			if (j == m) return true;	
		}
		c++;
		c %= 2;
	}
	return c;
}

void solve () {
	int n,m;
	cin >> n;
	vint a(n+1);
	rep(i,1,n+1) cin >> a[i];
	cin >> m;
	vint b(m+1);
	rep(i,1,m+1) cin >> b[i];
	
	sort(all(a));
	sort(all(b));
	
	if (f(a,b,n+1,m+1)) {
		show("Alice");
	} else {
		show("Bob");
	}
	if (f(b,a,m+1,n+1)) {
		show("Bob");
	} else {
		show("Alice");
	}
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
