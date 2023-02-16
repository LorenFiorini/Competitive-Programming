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
	ll n;
	cin >> n;
	vll a(n); 
	vll b(n); 
	vll v(n);
	rep (i, 0, n) cin >> a[i];
	rep (i, 0, n) cin >> b[i];

	//vll pre(n);
	//rep (i, 0, n) {
	//	pre[i] = b[i];
	//	if (i) pre[i] += pre[i-1];
	//}
	ll sum = accumulate(all(b), 0LL);
	//show(sum);

	vll cnt(n);
	rep (i, 0, n) {
		if (a[i] >= sum) {
			cnt[i]++;
			sum -= b[i];
			continue;
		}
		int j = i;
		while (j < n && a[i] > 0) {
			ll dri = min(a[i], b[j]);
			v[j] += dri;
			a[i] -= dri;
			j++;
		}
		sum -= b[i];
	}
	int count = 0;
	rep (i, 0, n) {
		count += cnt[i];
		v[i] += b[i] * count;
	}
	
	showv(v);
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
