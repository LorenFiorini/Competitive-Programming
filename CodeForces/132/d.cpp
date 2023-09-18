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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

int he(vvi &v, ll m, ll sz, ll le, ll ri) {
	ll len = ri - le + 1;
	ll j = 0;
	while ((1 << (j + 1)) <= len) j++;
	return max(v[le-1][j], v[ri - (1 << j)][j]);
}

void solve () {
	bool ok = 0;
	ll n, m, q;
	cin >> n >> m;
	vint v(m);
	rep(i, 0, m) cin >> v[i];

	ll sz = 0;
	while ((1 << (sz)) <= m) sz++;
	vvi spa(m, vint(sz, 0));

	rep(i, 0, m) spa[i][0] = v[i];
	for (int j = 1; j < sz; j++) {

		for (int i = 0; i + (1 << j) - 1 < m; i++) {
			//  i + (1 << j) - 1 < n
			// i+(1 << (j-1))
			spa[i][j] = max(spa[i][j-1], spa[i+(1 << (j-1))][j-1]);
		}
	}
	//showvv(spa, m, sz);
	//cout << endl;

	int xs, ys, xt, yt, k;
	int dx, dy;
	cin >> q;
	while (q--) {
		cin >> ys >> xs >> yt >> xt >> k;
		if (xt < xs) {
			swap(xt, xs);
			swap(yt, ys);
		}
		dx = abs(xs - xt);	dy = abs(ys - yt);
		ok = 1;
		if ((dx % k != 0) || (dy % k != 0)) {
			ok = 0;
		} else {
			ok = 0;
			ll mx = he(spa, m, sz, xs, xt);
			ll N = abs(ys - n);
			mx -= ys;

			ll tmp = k * (N / k);
			if (tmp > mx) ok = 1;

		}


		if (ok) {
			show("YES");
		} else {
			show("NO");
		}
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
