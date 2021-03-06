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
#define ff first
#define ss second
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
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

vll fac(1 ,1);


void factorial(int n) {
	rep (i, 1, n+1) {
		ll num = (ll) fac[i-1] * (ll) i;
		num %= MOD;
		fac.pb(num);
	}
}


void solve () {
	ll ans = 0;
	int n;
	cin >> n;
	int fn = 0;
	mpii mp;
	mpii ::iterator mit;
	rep (i, 0, n) {
		int nu;
		cin >> nu;
		int cnt = 0;
		while(nu > 0) {
			int num = (nu % 10) % 2;
			if (num == 1) {
				if (notin(mp, cnt)){
					mp.insert(mk(cnt, 1));
				}					
				else {
					mit = mp.find(cnt);
					mit->second++;
					fn = max(mit->second, fn);
				}
			}
			cnt++;
			nu /= 10;
		}
		
	}
	factorial(fn);
	each(mit, mp) {
		int id = mit->second;
		//show(id);
		ans += fac[id];
		ans %= MOD;
	}
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}


