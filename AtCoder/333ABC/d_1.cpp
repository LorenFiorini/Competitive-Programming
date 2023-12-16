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

int dfs(vvi &adj, vint &v, int p) {
    int deg = adj[p].size();
    if (deg == 1) {
        v[p] = 1;
    } else if (deg == 2) {
        v[p] = 1;
        int ans = 0;
        for (auto nxt: adj[p]) {
            if (v[nxt] == -1) {
                int res = dfs(adj, v, nxt);
                // ans = min(ans, res);
                ans += res;

            }
        }
        v[p] += ans;
    } else {
        v[p] = 1;
        int ans = 0;
        for (auto nxt: adj[p]) {
            if (v[nxt] == -1) {
                int res = dfs(adj, v, nxt);
                ans += res;
            }
        }
        v[p] += ans;
    }

    
    return v[p];
}

void solve () {
	int ans = 1e9;
	int n;
	cin >> n;
	vvi adj(n);
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (len(adj[0]) < 2) {
        show(1);
        return;
    }
	
    vint v(n, -1);
    // ans = dfs(adj, v, 0);

    v[0] = 0;
    for (auto nxt: adj[0]) {
        v[0] = min(ans, dfs(adj, v, nxt));
    }
    
    ans = v[0] + 1;

    showv(v);
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */ 
