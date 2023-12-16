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

int mx = 200001;
int m = 0, n;
vector<int> cnt(mx, 0);
int res = 1e9;
vint vec;

int dfs(vvi &a, vint &v, int i, int id, int sum, int ans) {
    if (i == n) {
        // res = min(res, ans);
        if (ans < res) {
            res = ans; 
            vec = v;
        }
        return 1;
    }
    ans = max(ans, sum);
    int t = a[i][0];
    int x = a[i][1];

    if (t == 1) {
        if (dfs(a, v, i + 1, id + 1, sum, ans))
            return 1;
        if (cnt[x] == 0) {
            cnt[x]++;
            v[id] = 1;
            if (dfs(a, v, i + 1, id + 1, sum + 1, ans))
                return 1;
        }
    } else {
        if (cnt[x] > 0) {
            cnt[x] = 0;
            // sum--;
            if (dfs(a, v, i + 1, id, sum - 1, ans))
                return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

void solve () {
	int ans = 0;
    
	cin >> n;
    vvi a(n, vint(2));
    rep (i, 0, n) {
        cin >> a[i][0] >> a[i][1];
        m += (a[i][0] == 1);
    }
    vint v(m, 0);
	
    if (dfs(a, v, 0, 0, 0, 0)) {
        show(res);
        showv(vec);
    } else {
        show(-1);
    }
	
    
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */ 
