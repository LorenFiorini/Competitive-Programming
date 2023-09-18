#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
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

ll n;

ll bs(ll d, vll &v) {
	ll l = 0;
	ll r = n-1;
	
	while (l+1 < r) {
		ll mid = (l + r) / 2;
		
		if (v[mid] == d) {
			return mid;
		} else if (v[mid] > d) {
			l = mid;
		} else {
			r = mid;
		}
		
	}
	return l;
}

void solve () {
	cin >> n;
	vll v(n);
	rep (i,0,n) cin >> v[i];
	sort(allg(v));
	ll suma = accumulate(all(v), 0);
	int m;
	cin >> m;
	
	while (m--){
		ll  coins = 1e18;
		ll d, a;
		cin >> d >> a;
		
		ll p = bs(d, v);
		p = max((ll) 0, p-2);
			//	v[p] hero who attacks
			//while (p > 0 && v[p] < d) p--;
			
			// Stronger Weaker
			//ll l = v[p], r = v[p]; 
			//if (p+1 < n) r = v[p+1];
		
		
		rep (i,0,5) {
			if (p+i >= n) break;
			ll tmp = max((ll) 0, d - v[p+i]);
			tmp += max((ll) 0, a - (suma - v[p+i]));
			coins = min(coins, tmp);
		}
		
		
		show(coins);
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
