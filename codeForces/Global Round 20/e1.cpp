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

ll ans = 1e18;
seti st;

ll query(ll num) {
	cout << "? " << num << endl;
	ll a; cin >> a;
	return a? a : 1e9;
}

int bin(ll &times, ll &up) {
	ll l = 1;
	ll r = 2000;
	
	while (l < r && times--) {
		ll width = (l + r) / 2;
		ll he = query(width);
		if (he != (ll) 1e9) ans = min(ans, width * he);
		
		if (he == 1) up = min(up, width);
		st.insert(width);
		
		if (he == 1e9) {
			l = width + 1;
		} else {
			r = width;
		}
	}
	return l;
}


void solve () {	
	ll n;
	cin >> n;
	//ans = n * 2000;
	ll times = n + 30;
	
	
	ll up = 4 * 1e6;
	ll low = bin(times, up);

	ll inc = low;
	while (times > 0) {
		for (ll width = low; width <= up; width += inc) {
			if (times-- <= 0) break;
			while (st.find(width) != st.end()) width++;
			st.insert(width);
			
			ll he = query(width);			
			ans = min(ans, width * he);
			if (he == 1) {
				up = min(up, width);
			}
		}
		inc -=  max((ll)2, low / (ll)10);
		inc = max(inc, (ll) 1);
	}
	
	
	
	cout << "! " << ans << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
