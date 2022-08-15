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

bool check(vint v) {
	bool mov = 0;
	vector<bool> moved(n, 0);
	rep (i, 1, n) {
		if (v[i] - v[i-1] == 2) {
			if (mov == 0) {
				// move up
				v[i-1]++;
				moved[i-1] = 1;
			} else {
				v[i]--;
				moved[i] = 1;
			}
			mov = 1;
		} else if (v[i] - v[i-1] == 3) {
			if (moved[i-1] == 0 && moved[i] == 0) {
				v[i-1]++;
				v[i]--;
				moved[i-1] = 1;
				moved[i] = 1;
			} else {
				return 0;
			}
			mov = 1;
		} else if (v[i] - v[i-1] > 3) {
			return 0;
		} 
	}
	return 1;
}
void solve () {	
	int mx = 0;
	cin >> n;
	vint v(n);
	rep(i,0,n) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	
	if (check(v)) {
		show("YES");
		return;
	} 
	rep (i,0,n) {
		v[i] = mx - v[i];
	}
	reverse(all(v));
	if (check(v)) {
		show("YES");
	} else {
		show("NO");
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