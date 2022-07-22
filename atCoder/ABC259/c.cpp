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

vector<pair<char, int>> get(string s, int n) {
	vector<pair<char, int>> v;
	v.pb({s[0], 1});
	int sz = 1;
	rep(i, 1, n) {
		if (s[i-1] == s[i]) {
			v[sz-1].ss++;
		} else {
			v.pb({s[i], 1});
			sz++;
		}
	}
	return v;
}

void solve () {
	int ans = 0;
	string s; cin >> s;
	string t; cin >> t;
	int n = len(s);
	int m = len(t);
	if (n > m) {
		show("No");
		return;
	}
	vector<pair<char, int>> a = get(s, n);
	vector<pair<char, int>> b = get(t, m);

	if (len(a) == len(b)) {
		bool ok = 1;
		n = len(a);
		rep(i, 0, n) {
			if (a[i].ff != b[i].ff) ok = 0;
			if (a[i].ss != b[i].ss) {
				if (!(a[i].ss < b[i].ss && a[i].ss >= 2) ) ok = 0;
			}
			if (!ok) break;
		}
		if (ok) {
			show("Yes");
			return;
		}
	}
	show("No");
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
