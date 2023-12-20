#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<ll,ll> pll;
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

typedef vector<vpll> vvpll ;
void debug(vvpll &v, ll n, ll m) {
	// Debug
	rep (i, 0, m) {
		show(i);
		rep (j, 0, n) {
			showp(v[i][j].ff, v[i][j].ss);
		}
	}
}

ll get_max(vvpll &v, ll n, ll m) {
	ll ans = 0;
	set<ll> days;

	rep (i, 0, m) {
		// for (auto p: v[id]) {
		// 	if (days.find(p.ss) == days.end()) {
		// 		ans += p.ff;
		// 		days.insert(p.ss);
		// 		break;
		// 	}
		// }
		rep (j, 0, n) {
			if (days.find(v[i][j].ss) == days.end()) {
				ans += v[i][j].ff;
				days.insert(v[i][j].ss);
				break;
			}
		}
	}
	return ans;
}

void solve (void) {
	ll ans = 0;
	ll n, m = 3;
	cin >> n;
	
	vvpll v(m, vpll(n));

	rep (i, 0, m) {
		rep (j, 0, n) {
			cin >> v[i][j].first;
			v[i][j].ss = j;
		}
		// sort(v[i].begin(), v[i].end());
	}
	// sort(v.begin(), v.end());

	
	// debug(v, n, m);
	rep (i, 0, m) {
		sort(v[i].begin(), v[i].end(), greater<>());
	}
	sort(v.begin(), v.end());
	// debug(v, n, m);

	do {
		ll mx = get_max(v, n, m);
		// showp(-1,mx);
		ans = max(ans, mx);
	} while (next_permutation(all(v)));

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
