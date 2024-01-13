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
#define por(i_, a_, b_, in_) for (ll i_ = a_; i_ < (b_); i_ += in_)
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

// void    solve_m(ll n, vll v, ll m) {
//     rep (i, 0, n) {
//         v[i] %= m;
//     }
// }
vector<ll> divisors_of(ll n) {
    ll N = sqrt(n);
    vector<ll> divisors;
    for (ll i = 1; i <= N; i++) {
        if (n % i == 0) {
            // if (i > 1)
            divisors.push_back(i);
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}


void solve (void) {
	ll ans = 0;
	ll n, k, x;
	cin >> n;
	vll v(n);
    rep (i, 0, n) cin >> v[i];
	

    // solve_m(n, v, 2);
	
    vll di = divisors_of(n);
    // showv(di);

    for (auto k : di) {
        bool ok = 1;
        ll num = v[0] % 2;
        por (i, 0, n, i += k) {
            if (num != (v[i] % 2)) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans += 1;
        }
        // showp(k, ok);

    }
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
