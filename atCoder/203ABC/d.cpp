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

void add_column(vvi &v, mpii &mp, int r, int col, int k) {
	mpii :: iterator it;
	rep (i, r, r + k) {
		int num = v[i][col];
		it = mp.find(num);
		if (it == mp.end()) {
			mp.insert(mk(num, 1));
		} else {
			it->ss++;
		}
	}
}

void del_column(vvi &v, mpii &mp, int r, int col, int k) {
	mpii :: iterator it;
	rep (i, r, r + k) {
		int num = v[i][col];
		it = mp.find(num);
		if (it->ss == 1) {
			mp.erase(it);
		} else {
			it->ss--;
		}
	}
}

int check(mpii &mp, int mid) {
	int p = 0;
	int ans;
	each (it, mp) {
		int num = it->ff;
		if (p <= mid) {
			ans = num;
		} else break;
		p += it->ss;
	}
	return ans;
}


void solve () {
	int ans = 1e9;
	int n, k;
	cin >> n >> k;
	int mid = k * k;
	if (mid & 1) mid /= 2;
	else {
		mid /= 2;
		mid--;
	}
	
	vvi v(n, vint(n));
	rep (i, 0, n) {
		rep (j, 0, n) {
			cin >> v[i][j];
		}
	}
	
	
	rep (i, 0, n - k + 1) 
	{
		mpii mp;
		mpii :: iterator it;
		rep (j, 0, k) {
			add_column(v, mp, i, j, k);
		}
		ans = min(ans, check(mp, mid));
		
		rep (j, k, n) {
			del_column(v, mp, i, j - k, k);
			add_column(v, mp, i, j, k);
			ans = min(ans, check(mp, mid));
		}
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

