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

vint pr;
void primes() {
	int N = 1e6 + 1;
	vector<int> v(N, 1);
	rep (i, 2, N) {
		if (v[i])
			pr.pb(i);
		for (int j = i; j < N; j += i) 
			v[j] = 0;
	}
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

bool fun(vint &v) {
	seti st(all(v));
	if (len(st) != 1) return 0;
	show(0);
	return 1;
}

void solve (void) {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	
	// Special Case 0
	if (fun(v)) return ;


	// For gcd > 1 Case
	int GCD = v[0];
	rep (i, 0, n) GCD = gcd(GCD, v[i]);
	if (GCD > 1) {show(1); show(GCD); return;}


	// find the first unused prime <= M
	int N = len(pr);
	vector<bool> used(N, 0);
	rep (i, 0, n) {
		int num = v[i];
		int j = 0;

		while (num > 1) {
			while (num > 1 && num % pr[j] == 0) {
				used[j] = 1;
				num /= pr[j];
			}
			j++;
		}
	}
	rep (i, 0, N) {
		if (pr[i] > m) break;
		if (!used[i]) {
			show(1);
			show(pr[i]);
			return;
		}

	}

	show(2);
	show("2 3");
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	primes();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
