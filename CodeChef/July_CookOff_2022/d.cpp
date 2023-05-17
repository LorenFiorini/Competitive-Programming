#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
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
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "\n";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

// 00000001110
// 00000111100
// 11110000000
// 00011111000

// 11121223210

void solve () {
	int ans = 0;
	int n, l, r;
	cin >> n;
	vint po(n, 0);
	vint ne(n, 0);
	vint v(n, 0);

	rep(i, 0, n) {
		cin >> l >> r;
		l--; r--;
		po[l]++;
		ne[r]++;
		if (l <= i && i <= r) v[i] = -1e9;
	}

	vint vec;
	int cnt = 0;
	rep(i, 0, n) {
		cnt += po[i];
		v[i] += cnt;
		cnt -= ne[i];
		if (v[i] > 0) {
			ans++;
		}
		if (v[i] == n-1) {
			vec.pb(i+1);
		}
	}
	if (len(vec) > 0) {
		int sz = len(vec);
		show(sz);
		showv(vec, sz);
	} else {
		show(ans);

		rep(i,0,n) {
			if (v[i] > 0) {
				show(i+1);
			}
		}
	}

}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
