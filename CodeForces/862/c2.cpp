#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
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
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";


void solve (void) {
	ll ans = 0;
	ll n, m, kk;
	cin >> n >> m;

	set<ll> lines;
	rep (i, 0, n) {
		cin >> kk;
		lines.insert(kk);
	}

	vector<vll> v(m, vll(3));
	rep (i, 0, m) {
		rep (j, 0, 3) cin >> v[i][j];
	}
	
	ll mn = *lines.begin();
	ll mx = *lines.rbegin();
	//cout << "par: ";showp(mn, mx);

	rep (i, 0, m) {
		ll fac = (v[i][0] * v[i][2]) << 2;

		ll ta = abs(v[i][1] - mn);
		ll tb = abs(v[i][1] - mx);
		if (ta < tb) {
			kk = mn;
		} else {
			kk = mx;
		}

		ll tmp = min(ta, tb);
		tmp = tmp * tmp;
		//showp(tmp, fac);

		if (tmp < fac) {
			show ("Yes");
			show(kk);
		} else {
			show("No");
		}
	}

	
	cout << endl;
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
