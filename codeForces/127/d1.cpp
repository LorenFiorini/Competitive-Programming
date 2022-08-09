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
#define por(i, a, b, in) for (ll  i=a ; i<(b) ; i+=in)
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


void solve () {
	ll ans = 0;
	ll n, x;
	cin >> n >> x;
	ll mn = 1e9, mx = 0;
	set<ll> st;
	vll v(n);
	
	rep(i,0,n){
		cin >> v[i];
		st.insert(v[i]);
		mn = min(mn, v[i]);
		mx = max(mx, v[i]);
	}
	rep(i,1,n) {
		ans += abs(v[i] - v[i-1]);
	}
	
	ll less = min(v[0], v[n-1]);
	ll more = max(v[0], v[n-1]);
	
	rep (num, 1, x + 1) {
		// next to same
		if (st.find(num) != st.end()) continue;
		
		ll dif = 1e9;
		if (num < mn) {
			ll a = 2 * abs(mn - num); // insert mid
			ll b = abs(less - num); // insert beginnning
			dif = min(a, b);
			
			if (a >= b) {
				less = num;
			}
			mn = num;
		} else if (num > mx) {			
			ll a = 2 * abs(mx - num); // insert mid
			ll b = abs(more - num); // insert beginnning
			
			if (a >= b) {
				more = num;
			}
			dif = min(a, b);
			mx = num;
		} else {
			dif = 0;
		}
		ans += dif;
		//show(ans);
	}
	
	
	show(ans);
	//show("--");
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
