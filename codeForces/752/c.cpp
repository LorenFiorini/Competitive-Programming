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
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

vint pr;
void primes() {
	ll n = 1e5 + 20;
	vint pri(n);
	rep (i, 2, n) {
		if (pri[i] == 0) {
			pri[i] = i;
			pr.pb(i);
		}
		for (ll j = 0; j < (int)pr.size() && pr[j] <= pri[i] && i*pr[j] <= n; j++) {
			pri[i * pr[j]] = pr[j];
		}
	}
	//showv(pr, len(pr));
}

void solve () {
	ll n;
	cin >> n;
	vint v(n);
	rep(i, 0, n) cin >> v[i];
	
	
	ll p = 0;
	rep (i, 0, n) {
		if (i+2 > pr[p]) p++;
		bool ind = true;
		rep (j, 0, p+1) {
			ind &= (v[i] % pr[j] == 0);
		}
		if (ind) {
			show("NO");
			return;
		}
	}
	
	
	show("YES");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	primes();
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
