#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
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
#define ff first
#define ss second
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 5); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

map<ll, ll> mp;
ll n, k; 

ll dfs(vll &v, ll used, ll pos) {
	if (mp.find(used) != mp.end()) {
		return mp[used];
	}

	mp[used] = 1e9;
	ll A = max(0LL, pos-k);
	ll B = min(n-1, pos+k);

	for (ll val = A; val <= B; val++) {
		if ((1 << val) & used) continue;
		ll t = used | (1 << val);

		ll change = abs(val - v[pos]);
		if (change >= mp[used]) break;

		ll tmp = dfs(v, t, pos + 1);
		
		mp[used] = min(mp[used], tmp + change);
	}
	return mp[used];
}

void solve (void) {
	mp.clear();
	cin >> n >> k;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	ll mx = (1 << n) - 1;
	mp[mx] = 0;
	

	ll ans = dfs(v, 0, 0);
	showmap(it,mp);

	show(mp[0]);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
