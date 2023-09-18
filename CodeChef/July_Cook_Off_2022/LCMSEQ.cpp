#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
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

	//vll v(n);
	//rep(i, 0, n) cin >> v[i];

	// if cntOf[lcm(m,a)-a] == m  then ans++
	// else if cnt >  ...         then ans += (m choose cnt) 

ll mod = 1000000007;
ll binomialCoeff(ll n, ll r){
    if (r > n) return 0;

    ll m = 1000000007;
    ll inv[r + 1] = { 0 };
    inv[0] = 1;
    if (r + 1 >= 2) inv[1] = 1;

    for (ll i = 2; i <= r; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
 
    ll ans = 1;
 
    // for 1/(r!) part
    for (ll i = 2; i <= r; i++) {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }
 
    for (ll i = n; i >= (n - r + 1); i--) {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}

void solve () {
	ll ans = 0;
	ll n, a, b, num;
	cin >> n;
	mpii mp;

	rep(i, 0, n) {
		cin >> num;
		mp[num]++;
	}
	
	each(it, mp) {
		//a = it->ff;
		b = it->ss;
		if (b >= 2) {
			rep(i, 2, b+1) {
				ans += binomialCoeff(b, i);
				ans %= mod;
			}
		}
	}

	show(ans);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
