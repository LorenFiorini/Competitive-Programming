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


void solve () {
    int ans = 0;
	int n;
	cin >> n;
	string s;
    cin >> s;
    string t(all(s));
    sort(all(t));
    // show(s);    
    // show(t);    
    string pre(all(s));
    string pos(all(s));
    rep (i, 1, n) {
        pre[n - i - 1] = max(pre[n - i - 1], pre[n - i]);
        pos[i] = max(pos[i - 1], pos[i]);
    }
    
    char ch = 0;
    string a;
    string b;
    rep (i, 0, n) {
        if (s[i] != t[i]) {
            if (s[i] < pre[i]) {
                show(-1);
                return;
            }
            // if (s[i] < ch && ch != a.back()) {
            if (s[i] < ch) {
                ans++;
            }
            a.pb(s[i]);
            b.pb(t[i]);
            
            ch = 0;
        } else 
        ch = max(ch, s[i]);
    }

    


    // show (a);
    // show (b);
    int m = len(a);
    rep (i, 0, m) {
        // if (t[n-1] != a[0] || a[i] != b[m-1-i]) {
        if (a[i] != b[m-1-i]) {
            show(-1);
            return;
        }
    }

    // showp(ans, m);
    // ans = ans + m - 1;
    // ans = max(ans, m);
    ans = ans + m -1;
    show(ans);
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
