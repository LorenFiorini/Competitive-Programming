#include "bits/stdc++.h"
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
#define por(I_, A_, B_, in__) for (int I_ = A_; I_ < (B_); I_ += in__)
#define rep(I_, A_, B_) por(I_, A_, B_, 1)
#define each(it, MP) for (auto it = MP.begin(); it != MP.end(); it++)
#define all(C_) C_.begin(), C_.end()
#define allg(C_) all(C_), greater<> ()
#define len(V_) (int) V_.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(X_) cout << X_ << "\n";
#define showbin(X_) for (int I = (1 << 30); I > 0; I >>= 1) {cout << ((X_&I)? 1: 0);} cout << "\n";
#define showp(X_, Y_) cout << X_ << " " << Y_ << "\n";
#define showv(V_) for (auto A_: V_) {cout << A_ << " ";} cout << "\n";
#define showvp(V_) for (auto P_: V_) {out_p(P_.first, P_.second);}
#define showmat(MAT) for (auto R_: MAT) {out_v(R_);}
#define showset(ST) for (auto X_: ST) {cout << X_ << " ";} cout << "\n";
#define showmap(MP) for (auto P_: MP) {cout << P_.first << " " << P_.second << "\n";} cout << "\n";

/*
Problem: Swapping Pairs
Link   : https://www.hackerearth.com/challenges/competitive/march-circuits-21/algorithm/swapping-pairs-6f0aadb9/
dynamic programming
*/

int n, m;

bool dfs(vvi &dp, vvi &v, int i, int cur_sum) {
	if (i == n) return cur_sum == m;
	if (cur_sum > m) return false;
	if (dp[i][cur_sum]) return false;

	if (dfs(dp, v, i + 1, cur_sum + v[i][0])) return true;
	if (dfs(dp, v, i + 1, cur_sum + v[i][1])) return true;
	dp[i][cur_sum] = 1;
	return false;
} 


void solve (void) {
	int ans = 0;
	cin >> n >> m;
	vvi v(n, vint(2));
	rep(i, 0, n) {
		cin >> v[i][0] >> v[i][1];
		if (v[i][0] > v[i][1]) swap(v[i][0], v[i][1]);
	}
	vvi dp(n, vint(m + 1, 0));

	if (dfs(dp, v, 0, 0)) {cout << "YES\n";}
	else {cout << "NO\n";}
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
