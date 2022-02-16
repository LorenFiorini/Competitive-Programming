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
//#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

int L(int a, int b) {
	int ans = 0;
	if (a >= 2 && b >= 4) {
		ans += min(a, b / 2) - 1;
	}
	if (a >= 4 && b >= 2) {
		ans += min(a / 2, b) - 1;
	}
	return ans;
}

void showvv(vvi &v, int n, int m) {
	rep(i,0,n){
		rep(j,0,m) cout << v[i][j] << " ";
		cout << "\n";
	}
}

void solve () {
	ll ans = 0;
	int r, c;
	cin >> r >> c;
	vvi v(r, vint (c));
	rep (i,0,r) rep (j,0,c) cin >> v[i][j];
	
	
	vvi up(r, vint (c, 0));
	vvi down(r, vint (c, 0));
	vvi left(r, vint (c, 0));
	vvi right(r, vint (c, 0));
	rep (i, 0, r) {
		rep (j, 0, c) {
			left[i][c-1-j] = v[i][c-1-j];
			right[i][j] = v[i][j];
			if (j) {
				if (right[i][j]) right[i][j] += right[i][j-1];
				if (left[i][c-1-j]) left[i][c-1-j] += left[i][c-j];
			} 
			up[r-1-i][j] = v[r-1-i][j];
			down[i][j] = v[i][j];
			if (i) {
				if (down[i][j]) down[i][j] += down[i-1][j];
				if (up[r-1-i][j]) up[r-1-i][j] += up[r-i][j];
			}
		}
	}
	/*
	showvv(up, r, c); show("");
	showvv(down, r, c);show("");
	showvv(right, r, c);show("");
	showvv(left, r, c);show("");
	*/
	
	rep (i, 0, r) {
		rep (j, 0, c) {
			ans += L(up[i][j], left[i][j]);
			ans += L(up[i][j], right[i][j]);
			ans += L(down[i][j], left[i][j]);
			ans += L(down[i][j], right[i][j]);
		}
	} 
	
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int C = 1;
	while (C <= T) {
		cout << "Case #" << C << ": ";
		solve();
		C++;
	}
	
	return 0;
}

// Lorenzo
