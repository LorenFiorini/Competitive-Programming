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

vint query(int l, int r) {
	// One index
	cout << "? " << (l+1) << " " << (r+1) << endl;
	int n = r - l + 1;
	vint ans(n);
	rep(i, 0, n) {
		cin >> ans[i];
		ans[i]--;
	}

	return ans;
}

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vint v(n, 1);
	int l = 0;
	int r = n/2;

	rep(Q, 0, 15) {

		vint a = query(l, r);
		sz = r - l + 1;
		if (l == r && a[0] == l) {
			cout << "! " << (r+1) << endl; 
			return;
		}

		rep(i, 0, sz) {
			if (l <= a[i] && a[i] <= r) {
				//should be here
				int from = l;
				if (i) from = a[i-1];
				rep(j, from, a[i]) v[j] = 0;

			} else {
				//it changed position
				v[a[i]] = 0;
			}
		}
		while (v[l] && l <= r) l++;
		while (v[r]) r--;

		if (r-l+1 == sz) {
			int d = max(sz > 4, 1);
			l += d;
			r -= d;
		} 
		if (l > r) {
			while (v[l]) l++;
			r = l;
			while (v[r]r < n) r++;
		}
	}
	rep(i,0,n) {
		if (v[i]) {
			cout << "! " << (i+1) << endl; 
			return;
		}
	}
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
