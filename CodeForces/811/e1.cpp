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
typedef set<ll> seti;
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

vint get(ll n) {
	ll num, val;
	seti st;
	rep(i, 0, n) {
		cin >> num;
		val = num % 10;
		while (val != 0 && val != 2) {
			num += val;
			val = num % 10;
		}
		st.insert(num);
	}
	vint v(all(st));
	return v;
}

bool check(vint &v, ll n) {
	ll num, dif;
	rep(i, 0, n-1) {
		dif = v[i+1] - v[i];

		if (dif % 20 != 0) return 0;
	}

	return 1;
}


void solve () {
	bool ans = 1;
	ll n, num;
	cin >> n;
	vint v = get(n);
	n = len(v);

	// Check Component
	int c[2] = {0, 0};
	rep(i, 0, n) c[(v[i] % 10) == 0]++;


	if (c[0] > 0 && c[1] > 0) {
		ans = 0;
	} else if (c[1] > 0 || n == 1) {
		ans = (n == 1);
	} else {
		//cout << "? ";
		ans = check(v, n);
	}
	
	if (ans) {
		show("Yes");
	} else {
		show("No");
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
