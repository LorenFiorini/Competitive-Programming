#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef map<int,int>  :: iterator mit;
typedef set<int> :: iterator sit;
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
#define showp(x, y) cout << x << " "<< y << "\n";
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
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	
	multimap<ll, pii> mp;
	//multimap<int, pii> :: iterator it1;
	
	ll f = 0;
	ll dif = 0;
	rep (i, 1, n) 
	{
		if (i == 1) {
			dif = v[i] - v[i - 1];
			continue;
		}
		
		if (v[i] - v[i-1] == dif) {
			continue;
		} else {
			mp.insert(mk( dif, mk(f, i-1) ));
			dif = v[i] - v[i-1];
			f = i - 1;
		}
	}
	mp.insert(mk( dif, mk(f, n-1) ));
	
	// longest
	each (it, mp) {
		ll le = it->ss.ss - it->ss.ff + 2;
		ans = max(ans, le);
	}
	if (ans >= n) {
		cout << n << "\n";
		return;
	}
	
	// two segments
	vector< pair<ll, pii> > it1;
	each (it, mp) {
		ll pr = it->ff;
		pii pa = mk(it->ss.ff, it->ss.ss);
		it1.pb(mk(pr, pa));
	}
	
	
	
	rep (i, 1, len(it1)) 
	{
		ll ky = it1[i-1].ff;
		ll pos = it1[i-1].ss.ss;
		ll ln = pos - it1[i-1].ss.ff + 2;
		
		if (it1[i].ff == ky) {
			ll posi = it1[i].ss.ff;
			if (pos + 2 == posi && v[posi] == v[posi-2] + 2 * ky) {
				// actualiyar max len
				ans = max(ans, ln + (it1[i].ss.ss - it1[i].ss.ff + 1) );
				//cout << ans << "here \n";
			}
		} else continue;
	}
	
	if (ans >= n) {
		cout << n << "\n";
		return;
	}
	
	
	/*
	cout << "\n";
	each(it, mp) {
		cout << it->ff << " " << it->ss.ff << " " << it->ss.ss;
		cout << "\n";
	}
	*/
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int C = 1;
	while (C <= T) {
		cout << "Case #" << C << ": ";
		solve();
		C++;
	}
	
	return 0;
}
