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
typedef map<ll, ll> mpii;
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


void solve () {
	// input
	ll ans[2] = {0, 0};
	ll n, Rs, Rh, m, dis;
	cin >> Rs >> Rh;
	ll D = pow(Rs + Rh, 2); 

	ll a, b;
	mpii mp;
	cin >> n; 
	rep(i, 0, n) {
		cin >> a >> b;
		dis = pow(a, 2) + pow(b, 2);
		if (dis <= D) {
			mp[dis] = 0;
		}
	}
	cin >> m; 
	rep(i, 0, m) {
		cin >> a >> b;
		dis = pow(a, 2) + pow(b, 2);
		if (dis <= D) {
			mp[dis] = 1;
		}
	}

	ll last = mp.begin()->second;
	each(it, mp) {
		if (it->ss != last) break;
		ans[it->ss]++;
	}

	showp(ans[0], ans[1]);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T; 
	rep(C, 1, T+1) {
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
