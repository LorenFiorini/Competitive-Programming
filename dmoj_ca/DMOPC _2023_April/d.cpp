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
	ll ans = 1, cnt = 1;
	ll n, d, x;
	cin >> n >> d;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	vll dif(n, 0);
	int le = 0;
	x = 0;
	rep (i, 1, n) {
		dif[i] = v[i] - v[le]; 
		//x = max(x, dif[i]);
		if (i==n || dif[i] >= d) {
			ans = max(ans, cnt);
			cnt = 1;
			x = 0;
			le = i;
		} else if (dif[i] >= x) {
			x = max(x, dif[i]);
			cnt++;
			le++;
		}
	}
	ans = max(ans, cnt);

	//showv(v);
	//showv(dif);
	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
/*

ll l = 0, r = 1; 
	ll x = 0, X = d;
	while (r < n) {
		mx_val = X + d;
		if (mx_dif v[r] - v[r-1])
		t = (v[r] - v[l]) % d;
		x = max(x, )
		
	}
*/