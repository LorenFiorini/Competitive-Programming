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
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

int h, w;

bool valid(vvi &v, int r,int c) {
	if (!(r == 0 || r == h-1 || c == 0 || c == w-1)) return false;
	//if (!()) return false;
	rep (i, -1, 2) {
		rep (j, -1, 2) {
			if (i==0 && j==0) continue;
			int R = r+i;
			int C = c+j;
			if (R < 0 || R >= h || C < 0 || C >= w) continue;
			
			if (v[R][C]) {
				return false;
			}
		}
	}
	return true;
}


void solve () {
	cin >> h >> w;
	vvi v1(h, vint(w, 0));
	vvi v2(h, vint(w, 0));
	
	int s1 = 0, s2 = 0;
	
	v1[0][0] = 1;
	rep (i, 0, h) {
		rep (j, 0, w) {
			if (i+j == 0) continue;
			if (valid(v1, i, j)) {
				v1[i][j] = 1;
				s1++;
			}
		}
	}
	
	rep (i, 0, h) {
		rep (j, 0, w) {
			if (i+j == 0) continue;
			if (valid(v2, i, j)) {
				v2[i][j] = 1;
				s2++;
			}
		}
	}
	
	
	if (s2 > s1) {
		v1.swap(v2);
	}
	
	rep (i, 0, h) {
		rep (j, 0, w) {
			cout << v1[i][j];
		}
		cout << "\n";
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
