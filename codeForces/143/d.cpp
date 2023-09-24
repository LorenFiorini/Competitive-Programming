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

ll mod = 998244353;
std::map<std::pair<long long, long long>, long long> memo;

ll combinations(ll n, ll k, ll p) {
	if (n  < k) return 0;
  	if (0 == n) return 0;
  	if (0 == k) return 1;
  	if (n == k) return 1;
  	if (1 == k) return n;
  	map<std::pair<long long, long long>, long long>::iterator it;

  	if((it = memo.find(std::make_pair(n, k))) != memo.end()) {
  	    return it->second;
  	} else {
  	    long long value = (combinations(n-1, k-1,p)%p + combinations(n-1, k,p)%p)%p;
  	    memo.insert(std::make_pair(std::make_pair(n, k), value));
  	    return value;
  	}  
}

void solve (void) {
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];


	/* maximum coloring
	for (ll i = 0; i < n; i += 3) {
		// sort(v.begin() + i, v.begin() + i + 3);
		ll a = v[i] + v[i+1];
		ll b = v[i+1] + v[i+2];
		ll c = v[i+2] + v[i];
		ll mx = max(a, max(b,c));
		ans = (ans + mx) % mod;
	}
	 
	showv(v);
	*/

	ll cnt = 0;
	por (i, 0, n, 3) {
		sort(v.begin() + i, v.begin() + i + 3);
		if (v[i] == v[i+2]) cnt++;
	}
	ans = combinations(n/3, n/6, mod);
	ll k = ans;
	while (cnt > 0) {
		ans = (ans * k) % mod;
		cnt--;
	}

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
2 blue 1 red
1 blue 2 red
	3 3 6 3

N = 4
36 = 2*2 * 3*3
4 choose 2 = 6
0011



N = 2
2 choose 1 = 6

*/
