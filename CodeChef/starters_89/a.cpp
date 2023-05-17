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
map<int, int> dp;

int dfs(int n) {
	if (n == 0) return 1;
	if (mp[n] == 0) {
		mp[n] = dfs()
	}
}

void help() {
	set<int> st;
	st.insert(0);

	rep (i, 1, mx) {

		for (auto num: st) {
			st.insert(num + 2);
			st.insert(num - 1);
		}

		dp[i] = st.size();
	}
}
*/
//int mx = 1e6 + 1;
//vint dp(mx, 1);

int ran = (1e6) * 3 + 5;
vint dp(ran, 1);
int zero = 1e6 + 1;

void help() {
	vector<bool> vis(ran, 0);

	// left most and right most number id
	int le, ri, cnt = 1;
	le = zero;
	ri = zero;
	vis[zero] = 1;
	vis[zero-1] = 1;

	rep (t, 1, ran) {
		//cout << t << endl;
		// 1. count new generated numbers from le to 0, from ri to ran
		// 2. move le and ri to their new positions

		// for left--

		cnt = 1;
		//if (le > 0) {
		//	le--;
		//	vis[le] = 1;
		//}


		//int j = ri - 1;
		int j = le;

		while (j < min(ran, ri + 2)) {
			if (vis[j]) {
				if (j+2 < ran && !vis[j+2]) {
					vis[j+2] = 1;
					cnt++;
				}
				if (!vis[j-1]) {
					vis[j-1] = 1;
					cnt++;
				}
			}
			j++;
		}

		ri += 2;
		while (le+1 < ri && vis[le+1]) le++;
		//while (ri+1 < ran && vis[ri+1]) ri++;

		dp[t] = dp[t - 1] + cnt;
	}
	//cout << "help() done" << endl;
}

void solve (void) {
	int n;
	cin >> n;

	//n += zero;
	show(dp[n]);
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
