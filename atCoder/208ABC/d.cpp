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
#define f first
#define s second
//
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
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
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

ll n, m, ans = 0;

void dfs (vector<vpii> &v, ll from, ll to, ll k, vll &time, ll cur, ll suma) {
	// F = TIME // S = ROADS
	
	
	if (suma > 0) time[from] = min(time[from], suma);
	
	rep (i, 0, k){
		dfs(v, from, to, k, time);
	}
	
}


void solve () {
	cin >> n >> m;
	vector<vpii> v(n, vpii (n, mk(0,0)));
	rep (i, 0, m) 
	{
		ll a,b,c;
		cin >> a >> b >> c;
		a--; b--;
		v[a][b] = mk(c, 1);
	}
	
	
	rep (k, 1, n+1) {
		rep (from, 0, n) {
			vll time(all(v[i]));
			rep (to, 0, k) {
				if (to == from) continue;
				dfs(v, from, to, k, time, from, 0);
			}
			ll sum = accumulate(all(time), 0);
			ans += sum;
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
