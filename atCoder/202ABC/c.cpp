#include <bits/stdc++.h>
using namespace std;
#define INF (ll)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vll;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vll> vvi;
typedef map<ll,ll> mpii;
typedef set<ll> seti;
typedef multiset<ll> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
//
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (ll i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (ll) v.size()
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
	ll ans = 0;
	ll n;
	cin >> n;
	
	mpii mpa;
	mpii mpb;
	vll b(n);
	mpii :: iterator it;
	rep (i, 0, n) {
		ll num;
		cin >> num;
		it = mpa.find(num);
		if (it == mpa.end()) {
			mpa.insert(mk(num, 1));
		} else {
			it->ss++;
		}
	}
	rep (i, 0, n) cin >> b[i];
	rep (i, 0, n) {
		ll id;
		cin >> id;
		id--;
		
		ll num = b[id];
		it = mpb.find(num);
		if (it == mpb.end()) {
			mpb.insert(mk(num, 1));
		} else {
			it->ss++;
		}
	}
	
	each(itt, mpa) {
		it = mpb.find(itt->ff);
		if (it != mpb.end()) {
			ll cant = itt->ss * it->ss;
			ans += cant;
		}
	}
	
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//ll t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

