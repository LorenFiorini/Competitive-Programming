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
#define por(i_, a_, b_, in_) for (int i_ = a_; i_ < (b_); i_ += in_)
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


int mod = 1e9 + 7;
int MX = 100005;

void help(int *tn, int *C[100005]) {
	//cout << "help" << endl;
	tn[0] = 1;
	C[0][0] = 1;
	C[0][1] = 0;
	rep (i, 1, MX-1) {
		tn[i] = (tn[i-1] * 2) % mod;
		C[i][0] = C[i][i] = 1;
		C[i][i+1] = 0;
		rep (j, 1, i) {
			//cout << i << " " << j << endl;
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
}

void solve(int *tn, int *C[]) {
	//cout << "solve" << endl;
	int ans = 0, n;
	cin >> n;
	vint v(n);
	rep (i, 0, n) cin >> v[i];

	sort(all(v));
	//show(""); showv(v);
	
	rep (i, 0, n) {
		if (v[i] - 1 <= i) {
			ll tmp = (((ll) tn[n-1 - i]) * ((ll) C[i][v[i] - 1])) % mod;
			ans = (ans + (int) tmp) % mod;	
		}
		//showp(1+i, ans);
		//cout << i << ": " << ans << endl;
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	static int tn[100005];
	static int C[100005][100005];
	//cout << "main" << endl;
	help(tn, C);

	int t; cin >> t; while (t--)
	
	solve(tn, C);
	
	return (0);
}

// Lorenzo Fiorini
