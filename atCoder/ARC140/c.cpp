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
void add(vint &v, vint &ans, int dir, int x) {
	while (x+dir > 0 && x+dir <= n) {
		ans.pb(x+dir);
		v[x+dir] = 1;
		
		x += dir;
		dir *= -1;
		if (dir < 0) {
			do {
				dir--;
			} while (x+dir > 0 && v[x+dir]);			
		} else {
			do {
				dir++;
			} while (x+dir <= n && v[x+dir]);	
		}
	}
	rep(i,1,n+1) {
		if (!v[i]) ans.pb(i);
	}
}

void solve () {
	int x;
	cin >> n >> x;
	vint v(n+1, 0);
	v[0] = v[x] = 1;
	vint ans(1,x);
	
	if (n%2) {
		int mid = n/2 + 1;
		if (mid == x) {
			add(v, ans, 1, x);
		} else {
			v[mid] = 1;
			ans.pb(mid);
			if (mid - x > 0) add(v, ans, 1, mid);
			else add(v, ans, -1, mid);	
		}		
	} else {
		int mid = n/2;
		if (mid == x) {
			add(v, ans, 1, x);	
		} else if (mid + 1 == x) {
			add(v, ans, -1, x);						
		} else {			
			if (mid - x > 0) {
				v[mid+1] = 1;
				ans.pb(mid+1);
				add(v, ans, 1, mid);
			} else {
				v[mid] = 1;
				ans.pb(mid);
				add(v, ans, 1, mid);
			}
		}	
	}
	
	showv(ans, n);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
