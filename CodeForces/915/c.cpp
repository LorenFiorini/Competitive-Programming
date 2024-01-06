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

int lisub(vint &lis, vint &arr, int n, int &last)
{
    
 
    lis[0] = 1;
 
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                last = arr[i];
                lis[i] = lis[j] + 1;
            }
    }

    // show("---");
    // showv(lis);
    return *max_element(all(lis));
}

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	string s;
    cin >> s;
    // vint a(n);
    vint b(n);
    vint lis(n);

    rep (i, 0, n) {
        // a[i] = s[i] - 'a';
        b[n-1-i] = s[i] - 'a';
    }
    int last = b[0];
    ans = lisub(lis, b, n, last);
	
    int mx = *max_element(all(b));

    if (mx != last) {
        show(-1);
    } else {
    	show(ans - 1);

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

/* Lorenzo Fiorini */
