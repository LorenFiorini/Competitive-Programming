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
#define showv(v, n) rep(index, 0, n) {cout << v[index] << " ";} cout << "\n";
#define showvp(v, n) rep(index, 0, n) {showp(v[index].ff, v[index].ss);}
#define showvv(vv, n, m) rep(row, 0, n) {showv(vv[row], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second


void solve () {
	ll ans = 0, n;
	cin >> n;
	vll v(n);
	rep (i,0,n) cin >> v[i];

	ll mx = 1e15;
	ll low = -mx;
	ll upp = mx;

	// greater than or equal, less
	vector<vll> vec(n-1, vll(2, mx));
	rep (i, 0, n-1) {
		ll sum = (v[i] + v[i+1]);
		if (v[i] > v[i+1]) {
			vec[i][0] = sum / 2 + (sum % 2 != 0);
		} else if (v[i] < v[i+1]) {
			vec[i][1] = sum / 2;
		}
	}
	//showvv(vec, n-1, 2);
	
	rep (i, 0, n-1) {
		if (vec[i][0] != mx) {
			low = max(low, vec[i][0]);
		}
		if (vec[i][1] != mx) {
			upp = min(upp, vec[i][1]);
		}
	}
	
	showp(low, upp);
	if (low > upp) {
		show(-1);
		return;
	} else if (low != -mx && upp != mx) {
		ans = (low + upp) / 2;
	} else if (low != -mx) {
		ans = low;
	} else if (upp != mx) {
		ans = upp;
	} else {
		ans = v[0];
	}

	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini