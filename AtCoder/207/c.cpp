#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long double ll;
typedef pair<ll, ll> pii;
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
#define l first
#define r second
//
#define por(i, a, b, in) for (long long i=a ; i<(b) ; i+=in)
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


void solve () {
	// INPUT
	int n;
	cin >> n;
	vpii v(n);
	rep (i, 0, n) {
		int t;
		cin >> t;
		ll x, y;
		cin >> x >> y;
		switch (t) {
			case 1:
				
				break;
			case 2:
				y -= 0.5;
				break;
			case 3:
				x += 0.5;
				break;
			case 4:
				y -= 0.5;
				x += 0.5;
				break;
		}
		v[i].l = x;
		v[i].r = y;
	}
	
	// ALGORITHM
	long long ans = 0;
	sort(all(v));
	vll r(n);
	vll l(n);
	rep (i, 0, n) {
		r[i] = v[i].r;
		l[i] = v[i].l;
		//showp(l[i], r[i]);
	}
	
	rep (i, 0, n - 1) {
		
		vll::iterator up = upper_bound(l.begin() + i + 1, l.end(), r[i]);
		long long sum = up - (l.begin() + i + 1);
		
		ans += max(sum, (long long) 0);
	}
	
	
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
