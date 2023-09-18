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

int n, k;
int rect(vpii&v) {
	int ans = 0;
	mpii mpx;
	mpii mpy;
	for (pii p: v) {
		mpx[p.ff]++;
		mpy[p.ss]++;
	}
	each(it, mpx) if (it->ss >= k) ans++;
	each(it, mpy) if (it->ss >= k) ans++;
	
	return ans;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve () {
	int ans = 0;
	
	cin >> n >> k;
	vpii v(n);
	rep(i,0,n) cin >> v[i].ff >> v[i].ss;
	
	if (k == 1) {
		show("Infinity");
		return;
	}
	
	// search for X and Y
	//ans = rect(v);
	
	//	map<double, vint> mp;
	// num/den -> cnt
	set<pii> st;
	rep (i, 0, n) {
		map<pii, vint> mp;
		
		rep(j, i+1, n) {
			if (st.find( {i, j} ) != st.end()) continue;
			
			int a = v[i].ss - v[j].ss;
			int b = v[i].ff - v[j].ff;
			// a / b
			int g = gcd(a,b);
			a /= g;
			b /= g;
			mp[ {a, b} ].pb(j);
		}
		
		each(it, mp) {
			int sz = len(it->ss);
			if (sz + 1 >= k) ans++;
			
			rep(id, 0, sz) {
				rep(jd, id+1, sz) {
					st.insert( {it->ss[id], it->ss[jd]} );
				}
			}
		}
	}
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
