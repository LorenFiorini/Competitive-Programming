#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pll> vpll;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(i_, a_, b_, in_) for (auto i_ = a_; i_ < (b_); i_ += in_)
#define rpor(i_, a_, b_, dec_) for (auto i_ = a_; i_ < (b_); i_ -= dec_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define rrep(i_, a_, b_) rpor(i_, a_, b_, 1)
#define each(it_, con_) for (auto it_ = con_.begin(); it_ != con_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
#define len(v_) v_.size()
#define precision(d_) cout << setprecision(d_) << fixed;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

// turn {0, 1}
// le {0, 6}
// ri {0, 6}
vector<vector<vll> > dp(2, vector<vll> (7, vll(7, 0)));

ll dfs(vpll &d, vll &a, vll &b, ll le, ll ri, ll A, ll B, bool turn) {
	if (le > ri) {
		return A - B;
	}
	ll ans = 0;
	if (turn == false) {
		// Alice
		ans = -1e12;
		ans = max(ans, dfs(d, a, b, le + 1, ri, A + a[d[le].ss] - 1, B, false == turn));
		ans = max(ans, dfs(d, a, b, le, ri - 1, A + a[d[ri].ss] - 1, B, false == turn));
	} else {
		ans = 1e12;
		ans = min(ans, dfs(d, a, b, le, ri - 1, A, B + b[d[ri].ss] - 1,  false == turn));
		ans = min(ans, dfs(d, a, b, le + 1, ri, A, B + b[d[le].ss] - 1,  false == turn));
	}
	dp[turn][le][ri] = ans;
	return ans;
}

void solve (void) {
	ll ans = 0;
	ll n;
	cin >> n;
	vll a(n);
	for (auto &i : a) cin >> i;
	vll b(n);
	for (auto &i : b) cin >> i;
	
	ll A = 0;
	ll B = 0;
	
	vpll d(n);
	rep (i, 0, n) {
		d[i].ff = a[i] - b[i];
		d[i].ss = i;
	}
	sort(allg(d));

	// Maybe dfs here instead
	ans = dfs(d, a, b, 0, n - 1, A, B, 0);
	// rep (i, 0, 2) {
	// 	cout << char('A' + i) << endl;
	// 	rep (j, 0, n) {
	// 		rep (k, 0, n) cout << dp[i][j][k] << " ";
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
