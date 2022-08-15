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

int bin(int num, vpii &vp, int m) {
	int l = 0;
	int r = m - 1;
	
	while (l < r) {
		int mid = (l+r) / 2;
		if (vp[mid].ff == num) {
			return vp[mid].ss;
		} else if (vp[mid].ff > num) {
			r = mid ;
		} else {
			l = mid + 1;
		}
	}
	
	if (vp[r].ff >= num) return vp[r].ss;
	//return the index
	return 1e9;
}

void solve () {
	int ans = 1e8;
	int n, k;
	cin >> n >> k;
	mpii mp;
	vint a(k);
	rep(i, 0, n) {
		if (i < k) cin >> a[i];
		else {
			int num;
			cin >> num;
			if (mp.find(num) == mp.end()) {
				mp[num] = i;
			}
		}
	}
	
	vpii vp;
	each(it, mp) {
		vp.pb({it->first, it->second});
	}
	int m = len(vp);
	for (int i = m-1; i > 0; i--) {
		vp[i-1].ss = min(vp[i-1].ss, vp[i].ss);
	}
	//showvp(vp, m);
	
	for (int i = k-1; i >= 0; i--) {
		int j = bin(a[i] + 1, vp, m);
		ans = min(ans, j - i);
		//showp(i, j);
	}
	
	
	if (ans >= 1e6) ans = -1;
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