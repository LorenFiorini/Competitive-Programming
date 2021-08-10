#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll, ll> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
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
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second



bool cool(vint &v, mpii &mp, int l, int r) {
	mp[v[r]] = 0;
	if (v[l] > v[r]) {
		// ... left --- right ...
		return false;
	} 
	
	// NEXT ELEMENT IS GREATER THAN PREVIOUS FOR SURE
	for (mpii::iterator it = mp.find(v[l]); it != mp.end(); it++) 
	{
		//showp(it->ff, it->ss);
		if (it->ff == v[r]) {
			return true;
		} else if (it->ss != (ll) 0) {
			return false;
		}
	}
	show("impossible");
	return 0;
}

void solve () {
	int n, k;
	cin >> n >> k;
	mpii mp;
	vint v(n);
	rep (i, 0, n) {
		cin >> v[i];
		mp.insert({v[i], 1});
	}
	
	if (n == k) {
		show("YES"); 
		return;
	} else if (n < k) {
		show("NO"); 
		return;
	} 
	
	vint sub;
	int l = 0;
	mp[v[0]] = 0;
	rep (i, 1, n) 
	{
		//showmap(it, mp);
		if (cool(v, mp, l, i)) {
			continue;
		} else {
			// pushback the size of the continuos array
			sub.pb((int) (i-l));
			l = i;
		}
	}
	sub.pb(n-l);
	//showv(sub, len(sub));
	
	int sz = len(sub);
	if (sz <= k) {
		show("Yes");
	} else {
		show("No");
	}
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
 
