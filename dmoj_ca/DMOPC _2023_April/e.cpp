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
#define por(i, a, b, in) for (ll i = a; i < (b); i += in)
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

ll mx = 1e6 + 2;
vll pr;
void help() {
	vll pri(mx, 1);
	rep (i, 2, mx) {
		if (!pri[i]) continue;
		pr.pb(i);
		por(j, i, mx, i) pri[j] = 0;
	}
}

void solve (void) {
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	rep (i, 0, n) {
		ll num = v[i];
		ll j = 0;
		ll mx = 0;
		while (num > 1 && num >= pr[j]) {
			ll cnt = 0;
			while (num > 1 && num % pr[j] == 0) {
				num /= pr[j];
				cnt++;
			}
			//showp(pr[j], cnt);
			mx = max(mx, cnt);
			j++;
		}
		if (mx > 1)
		ans += (mx-1);
	}
	if (ans & 1) {
		show("ALICE");
	} else {
		show("BOB");
	}
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();
	solve();
	
	return 0;
}

// Lorenzo Fiorini
