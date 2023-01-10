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

ll mod = 998244353;


ll binC(ll n, ll k) {
    ll res = 1;
    if (k > n - k) k = n - k;
 
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
        res %= mod;
    }
    return res;
}

void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	vint v(n);
	rep(i, 0, n) cin >> v[i];
	ans = n;

	//vint ma(n);
	rep(M, 2, n+1) {
		vint res(M, 0);
		rep(i, 0, n) {
			res[v[i] % M]++;  
		}
		//showv(res, M);
		
		rep(cla, 0, M) {
			ll tem = (cla * M) % M; 
			if (tem == 0 && res[cla] >= M) {
				ll num = binC(res[cla], M);
				ans += num;
				ans %= mod;
				//showp(cla, num);
			}
		}
		if (M % 2 == 0) {
			ll Mi = M / 2;
			rep(cla, 1, M/2) {
				if (res[cla] >= Mi && res[M-cla] >= Mi) {
					ll num = binC(res[cla], Mi) * binC(res[M-cla], Mi);
					ans += num;
					ans %= mod;
					//showp(cla, num);
				}
			}
		} else if (res[1] > 0) {
			ll Mi = M / 2;
			rep(cla, 1, Mi) {
				//if (cla + 1 == M - cla) break;
				if (res[cla+1] >= Mi && res[M-cla] >= Mi) {
					ll num = binC(res[cla+1], Mi) * binC(res[M-cla], Mi);
					ans += num;
					ans %= mod;
					//showp(cla, num);
				}
			}
		}
	}

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