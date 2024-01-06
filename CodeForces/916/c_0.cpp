#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

// Current sum, K left => maximum possible

ll dfs(map<pll, ll> &dp, vll &a, vll&b,
	ll n, ll k, ll sum, ll id, ll mxb) {

	if (k == 0)
		return sum;
	auto par = make_pair(sum, k);
	if (dp.find(par) == dp.end()) {
		ll ans = 0;
		if (id < n)
			ans = max(ans, dfs(dp, a, b, n, k - 1, sum + a[id], id + 1, max(mxb, b[id])));
		ans = max(ans, dfs(dp, a, b, n, k - 1, sum + mxb, id, mxb));
		dp[par] = ans;
	}
	return dp[par];
}

void solve (void) {
	map<pll, ll> dp;
	ll n , k;
	cin >> n >> k;
	vll a(n);
	for (auto &i : a) cin >> i;
	vll b(n);
	for (auto &i : b) cin >> i;
	
	ll ans = dfs(dp, a, b, n, k-1, a[0], 1, b[0]);

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
