#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
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
//
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a ; i>=(b) ; i-=in)
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

vll bit(30, 1);
void bits() {
	rep (i, 1, 30) {
		bit[i] = bit[i-1] * (ll)2;
	}
}

ll upper(ll num) {
	rep (i, 0, 30) {
		if (bit[i] > num) return bit[i];
	}
	return 0;
}

void solve () {
	ll ans = 1e15 * (-1);
	ll n ,k;
	cin >> n >> k;
	vpii v(n);
	rep (i, 0, n) {
		cin >> v[i].ff;
		v[i].ss = i + 1;
 	}
 	
 	sort(all(v));
 	
 	rep (i, 0, n-1) {
		ll lim = upper(v[i+1].ff);
		rep (j, i+1, n) {
			if (v[j].ff > lim) break;
			ll f = v[i].ss * v[j].ss;
			ll g = k * (v[i].ff | v[j].ff);
			ll dif = f - g;
			if (dif >= ans) {
				ans = dif;
			} 
		}
	}
 	
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bits();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
