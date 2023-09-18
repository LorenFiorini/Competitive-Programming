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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve (void) {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	vint v(n);
	rep (i, 0, n) cin >> v[i];

	set<int> st(all(v));

	while (len(st) > 1) {

		int gg = *st.begin();
		for (auto num: st) {
			gg = gcd(gg, num);
		}
		// special case when gg == 1

		set<int> tt;
		for (auto num: st) {
			while (num > 1 && num % gg == 0) {
				num /= gg;
				ans++;
			}
			tt.insert(num );
			if (num == 1) break;
		}
		st.swap(tt);
	}

	show(ans);
//for (auto it = mp.begin(); it != mp.end(); it++)
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