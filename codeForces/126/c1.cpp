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

int n;
ll check(vll &v, ll tar, ll odd) {
	//ll ans = 1e9;
	ll even = 0;
	
	rep(i,0,n) {
		ll di = tar - v[i];
		if (di == 0) break;
		even += di / 2;
		odd += di % 2;
	}
	
	ll di = abs(even - odd);
	if (di % 3 == 0) {
		if (even > odd) {
			odd += di / 2;
		} else if (odd > even){
			odd -= di / 3; 
		}
		return 2*odd;
	} else if (di % 3 == 1) {
		if (odd > even) {
			odd -= di / 3;
			return 2 * odd - 1;
		}
		even -= di /3;
		return even * 2;
	} else {
		if (odd > even) {
			odd -= di / 3;
			return 2 * odd - 1;
		} 
		
		even -= di /3;
		return even * 2;
	}
	
	
	
	return 0;
}

void solve () {
	ll ans = 1e9;
	cin >> n;
	vll v(n);
	rep(i,0,n) cin >> v[i];
	sort(all(v));
	
	// either to v[n-1] pr v[n-1] + 1
	n--;
	ans = min(check(v, v[n], 0), check(v, v[n] + 1, 1));
	
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