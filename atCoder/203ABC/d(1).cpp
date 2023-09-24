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
#define ff first
#define ss second
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, mp) each(it, mp) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;


void solve () {
	int n, k;
	cin >> n >> k;
	
	vvi v(n, vint(n));
	vvi pre(n, vint(n, 0));
	rep (i, 0, n) {
		rep (j, 0, n) {
			cin >> v[i][j];
			pre[i][j] = v[i][j];
		}
	}
	
	rep (i, 0, n) {
		rep (j, 0, n) {
			if (j == 0 && i > 0) {
				pre[i][j] += pre[i-1][j];
			} else if (j > 0 && i == 0) {
				pre[i][j] += pre[i][j-1];
			} else if (i > 0 && j > 0){
				pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}
	}
	
	pii mnp = mk(-1, -1);
	int mn = 1e9;
	rep (i, k-1, n) {
		rep (j, k-1, n) {
			int val = pre[i][j];
			if (j - k >= 0 && i - k >= 0) {
				val += pre[i-k][j-k];
			}if (j - k >= 0) {
				val -= pre[i][j-k];
			}if (i - k >= 0) {
				val -= pre[i-k][j];
			}
			if (val < mn) {
				mn = val;
				mnp = mk(i, j);
			}
		}
	}
	show(mn);
	showp(mnp.ff, mnp.ss);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

