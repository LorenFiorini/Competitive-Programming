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
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
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
1 
5 5 2 
16 94 62 67 91
2 3 3 4
1 1 69
2 3 1 4
2 1 1 1
2 3 2 2
*/
map<pii, ll> mp;
map<pii, ll>::iterator it;


ll V(ll num, ll p) {
	it = mp.find(mk(num, p));
	if (it != mp.end()) {
		return it->ss;
	}
	ll ansv = 0;
	vll vec;
	while (num != 0 && num % p == 0) {
		vec.pb(num);
		num /= p;
		ansv++;
	}
	rep (i, 0, len(vec)) {
		mp[mk(vec[i], p)] = ansv - i;
	}
	return ansv;
}


ll help(vll &v, ll ex, ll l, ll r, ll prime) {
	ll ans = 0;
	rep (i, l, r + 1) {
		ll num = pow(v[i], ex) - pow((v[i] % prime), ex);
		ll res = V(num, prime);
		ans += res;
		//cout << num << " " << res << "\n";
	}
	return ans;
}

void solve () {
	ll n, p, q;
	cin >> n >> q >> p;
	vll v(n + 1, 0);
	rep (i, 1, n+1) cin >> v[i];
	
	
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			ll pos, val;
			cin >> pos >> val;
			v[pos] = val;
		} else {
			ll s, l, r;
			cin >> s >> l >> r;
			ll answer;
			answer = help(v, s, l, r, p);
			cout << answer << " ";
		}
	}
	cout << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
