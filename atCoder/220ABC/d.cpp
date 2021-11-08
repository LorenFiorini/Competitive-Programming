#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
//#define MOD 1000000007
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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "\n";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

void solve () {
	int mod = 998244353;
	vint ans(10, 0);
	int n;
	cin >> n;
	vint v(n);
	rep (i,0,n) cin >> v[i];
	
	mpii mp;
	mp[v[0]] = 1;
	
	rep (i, 1, n) {
		
		mpii nxt;
		each(it, mp) 
		{
			int num = it->ff;
			// F
			int N = (num + v[i]) % 10;
			auto ite = nxt.find(N);
			if (ite == nxt.end()) {
				nxt[N] = it->ss;
			} else {
				nxt[N] += it->ss;
			}
			
			N = (num * v[i]) % 10;
			ite = nxt.find(N);
			if (ite == nxt.end()) {
				nxt[N] = it->ss;
			} else {
				nxt[N] += it->ss;
			}
			
		}
		
		mp.swap(nxt);
	}
	
	each(it, mp){
		ans[it->ff] = (it->ss) % mod;
	}
	
	showv(ans, 10);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini