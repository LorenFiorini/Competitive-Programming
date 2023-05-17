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
#define por(i_, a_, b_, in_) for (ll i_ = a_; i < (b_); i_ += in_)
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

ll mod = 1e9 + 7;

ll MX = 1e5+ 5;
vll vec_2(MX, 1LL);
vector<vll> C(MX, vll(MX));
void help() {
	rep (i, 1, MX) {
		vec_2[i] = (vec_2[i-1] << 1LL) % mod;
	}
	C[0][0] = 1;
	rep (i, 1, MX) {
		rep (j, 1, i + 1) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
}

void solve () {
	ll ans = 0, n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	sort(all(v));
	//show(""); showv(v);
	
	rep (i, 0, n) {
		if (v[i] - 1LL <= i) {
			ll tmp = (vec_2[n - (i + 1LL)] * C[i][v[i] - 1LL]) % mod;
			ans = (ans + tmp) % mod;	
		}
		//showp(1+i, ans);
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();

	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
