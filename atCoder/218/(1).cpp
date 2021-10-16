#include <bits/stdc++.h>
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
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

int n;

vstr get1(vstr &s) {
	int r0, r1, c0, c1;
	r0 = c0 = n+1;
	r1 = c1 = -1;
	rep (i, 0, n) {
		rep (j, 0, n) {
			if (s[i][j] == '#') 
			{
				r0 = min(r0, i);
				r1 = max(r1, i);
				c0 = min(c0, j);
				c1 = max(c1, j);
			}
		}
	}
	vstr ans;
	//int sz = max(c1 - c0, r1 - r0) + 1;
	rep (i, r0, r1 + 1) {
		string str = s[i].substr(c0, c1 - c0 + 1);
		ans.pb(str);
	}
	return ans;
}

bool fin(vstr &sh, vstr &t) {
	int shn = len(sh);
	int shm = len(sh[0]);
	rep (i, 0, n) {
		rep (j, 0, n) {
			bool ok = 1;
			rep (r, 0, shn) {
				rep (c, 0, shm) {
					if (i+r >= n || j+c >= n || t[i+r][j+c] != sh[r][c]) {
						ok = 0;
						break;
					}
				}
			}
			if (ok) return ok;
		}
	}
	return false;
}

void rot(vstr &a) {
	int N = len(a);
	int M = len(a[0]);
    vstr sh;
    
    for (int j = M-1; j >= 0; j--){
		string tmp;
		rep (i, 0, N) {
			tmp.pb(a[i][j]);
		}
		sh.pb(tmp);
	}
    
    //rep (i, 0, len(sh)) show(sh[i]);
    
    a.swap(sh);
}

bool solve (vstr &s, vstr&t) {
	vstr sh = get1(s);
	//rep (i,0,len(sh)) show(sh[i]);
	
	// 0
	if (fin(sh, t)) {
		return 1;
	}
	rot(sh);	
	// 1
	if (fin(sh, t)) {
		return 1;
	}
	rot(sh);	
	// 2
	if (fin(sh, t)) {
		return 1;
	}
	rot(sh);	
	// 3
	if (fin(sh, t)) {
		return 1;
	}
	
	return 0;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	vstr s(n);
	rep (i, 0, n) cin >> s[i];
	vstr t(n);
	rep (i, 0, n) cin >> t[i];
	
	if (solve(s, t)) {
		show("Yes");
	} else 	if (solve(t, s)) {
		show("Yes");
	} else {
		show("No");
	}
	
	
	return 0;
}

// Lorenzo Fiorini
