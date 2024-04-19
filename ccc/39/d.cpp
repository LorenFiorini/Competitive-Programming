	
	
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef	int64_t	lint;
typedef pair<ll, ll> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll,ll> mpii;
typedef set<ll> seti;
typedef multiset<ll> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(i_, a_, b_, in_) for (auto i_ = a_; i_ != (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
// #define len(v_) v_.size()
#define precision(d_) cout << setprecision(d_) << fixed;
// Debugging Tools
#define show(x_) cout << x_ << '\n';
#define shows(x_) cout << x_ << ' ';
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << '\n';
#define showp(x_, y_) cout << x_ << ' ' << y_ << '\n';
#define showv(v_) for (auto a_: v_) {cout << a_ << ' ';} cout << '\n';
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << ' ' << a_->second << '\n';} cout << '\n';

map< char, vector<int> > dir;

string ans;
int N;

int dfs(int r, int c, int i, vstr &v, vvi &vis) {
    if (i >= N) {
        return 1;
    }
    vis[r][c] = 1;
    if (dfs(r + dir['D'][0], c + dir['D'][1], i + 1, v, vis)) {
        ans.push_back('D');
        return 1;
    }
    if (dfs(r + dir['A'][0], c + dir['A'][1], i + 1, v, vis)) {
        ans.push_back('A');
        return 1;
    }
    if (dfs(r + dir['W'][0], c + dir['W'][1], i + 1, v, vis)) {
        ans.push_back('W');
        return 1;
    }
    if (dfs(r + dir['S'][0], c + dir['S'][1], i + 1, v, vis)) {
        ans.push_back('S');
        return 1;
    }
    vis[r][c] = 0;
    return 0;
}

void	solve(void) {
	ans.clear();
	int n, m;
	cin >> m >> n;
    vstr v(n);
    rep (i, 0, n) cin >> v[i];
	

    // down before X
    int r = -1, c = -1;
    rep (i, 0, n) {
        rep (j, 0, m) {
            if (v[i][j] == 'X') {
                r = i;
                c = j;
                break;
            }
        }
        if (r != -1) break;
    }
    showp(r, c);
    // down after X
    // end
    vvi vis(n, vint(m, 0));
    vis[r][c] = 1;
    N = n * m - 1;
    dfs(r, c+1, 10, v, vis);
	show(ans);
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	dir['S'] = {1, 0};
    dir['W'] = {-1, 0};
    dir['D'] = {0, 1};
    dir['A'] = {0, -1};
	cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
