#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll , ll> pii;
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
#define len(v) (ll) v.size()
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

ll comb(ll n) {
	ll num = n * (n-1);
	num /= 2;
	return num;
}


ll help(vpii &mx, ll n) {
	ll ans = 0;
	if (n==0) return 0;
	rep (i, 0, n-1) {
		// par , impar
		if (mx[i].ff % 2 == 0 && mx[i+1].ff % 2 == 1) {
			ans += min(mx[i].ss, mx[i+1].ss);
		}
	}
	return ans;
}

void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];
	
	vpii mx;
	vll mn;
	for (ll i = 0; i < n-1; i += 2) {
		ll mini = min(v[i], v[i+1]);
		ll value = max(v[i], v[i+1]) - mini;
		if (v[i] == v[i+1]) {
			mn.pb(i);
			mn.pb(i+1);
		} else if (v[i+1] < v[i]) {
			mn.pb(i+1);
			mx.pb({i, value});
		} else {
			mn.pb(i);
			mx.pb({i+1, value});
		}
		ans += mini;
	}
	
	
	ll block = 1;
	bool one = 0;
	ll lenmn = len(mn);
	rep (i, 1, lenmn) {
		if (mn[i] == mn[i-1] + 1) {
			one = !(mn[i] & 1);
			block++;
		} else 
		{
			ll tmp;
			if (block % 2 == 1) {
				tmp = (block + 1) / 2;
			} else {
				if (one) {
					tmp = block / 2 + 1;
				} else {
					tmp = block / 2;
				}
			}
			ans += comb(tmp);
			block = 1;
			one = 0;
		}
		
		if (i+1 == lenmn) {
			ll tmp;
			if (block % 2) {
				tmp = (block + 1) / 2;
			} else {
				if (one) {
					tmp = block / 2 + 1;
				} else {
					tmp = block / 2;
				}
			}
			ans += comb(tmp);
		}
	}
	
	//show(ans);
	
	ans += help(mx, len(mx));
	
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
