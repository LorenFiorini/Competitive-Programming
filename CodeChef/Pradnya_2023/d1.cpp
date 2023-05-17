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

int n, k;

void dfs(vint &v, vint &used, int pos, int &ans, int cur) {
	if (pos == n) {
		ans = min(ans, cur);
		return;
	}

	//used[v[pos]] =
	for (int val = max(0, pos-k); val <= min(n-1, pos+k); val++) {
		if (!used[val]) {
			
			//int tmp = min(abs(mn - v[i]), abs(mx - v[i]));
			//if (mn <= v[i] && v[i] <= mx) tmp = 0;

			used[val] = 1;
			dfs(v, used, pos + 1, ans, cur + abs(val - v[pos]));
			used[val] = 0;
		}
	}

}

void solve (void) {
	int ans = 1e9;	
	cin >> n >> k;
	vint v(n);
	rep (i, 0, n) cin >> v[i];

	vint vis(n, 0);
	dfs(v, vis, 0, ans, 0);
	
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
