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

ll n, w, h;

bool found(vll &v, ll num) {
	rep (i, 0, n) {
		if (v[i] >= num) {
			v[i] -= num;
			while (i > 0 && v[i-1] > v[i]) {
				swap(v[i-1], v[i]);
				i--;
			}
			return 1;
		}
	}
	return 0;
}

void solve (void) {
	cin >> n >> w >> h;
	vll v(w, h);
	ll num;

	rep (i, 0, n) {
		cin >> num;
		if (found(v, num)) {
			show("YES");
		} else {
			show("NO");
		}
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

/*

void solve (void) {
	int n, w, h;
	cin >> n >> w >> h;
	vpii v(n);
	vint ans(n);
	rep (i, 0, n) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(allg(v));

	int le = 0;
	int ri = n-1;
	while (le < n && v[le].ff > h) le++;
	while (le < ri && w > 0) {
		int stc = v[le].ff + v[ri].ff;
		if (stc <= h) {
			ans[v[le].ss] = 1;
			ans[v[ri].ss] = 1;
			le++;
			ri--;
			w--;
		} else if (v[le].ff <= h) {
			ans[v[le].ss] = 1;
			le++;
			w--;
		}
	}
	if (le == ri && w > 0) {
		ans[v[le].ss] = 1;
	}

	rep (i, 0, n) {
		if (ans[i]) {
			show("YES");
		} else {
			show("NO");
		}
	}
}
*/
