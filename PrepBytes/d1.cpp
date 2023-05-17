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

ll mod = 1e9 + 7;
ll N;
vector<vector<vector<ll>>> dp;

ll dfs(ll A, ll B, ll C, ll cur) {
	if (cur == N) return 1;
	if (dp[A][B][C] != -1) return dp[A][B][C];

	//cout << A << " " << B << " " << C << endl;
 	dp[A][B][C] = 0;

	if (C >= 3)
		dp[A][B][C] = (dp[A][B][C] + dfs(A, B, C - 3, cur + 6) ) % mod;
	
	if (B >= 2 && C >= 1)
		dp[A][B][C] = (dp[A][B][C] + dfs(A, B - 2, C - 1, cur + 6) ) % mod;

	ll p = 2;
	while (B>=p && C>= p)
	{
		dp[A][B][C] = (dp[A][B][C] + dfs(A, B - p, C - p, cur + 4*p) ) % mod;
		p++;
	}

	if (B >= 2)
		dp[A][B][C] = (dp[A][B][C] + dfs(A, B - 2, C, cur + 4) )% mod;

	if (min(A,C) > 0)
		dp[A][B][C] = (dp[A][B][C] + dfs(A - 1, B, C - 1, cur + 4) ) % mod;
	

	if (A)
		dp[A][B][C] = (dp[A][B][C] + dfs(A - 1, B, C, cur + 2) )% mod;

	return dp[A][B][C];
}

void solve (void) {
	ll ans = 0;
	ll a,b,c,n;
	cin >> n >> a >> b >> c;
	N = 2 * n;
	dp.resize(a+1, vector<vll> (b+1, vll(c+1 , -1)));
	//for (auto lvl: dp) showmat(lvl);

	if (b % 2 == 0)
		ans = dfs(a, b, c, 0);

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
