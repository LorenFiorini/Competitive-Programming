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

ll n;
ll ans = 0;
void palin(vll &v, ll i, ll j) {
	ll key = 0;

	while (i >= 0 && j < n ) {
		//rep (id, i, j+1) cout << v[id] << " "; cout << endl;
		// && v[i] == v[j]
		if (v[i] != v[j]) break;
		ans += (j - i + 1) - key;
		i--;
		j++;
	}
}

void solve (void) {
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	ll total = n * (n+1) / 2;
	ll t = 0;
	rep (i, 1, n+1) {
		t += (i * (n+1-i));
	}
	rep (i, 0, n) {
		palin(v, i, i);
		palin(v, i, i+1);
	}

	map<ll, ll> mp;
	for (ll num: v) mp[num]++;
	each(it, mp) {
		if (it->ss < 1) continue; 
		ans += (it->ss + 1) * (it->ss + 2)  / 2;
	}
	//showp(t, ans);
	
	show(t - ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
