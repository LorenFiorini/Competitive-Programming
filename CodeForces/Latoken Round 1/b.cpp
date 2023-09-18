#include <bits/stdc++.h>
using namespace std;
#define INF (ll)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll,ll> mpii;
typedef set<ll> seti;
typedef multiset<ll> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
//
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (ll i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (ll) v.size()
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

void solve () {
	ll ans = 1e18;
	ll n;
	cin >> n;
	seti st;
	vint v(n+2, (ll)0);
	//vint h(n + 1, 0);
	rep (i, 1, n+1) {
		cin >> v[i];
		/*
		if (i > 0) {
			h[i] = abs(h[i-1] - v[i]);
			if (i == n-1 ) {
				h[n] = v[i];
			}
		} else {
			h[i] = v[i];
		}*/
		st.insert(v[i]);
	}
	if (n == 1) {
		show(v[1]);
		return;
	}
	
	ll m = min((ll) 5, n);
	vll mn(m, 0);
	ll pos = 1;
	each (it, st) {
		mn[pos] = (ll) *it;
		pos++;
		if (pos == m-1) break;
	}
	vll dp(m, 0);
	
	seti no;
	rep (i, 1, n+2){
		
		rep (j, 0, m) {
			if (!notin(no, j)) continue;
			ll he = min(mn[j], v[i]);
			dp[j] += abs(he - min(mn[j], v[i-1]));
			
			ll take = v[i] - he;
			if (dp[j] + take > 1e18) {
				no.insert(j);
			}
			dp[j] += take;
			/*
			dp[j].ff += abs(he - min(mn[j], v[i-1]));
			if (dp[j].ff >= MOD) {
				dp[j].ss++;
				dp[j].ff %= MOD;
			}*/
		}
	}
	
	rep (i, 0, m) {
		ans = min(dp[i], ans);
	}
	
	
	/*
	if (ans == dp[0]) {
		show("mini");
	} else {
		show("maxi");
	}*/
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
