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
bool sorted(vint& v) {
	vint vec(all(v));
	sort(all(vec));
	rep (i, 0, n) {
		if (vec[i] != v[i]) return 0;
	}
	return true;
}

void solve () {
	
	cin >> n;
	vint v(n);
	rep(i,0,n) cin >> v[i];
	//
	int dif = v[n-2] - v[n-1];
	if (sorted(v)) {
		show(0);
		return;
	} else if (dif > 0 || v[n-2] < dif) {
		show(-1);
		return;
	} 
	 
	vvi ans;
	for (int i = n-3; i >= 0; i--) {
		ans.pb({i+1, n-1, n});
	}
	
	show(n-2);
	for (vector<ll> v: ans) {
		for (ll a : v){
			cout << a << " ";
		}
		cout << "\n";
	}
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
