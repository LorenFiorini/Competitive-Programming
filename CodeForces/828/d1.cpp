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
typedef map<ll, ll> mpii;
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

vll zero;

ll count(ll num) {
	ll ans = 0;
	while ((num > 0) && num % 2 == 0) {
		ans++;
		num >>= 1;
	}
	return ans;
}

ll fa(ll n) {
	ll ans = 0;
	while ((1 << (ans+1)) <= n) ans++;
	return ans;
}

void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];

	// cuento los zeroes at the end
	ll cnt = 0;
	rep (i, 0, n) {
		cnt += count(v[i]);
	}

	if (cnt < n) {
		mpii mp;
		rep(i, 1, n+1) {
			mp[zero[i]]++;
		}
		//show(n);
		//showmap(it, mp);
		for (auto it = mp.rbegin(); it != mp.rend(); it++) {
			ll maxi = (it->ff) * (it->ss);
			if (cnt + maxi <= n) {
				cnt += maxi;

				ans += it->ss;
			} else {
				ll dif = n - cnt;
				ll K = dif / it->ff + ((dif % it->ff) > 0);

				cnt += K * it->ff;
				ans += K;
			}
			if (cnt >= n) break;
		}

	}

	if (cnt >= n) {
		show(ans);
	} else {
		show(-1);
	}
}


void help() {
	ll mx = 2 * 1e5 + 5;
	zero.resize(mx);
	rep (i, 0, mx) {
		zero[i] = count(i);
	}
}
int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
