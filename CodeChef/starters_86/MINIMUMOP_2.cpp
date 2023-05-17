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

bool fun(vint &v) {
	seti st(all(v));
	if (len(st) == 1) {
		show(0);
		return 1;
	}
	return 0;
}
void solve (void) {
	int n, m;
	cin >> n >> m;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	if (fun(v)) return ;

	int GCD = v[0];
	rep (i, 1, n) GCD = gcd(GCD, v[i]);
	if (GCD > 1) {show(1); show(GCD); return;}

	vint ans;
	set<int> st(all(v));
	while (len(st) > 1) {

		auto rit = st.rbegin();
		int gg = *rit; rit++;
		for (; rit != st.rend(); rit++) {
			int hh = gcd(gg, *rit);
			if (hh == gg) continue;
			if (hh == 1) break;
			
			ans.pb(hh);
			gg = hh;
		}
		
		set<int> tt;
		for (auto num: st) {
			if (num < gg) {
				tt.insert(num);
			} else if (num > gg) {
				tt.insert(gcd(num, gg));
			} else {

			}			
		}
		st.swap(tt);
	}

	show(len(ans));
	showv(ans);
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
