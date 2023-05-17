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
#define por(i_, a_, b_, in_) for (int i_ = a_; i < (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
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

bool dfs(set<ll> &memo, vll& vec, ll i, ll sum, ll n, ll N) {
	if (sum == n) return true;
	if (sum > n || i == N) return false;

	if (memo.find(sum) != memo.end()) {
		return false;
	}
	memo.insert(sum);

	// without current element
	if (dfs(memo, vec, i+1, sum, n, N)) return 1;
	// with current element
	if (dfs(memo, vec, i+1, sum + vec[i], n, N)) return 1;
	
	return 0;
}

bool fun(ll m, ll n) {
	set<ll> memo;
	vll vec;

	vec.pb(m);
	while (m % 2 == 0 && m > 0) {
		m /= 2;
		vec.pb(m);
		if (m == n) return 1;
	}

	return n % m == 0;
	//return dfs(memo, vec, 0, 0, n, vec.size());
}

void solve () {
	ll ans = 0;
	ll m, n;
	cin >> m >> n;
	
	if (m >= n) {
		ans = fun(m, n);
	}
	
	
	if (ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
