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

vll ri;
set<ll> st;
ll N;
map<ll, ll> dp;

void help() {
	ll cnt = 0;
	ll i = 1;
	while (cnt <= 1e6) {
		cnt += i;
		i++;

		ri.pb(cnt);
		st.insert(cnt);
		//st.insert(cnt+1);
	}
	N = ri.size();
	// 1414
	//show(N); 
	//showv(ri);
	dp[0LL] = 0LL;
	dp[1LL] = 1LL;
}

ll bin_search(ll num) {
	ll l = 0;
	ll r = N-1;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (ri[mid] == num) {
			return mid;
		} else if (ri[mid] < num) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}

ll dfs(ll num, ll row) {
	if (num < 2) return num;
	if (dp.find(num) != dp.end()) return dp[num];

	ll iz = 0, der = 0, ok = 0;
	if (st.find(num-1) == st.end()) {
		iz = dfs(num-row-1, row - 1);
		ok++;
	}
	if (st.find(num) == st.end()) {
		// not right most
		der = dfs(num-row, row - 1);
		ok++;
	}
	dp[num] = num * num + iz + der;
	if (ok == 2) {
		dp[num] -= dp[num - row - (row-1)];
	}
	return dp[num];
}

void solve (void) {
	ll n;
	cin >> n;

	// find row
	ll row = bin_search(n);
	//show(row);


	ll ans = dfs(n, row);
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
