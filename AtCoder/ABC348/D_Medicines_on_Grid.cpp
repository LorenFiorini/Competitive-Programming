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
typedef pair<int, int> pii;
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
#define ro first
#define co second
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
#define showpii(par_) cout << par_.first << ' ' << par_.second << '\n';
#define showv(v_) for (auto a_: v_) {cout << a_ << ' ';} cout << '\n';
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << ' ' << a_->second << '\n';} cout << '\n';

int MX = 1e4;
int dir[4] = {0, 0, 1, -1};

void	bfs(int n, int m, vstr &grid, vvi &dt, pii S) {
    queue<pii> q;

    dt[S.ro][S.co] = 0;
    q.push(S);

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        rep (i, 0, 4) {
            int row = cur.ro + dir[i];
            int col = cur.co + dir[3-i];
            if (min(row, col) < 0 || row >= n || col >= m) continue;
            if (grid[row][col] != '#' && dt[row][col] > dt[cur.ro][cur.co] + 1) {
                dt[row][col] = dt[cur.ro][cur.co] + 1;
                q.push({row, col});
            }
        }
    }
}

bool	dfs(int n, int m, vstr &grid, vvi &dt, map<pii, int> &mp, pii cur, int energy) {

    int cur_energy = energy;
    if (mp.find(cur) != mp.end() && mp[cur] > energy) {
        cur_energy = mp[cur];
        mp[cur] = 0;
    }

    if (dt[cur.ro][cur.co] <= cur_energy) {
        return true;
    }
    if (cur_energy <= 0) {
        return 0;
    }

    rep (i, 0, 4) {
        int row = cur.ro + dir[i];
        int col = cur.co + dir[3-i];
        if (min(row, col) < 0 || row >= n || col >= m || grid[row][col] == '#') continue;

        if (dfs(n, m, grid, dt, mp, make_pair(row, col), cur_energy - 1)) {
            return 1;
        }
    }

    if (cur_energy > energy) {
        mp[cur] = cur_energy;
    }
    return false;
}

bool	solve(int n, int m, int me, vstr &grid, vvi &meds) {
    pii S, T;
    map<pii, int> mp;
    vvi dt(n, vint(m, MX));

    // Meds = Energy
    // i, j ---> Value
    rep (i, 0, me) {
        mp[make_pair(meds[i][0], meds[i][1])] = meds[i][2];
    }
    // Start and end
    rep (i, 0, n) {
        rep (j, 0, m) {
            if (grid[i][j] == 'S') {
                S = make_pair(i, j);
            } else if (grid[i][j] == 'T') {
                T = make_pair(i, j);
            } 
        } 
    }
	
    // check start
    if (mp.find(S) == mp.end())
        return false;

    // distances to the end
    bfs(n, m, grid, dt, S);

    int ans = dfs(n, m, grid, dt, mp, S, 0);
    // rep (i,0,n)	show(grid[i]);    // debug
    // showpii(S);     // debug
    // showpii(T);     // debug
    // show("Map");
    // for (auto p : mp) {
    //     showpii(p.first);
    //     show(p.second);
    // }
    // showmat(dt)
    return ans;
}

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

    
    // INPUT
	int n, m, me;
	cin >> n >> m;
    vstr grid(n);
    rep (i, 0, n) cin >> grid[i];

    cin >> me;
    vvi meds(n, vint(3));
    rep (i, 0, me) {
        rep (j, 0, 3) {
            cin >> meds[i][j];
        }
        meds[i][0]--;
        meds[i][1]--;
    }

    
	if (solve(n, m, me, grid, meds)) {
        show("Yes");
    } else {
        show("No");
    }
	
	return (0);
}

/* Lorenzo Fiorini */
    
    
