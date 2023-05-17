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

ll bin(vll &v, ll left, ll n, ll sum) {
	ll le = left;
	ll ri = n;
	ll mn = sum + v[left-1];
	if (mn > v[n-1]) return n;
	// v[mid] >= mn
	while (le < ri) {
		ll mid = (le + ri) / 2;
		if (v[mid] < mn) {
			le = mid + 1;
		} else if (v[mid] == mn) {
			return mid;
		} else {
			ri = mid;
		}
	}
	return ri;
}

void solve (void) {
	string oi;
	ll ans = 0;
	ll n, q;
	cin >> n >> q;
	vll v(n+1, 0);
	rep (i, 1, n+1) cin >> v[i];
	rep (i, 1, n+1) v[i] += v[i-1];
	//showv(v);

	rep (T, 0, q) {
		ll left, sum;
		cin >> oi >> left >> sum;
		//left--;
		ans = bin(v, left, n, sum);
		show(ans);
	}
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
