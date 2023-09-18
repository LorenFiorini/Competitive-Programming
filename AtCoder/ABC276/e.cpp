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

using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
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
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " <ls < it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second


int n, m;
int d[4] = {0,0,1,-1};
 
bool dfs(vstr &v, int R, int C) {
	vvi vis(n, vint(m, 0));
    int r,c;
    queue<pii> q;
    vis[R][C] = -1;
    if (R+1 < n && v[R+1][C] == '.') {
        q.push({R+1,C});
        vis[R+1][C] = 1;
    }
    if (C+1 < m && v[R][C+1] == '.') {
        q.push({R,C+1});
        vis[R][C+1] = 2;
    }
    if (R > 0 && v[R-1][C] == '.') {
        q.push({R-1,C});
        vis[R-1][C] = 3;
    }
    if (C > 0 && v[R][C-1] == '.') {
        q.push({R,C-1});
        vis[R][C-1] = 4;
    }
    
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        
        rep (i, 0, 4) {
            r = p.ff + d[i];
            c = p.ss + d[3-i];
            if (min(r, c) >= 0 && r < n && c < m && v[r][c] == '.') {
                if (vis[r][c] != 0) {
                    if (vis[r][c] != vis[p.ff][p.ss]) return 1;
                } else {
                    vis[r][c] = vis[p.ff][p.ss];
                    q.push({r,c});
                }
            }
        }
    }
    return 0;
} 
 
void solve () {
	cin >> n >> m;
	vstr v(n);
	rep(i,0,n) cin >> v[i];
	
	rep (i, 0, n) {
	    rep (j, 0, m) {
	        if (v[i][j] == 'S') {
	            if (dfs(v, i, j)) {
	                show("Yes");
	            } else {
	                show("No");
	            }
	            return ;
	        }
	    }
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini