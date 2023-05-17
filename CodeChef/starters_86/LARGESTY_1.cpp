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
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

void count(set<ll> &st, set<ll> &tt, ll num) {

	for (ll a: st) {
		tt.insert((a | num));
	}
	//showset(it, tt);
}

void solve (void) {
	ll n, x, ans = 0;
	cin >> n >> x;
	vll v(n);
	rep (i, 0, n) cin >> v[i];
	
	// the maximum digit 
	ll id = 0;
	while ((1 << id) <= x) {
		id++;
	}

	//showp(id, (1 << id));
	set<ll> st(all(v));
	
	while (id >= 0 ) {
		ll tmp = ans + (1 << id);
		id--;
		if (tmp > x) continue;
		
		set<ll> tt;
		count(st, tt, tmp);
		if (tt.size() < 2) continue;
		
		st.swap(tt);
		ans = tmp;
	}
	

	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini

	//if (ans == 0)
	//if (ans == cur)
	//dfs(v, cur, id - 1); 
//dfs(v, (cur | (1 << id)), id - 1);