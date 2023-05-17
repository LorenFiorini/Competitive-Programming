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

ll n, x, ans;

int dfs(vll &v, ll cur, ll id) {
	if (cur > x) return 0;
	//if (id < 0) return ;

	// Search for 2 numbers that make B-array different
	ll cnt = 0;
	ll tmp;
	rep (i, 0, n) {
		cnt += ((v[i] | cur) != v[i]);
		if (cnt == 2) break;
	}
	
	if (cnt < 2) return 0;
	ans = max(ans, cur);
	if (id < 0) return cur;
	
	for (int i = id; i >= 0; i--) {
		tmp = dfs(v, (1 << i), i - 1);
		if (tmp) return tmp;
	}
	return 0;
}

void solve (void) {
	ans = 0;
	cin >> n >> x;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	sort(allg(v));
	
	ll m = x, id = 0, tmp = 0;
	while ((m ^ (1 << id)) > 0) {
		if (m & (1 << id)) {
			m = (m ^ (1 << id));
		}
		id++;
	}
	showp(id, m);
	for (int i = id; i >= 0; i--) {
		tmp = dfs(v, (1 << i), i - 1);
		if (tmp) break;
	}
	
	showp(tmp, ans);
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