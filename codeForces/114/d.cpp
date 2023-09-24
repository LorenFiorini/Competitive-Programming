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

int n, m;

ll get(vvi &v, vint &b, vint &tmp) {
	ll ans = 0;
	rep (i, 0, n) {
		if (b[i] == v[i][0]) {
			tmp[i] = b[i] - 1;
			ans += v[i][ b[i] - 1 ];
		} else {
			tmp[i] = v[i][0];
			ans += v[i][ v[i][0] ];
		}
	}
	return ans;
}

void solve () {
	ll ans = 0;
	
	cin >> n;
	vvi v(n);
	rep (i,0,n) {
		int c;
		cin >> c;
		vint a(1+c, c);
		rep (j,0,c) cin >> a[j+1];
		v[i] = a;
		
	}
	
	vint vans(n);
	cin >> m;
	rep (i, 0, m) {
		vint b(n);
		rep (j,0,n) cin >> b[j];
		
		vint tmp(n);
		ll val = get(v, b, tmp);
		
		
		if (val >= ans) {
			ans = val;
			vans.swap(tmp);
		}
	}
	
	
	showv(vans, n);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
