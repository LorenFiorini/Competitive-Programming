#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll , ll> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll , ll> mpii;
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
void bfs(vint &v, ll target, ll &ans) {
	mpii mp;
	
	for (ll num : v){
		vpii vec(1, {num, (ll)1});
		each (it, mp) {
			ll val = num + it->ff;
			if (val > target) continue;
			vec.pb({val, it->ss});
		}
		for (pii p : vec) {
			if (p.ff == target) ans += p.ss;
			if (mp.find(p.ff) == mp.end()) {
				mp[p.ff] = p.ss;
			} else {
				mp[p.ff] += p.ss;				
			}
		}
	}
	//showmap(it, mp);
}

void solve () {
	ll ans = 0;
	
	cin >> n;
	vint v(n, 0);
	rep (i,0,n) cin >> v[i];
	
	ll suma = accumulate(all(v), 0) - 1;
	sort(allg(v));
	
	if (suma == 0) {
		ans = pow((ll) 2, (ll) n-1);
	} else {
		bfs(v, suma, ans);
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
