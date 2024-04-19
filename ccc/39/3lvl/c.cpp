	
	
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

string S;
int lenS = 0;
    int mnh = 0, mxh = 0;
    int mnw = 0, mxw = 0;


void	get_WD(int &H, int &W) {
    H = 0; W = 0;
    mnh = 0; mxh = 0;
    mnw = 0; mxw = 0;
    
    for (char c: S) {
        if (c == 'S') H++;
        if (c == 'W') H--;
        if (c == 'D') W++;
        if (c == 'A') W--;
        mnh = min(mnh, H);
        mxh = max(mxh, H);
        mnw = min(mnw, W);
        mxw = max(mxw, W);
    }
	// showp(mxh, mnh);
	// showp(mxw, mnw);
    int a = abs(mxh - mnh) + 1;
    int b = abs(mxw - mnw) + 1;
    // showp(a, b);
    H = a;
    W = b;
    // cout << endl;
}

bool check(vvi &vis, int i, int j, vstr &v, int n, int m, int id) {
    // show("Checkoing");
    while (id <= lenS) {
        // if (min(i, j) < 0 || i >= n || j >= m) {
        //     return 0;
        // }
        if (v[i][j] == 'X' || vis[i][j]) return 0;
        vis[i][j] = 1;
        
        if (id >= lenS) break;
        if (S[id] == 'S') i++;
        if (S[id] == 'W') i--;
        if (S[id] == 'D') j++;
        if (S[id] == 'A') j--;
        id++;
    }
    // showmat(vis);
    rep (r, 0, n) {
        rep (c, 0, m) {
            if (v[r][c] != 'X' && vis[r][c] != 1)  {
                return 0;
            }
        }
    }
    return 1;
}

bool	solve(void) {
	int ans = 0;
	int n, m;
	cin >> m >> n;
    vstr v(n);
    rep (i, 0, n) cin >> v[i];
    cin >> S;
    lenS = S.size();

	int h = 0, w = 0;
    get_WD(h, w);
    
    if (h > n || w > m) return false;
    // showp(mnh, mxh);
    // showp(mnw, mxw);

    vvi vis(n, vint(m, 0));    
    if (check(vis, abs(mnh), abs(mnw), v, n, m, 0)) {
        return 1;
    }
	
    return 0;
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	
	cin >> T;
    while (T--) {
        if (solve()) {
            show("VALID");
        } else {
            show("INVALID");
        }
    }
	
	return (0);
}

/* Lorenzo Fiorini */
