#include <bits/stdc++.h>
using namespace std;
#define INF (ll)1e10
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
#define tem first
#define pos second
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


void read(vll &v, ll k) {
	vll a(k);
	rep (i, 0, k) cin >> a[i];
	rep (i,0,k) {
		ll t;
		cin >> t;
		v[a[i] - 1] = t;
	}
}



void solve () {
	ll n, k;
	cin >> n >> k; 
	vll v(n, INF); 
	read(v, k);
	
	pii mn = {INF, INF};
	rep (i, 0, n) {
		ll dis = abs(mn.pos - i);
		v[i] = min(v[i], mn.tem + dis);
		if (v[i] < mn.tem + (dis)) {
			mn.tem = v[i];
			mn.pos = i;
		}
	}
	
	mn = {INF, INF};
	rrep (i, n, 0) {
		ll dis = abs(mn.pos - i);
		ll num = mn.tem + dis;
		if (v[i] < num) {
			mn.tem = v[i];
			mn.pos = i;
		} else {
			v[i] = num;
		}
	}
	
	showv(v, n);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int te; cin >> te; while (te--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
