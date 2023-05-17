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

struct Line {
	ll a;
	ll b;
	ll c;
};

void print_line(Line x) {
	cout << x.a << " ";
	cout << x.b << " ";
	cout << x.c << endl;
}

ll gcd(ll p, ll q) {
	if (q == 0) return p;
	return gcd(q, p % q);
}

void solve (void) {
	ll ans = 0;
	Line x;
	Line y;
	cin >> x.a >> x.b >> x.c;
	cin >> y.a >> y.b >> y.c;

	ll A = max(x.a, 1LL) * max(x.b, 1LL) * max(x.c, 1LL);
	ll B = max(y.a, 1LL) * max(y.b, 1LL) * max(y.c, 1LL);
	x.a *= A * B;
	x.b *= A * B;
	x.c *= A * B;
	//y.a *= A * B;
	//y.b *= A * B;
	//y.c *= A * B;
	// check whther overlap
	ll ga = gcd(abs(x.a), abs(y.a));
	//ll gb = gcd(abs(x.b), abs(y.b));
	//ll gc = gcd(abs(x.c), abs(y.c));
	if ((x.b%ga == 0) && (y.b%ga == 0) && (x.c%ga == 0) && (y.c%ga == 0)) {
		//x.a /= ga;
		//x.b /= ga;
		//x.c /= ga;
		//y.a /= ga;
		//y.b /= ga;
		//y.c /= ga;

		if (((!y.a || x.a%y.a == 0) && (!y.b || x.b%y.b == 0) && (!y.c || x.c%y.c == 0)) ||
			((!y.a || !y.b || x.a / y.a == x.b / y.b) && (!y.a || !y.c || x.a / y.a == x.c / y.c))) {
			ans = -1;
		} else {
			ans = 1;
		}
	}

	print_line(x);
	print_line(y);
	show(ans);
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
