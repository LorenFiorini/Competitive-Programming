#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define mod (ll) 1000000007
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
#define one first
#define sz second

ll solve (ll ans, ll leng) {
	ll p = 1;
	while (--(leng)) {
		p <<= (ll) 1;
		p %= mod;
	}
	
	ans *= p;
	ans %= mod;
	
	return ans;
}


void fib(int n, mpii &mp) {
	
	vector<vll> v(2, vll(2, 1));
	v[0][0] = 0;
	mp[0] = 0;
	mp[1] = 1;
	rep (i, 2, n+1) {
		ll ones = v[0][0] + v[0][1];
		ll sz = v[1][0] + v[1][1];
		// move to first
		v[0][0] = v[0][1];
		v[1][0] = v[1][1];
		// move to second
		v[0][1] = ones;
		v[1][1] = sz;
		if (mp[i] == -1) {
			mp[i] = solve(ones, sz);
		}
	}
	return;
}


int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, mx = 0; 
	cin >> t;
	vint nums(t);
	mpii mp;
	rep (i, 0, t) {
		cin >> nums[i];
		mp[nums[i]] = -1;
		mx = max(mx, nums[i]);
	}
	
	
	fib(mx, mp);
	
	rep (i, 0, t) {
		
		cout << mp[nums[i]] << "\n";
	}
	
	return 0;
}

// Lorenzo Fiorini
