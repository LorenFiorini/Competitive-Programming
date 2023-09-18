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
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second


ll get(vll &v, vpii &sum) {
	//
	ll pos = -1, mn = 1e16;
	ll n = len(v), m = len(sum);
	sort(all(sum));
	rep (i, 0, n) {
		rep (j, 0, m) {
			if (i < sum[j].ff) {
				v[i] += sum[j].ss;
			} else break;
		}
		
		if (v[i] < mn) {
			mn = v[i];
			pos = i;
		}
	}
	vll::iterator it = v.begin();
	v.erase(it + pos);
	return mn;
}

//5000000000
//5000000000

void solve () {
	ll q;
	cin >> q;
	vll v;
	
	// pos , cant
	vpii su;
	
	while (q--) 
	{
		int type;
		cin >> type;
		ll x;
		if (type == 1) {
			cin >> x;
			v.pb(x);
		} else if (type == 2) {
			cin >> x;
			ll upto = v.size();
			su.pb({upto, x});
		} else {
			ll ans = get(v, su);
			show(ans);
			
			su.clear();
		}
	}
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
