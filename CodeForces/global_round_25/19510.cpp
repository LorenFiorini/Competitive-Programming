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
#define showmap(mp_) for (auto a_: mp_) {cout << a_.first << ' ' << a_.second << '\n';} cout << '\n';


bool	solve(void) {
	int ans = 0;
	int n;
	cin >> n;
	string s; cin >> s;

    int cnt[2] = {0,0};
    vint color(n);
    rep (i, 0, n) {
        cnt[s[i] - '0']++;
    }
    if (cnt[1] % 2) return 0;

	while (cnt[1] > 0) {
		map<int, int> mp;
		map<int, vint> pm;
		rep (i, 0, n) {
			if (s[i] == '1') {
				mp[i] = 1;
				if (i > 0 && s[i-1] == '1') {
					mp[i]++;
				}
				if (i+1 < n && s[i+1] == '1') {
					mp[i]++;
				}
				pm[mp[i]].push_back(i);
			}
		}
		vint tmp;
		for (int i = 3; i > 0; i--) {
			for (int id: pm[i]) {
				tmp.push_back(id);
			}
		}
		// showv(tmp);
		int a = -1;
		int b = -1;
		int sz = tmp.size();
		if (sz) {
			a = tmp[0];
			rep (j, 0, sz) {
				if (abs(a - tmp[j]) > 1) {
					b = tmp[j];
					break;
				}
			}
		}
		if (a >= 0 && b == -1) return 0;
		
		s[a] = '0';
		s[b] = '0';
		// show(s);
		cnt[1] -= 2;
	}

    return 1;
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	
	cin >> T;
    while (T--) {
        int ans = solve();
        if (ans) {
            show("YES");
        } else {
            show("NO");
        }
    }
	return (0);
}

/* Lorenzo Fiorini */
