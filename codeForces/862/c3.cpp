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

ll bin(vll& li, ll n, ll val) {
	ll le = 0;
	ll ri = n - 1;

	while (le < ri) {
		ll mid = (le + ri) / 2;
		if (li[mid] == val) {
			return li[mid];
		} else if (li[mid] < val) {
			le = mid + 1;
		} else {
			ri = mid;
		}
	}
	if (le > 0 && abs(val - li[le - 1]) < abs(val - li[le])) {
		le--;
	}
	return li[le];
}

void solve (void) {
	ll ans = 0;
	ll n, m;
	cin >> n >> m;

	vector<ll> li(n);
	rep (i, 0, n) {
		cin >> li[i];
	}
	sort(all(li));

	vector<vll> v(m, vll(3));
	rep (i, 0, m) {
		rep (j, 0, 3) cin >> v[i][j];
	}
	

	rep (i, 0, m) {
		ll fac = (v[i][0] * v[i][2]) << 2;

		
		ll K = bin(li, n, v[i][1]);

		ll tmp = v[i][1] - K;
		tmp = tmp * tmp;
		

		if (tmp < fac) {
			show ("Yes");
			show(K);
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
