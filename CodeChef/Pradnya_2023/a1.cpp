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
#define showbin(x) for (int i_ = (1 << 10); i_ > 0; i_ >>= 1) {cout << ((x&i_)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";


void solve (void) {
	ll ans = 0, n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	vll val(n, 0);
	ll des = 1, mn = 1e9, mx = 0;
	while (des <= v[0]) {
		des <<= 1;
		des++;
	}

	rep (i, 0, n) {
		ll num = v[i];
		ll cnt = 0;
		showp(v[i], ": ")

		while (num != des) {
			cnt++;
			num = num | (num >> 1);
			show(num);
		}
		val[i] = cnt;
		mn = min(mn, val[i]);
		mx = max(mx, val[i]);
	}

	/*
	showp(mn, mx);

	rep (i, 0, n) {
		showbin((int) v[i]);
		if (mn == val[i]) {
			show(v[i]);
			showbin((int) v[i]);
			//cout << endl;
			//return;
		}
		if (mx == val[i]) {
			show(v[i]);
			showbin((int) v[i]);
			
			//return;
		}
	}*/

	show(ans);
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

/*
a = 5;
b = (a >> 1);
a = a | b;

*/

