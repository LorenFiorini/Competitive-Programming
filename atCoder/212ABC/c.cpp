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
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

void solve () {
	int ans = INF;
	int n, m;
	cin >> n >> m;
	vint a(n);
	vint b(m);
	rep (i, 0, n) cin >> a[i];
	rep (i, 0, m) cin >> b[i];
	
	sort(all(a));
	sort(all(b));
	
	rep (i, 0, n) {
		vint::iterator low = lower_bound(all(b), a[i]);
		int j = low - b.begin();
		if (j < m)
		ans = min(ans, abs(a[i] - b[j]));
	}
	
	rep (j, 0, m) {
		vint::iterator low = lower_bound(all(a), b[j]);
		int i = low - a.begin();
		if (i < n)
		ans = min(ans, abs(a[i] - b[j]));
	}
	
	/*
	int i = 0, j = 0;
	while (i < n && j < m) {
		int dif = abs(a[i] - b[j]);
		ans = min(ans, dif);
		if (i+1 < n && j+1 < m) {
			if (abs(a[i+1] - b[j]) > abs(a[i] - b[j+1])) {
				i++;
			} else {
				j++;
			}
		} else if (i+1 < n) {
			i++;
		} else {
			j++;
		}
	}*/
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
