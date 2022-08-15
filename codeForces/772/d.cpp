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
typedef map<int,int> mpii;
typedef set<ll> seti;
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

void showbn(ll num) {
	cout << num << " -> ";
	vint v;
	while (num) {
		v.pb(num % 2);
		num >>= 1;
	}
	reverse(all(v));
	showv(v, len(v));
}

void solve () {
	ll mod = 1e9 + 7;
	ll n, p;
	cin >> n >> p;
	vint v(n);
	rep(i,0,n) cin >> v[i];
	/*
	rep (i, 0, 31) {
		int num = 1 << i;
		show(num);
	}*/
	
	seti st(all(v));
	ll mx = 1 << p;
	
	while (!st.empty()) {
		auto it = st.begin();
		int num = *it;
		st.erase(num);
		showbn(num);
		
		ll a = 2 * num + 1;
		ll b = 4 * num;
		if (a < mx) st.insert(a);
		if (b < mx) st.insert(b);
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