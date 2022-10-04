#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
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
#define showv(v, n) rep(i, 0, n) {cout << v[i];} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

bool same(vint &a, vint &b, ll n, ll &shift) {
	ll i = 0, j = 0;

	while (a[i] != b[j]) i++;

	while (j < n && a[(i+j) % n] == b[j]) j++;

	shift = i;
	return (j == n);
}

void solve () {
	ll n, k, shift = 0;
	cin >> n >> k;
	vint a(n);
	vint b(n);
	rep (i, 0, n) cin >> a[i];
	rep (i, 0, n) cin >> b[i];

	//showp(n,k);
	bool ok = same(a, b, n, shift);

	if (ok && ( 
		(n == 2 && (shift == (k%2))) ||
		(n > 2 && shift == 0 && k != 1) ||
		(n > 2 && shift > 0 && k > 0)
		)) {
		show("YES");
	} else {
		show("NO");
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; 
	cin >> T; 
	for (int C = 1; C <= T; C++) {
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
