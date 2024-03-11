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
typedef pair<int64_t, int64_t> pii;
typedef vector<int64_t> vint;
typedef vector<int64_t> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<int64_t, int64_t> mpii;
typedef set<int64_t> seti;
typedef multiset<int64_t> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(i_, a_, b_, in_) for (auto i_ = a_; i_ != (b_); i_ += in_)
#define rep(i_, a_, b_) por(i_, a_, b_, 1)
#define each(it_, mp_) for (auto it_ = mp_.begin(); it_ != mp_.end(); it_++)
#define all(c_) c_.begin(), c_.end()
#define allg(c_) all(c_), greater<> ()
#define len(v_) v_.size()
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

int64_t N;
string S;

void	edges(vector<int64_t> &ans, int64_t &i, int64_t &j) {
    while (i < j) {
        if (S[i] == '>') break;
        ans[i] = i + 1;
        i++;
    }
    while (i < j) {
        if (S[j] == '<') break;
        ans[j] = N - j;
        j--;
    }
}

void	solve(void) {
	cin >> N;
    cin >> S;
    int64_t n = N;
	vector<int64_t> ans(n, -1);
    // v[0] = v[n + 1] = 0;
    
    int64_t i = 0, j = N - 1;
    while (i < j) {
        edges(ans, i, j);

        int64_t ri = 0;
        while (S[i + ri] == '>') ri++;
        ans[i] = (2 * ri + 1) + ((i > 0)? ans[i-1] : 0);
        i++;

        if (i >= j) break;
        
        int64_t le = 0;
        while (S[j - le] == '<') le++;
        ans[j] = (2 * le + 1) + ((j+1<n)? ans[j+1] : 0);
        
        break;
    }
	
	showv(ans);
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	
	cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
