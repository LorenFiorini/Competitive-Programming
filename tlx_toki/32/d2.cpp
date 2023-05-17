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

int n, m;

int dfs(vvi &v, vint &used, int p) {
	if (p == m) return 1;
	if (used[v[p][0]] == 1 && used[v[p][1]] == 1) return 0;
	if (used[v[p][0]] == -1 && used[v[p][1]] == -1) return 0;

	int ans;
	//if ((used[v[p][0]] == 1 || used[v[p][1]] == 1) ||
	//	(used[v[p][0]] == -1 || used[v[p][1]] == 1)||
	//	(used[v[p][0]] == 1 || used[v[p][1]] == -1) 
	if (used[v[p][0]] != 0 && used[v[p][1]] != 0){
		ans = dfs(v, used, p + 1);
	} else {
		used[v[p][0]] = 1;
		used[v[p][1]] = -1;
		ans = dfs(v, used, p + 1);
		if (ans) return ans;
		used[v[p][0]] = 0;
		used[v[p][1]] = 0;

		used[v[p][0]] = -1;
		used[v[p][1]] = 1;
		ans = dfs(v, used, p + 1);
		if (ans) return ans;
		used[v[p][0]] = 0;
		used[v[p][1]] = 0;
	}
	return ans;
}

void solve (void) {
	cin >> n >> m;
	vvi v(m, vint(2));
	rep (i, 0, m) {
		cin >> v[i][0] >> v[i][1];
		v[i][0]--; v[i][1]--;
	}

	
	vint used(n, 0);
	int ans = dfs(v, used, 0);
	if (ans) {
		int cnt = 0;
		rep (i, 0, n) cnt += (used[i] != 1);
		
		show(cnt);
		rep (i, 0, n) {
			if (used[i] != 1) {
				cout << (i+1) << " ";
			}
		}
		cout << "\n";
	} else {
		show(-1);
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
