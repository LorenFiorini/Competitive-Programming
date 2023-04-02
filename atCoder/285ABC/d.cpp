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


bool dfs(map<string, string> &mp, map<string, bool> &vis, string cur) {
	if (vis[cur]) return 0;
	vis[cur] = 1;
	if (mp.find(cur) != mp.end()) {
		return dfs(mp, vis, mp[cur]);
	}
	return 1;
}

bool count(map<string, bool> &vis) {
	int ans = 0;
	for (auto p: vis) {
		ans += p.ss;
	}
	return ans == len(vis);
}

void solve (void) {
	int ans = 0;
	int n;
	cin >> n;
	// future -> present
	map<string, string> mp;
	map<string, bool> vis;
	set<string> A;
	set<string> B;
	string a, b;

	rep (i, 0, n) {
		cin >> a >> b;
		A.insert(a);
		B.insert(b);
		mp[b] = a;
		vis[b] = 0;
	}

	if (len(A) < n || len(B) < n) {
		show ("No");
		return;
	}

	bool ok = 1;
	each(it, B) {
		if (A.find(*it) == A.end() && !vis[*it]) {
			ok &= dfs(mp, vis, *it);
		}
	}

	if (ok && count(vis)) {
		show("Yes");
	} else {
		show ("No");
	}
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
