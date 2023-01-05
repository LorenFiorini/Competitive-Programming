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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

/*
4 19
5 7 10 11

*/
void solve () {
	ll ans = 1e9;
	ll n, l;
	cin >> n >> l;
	vll a(n);
	rep(i,0,n) cin >> a[i];

	// Distances
	ll N = 4* n + 1;
	vll v(N);
	v[0] = 2 * a[0];
	v[n] = 2* (l - a[n-1]);
	rep (i, 1, n) {
		v[i] = a[i] - a[i-1];
	}
	rep (j, 1, 4) {
		rep (i, 1, n+1) {
			v[j * n + i] = v[j * n - i];
		}
	}

	ll sum = 0;
	ll i = 0, j = 0;
	while (1) {
		// Next to be added is J
		while (sum < l && j < N) {
			sum += v[j];
			j++;
		}
		if (sum >= l) {
			ans = min(ans, 2 * sum);
			if (sum == l) break;
		} else break;
		while (sum > l) {
			sum -= v[i];
			i++;
		}
	}
	
	//showv(v, N);
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
