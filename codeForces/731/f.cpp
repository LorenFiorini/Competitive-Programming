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
#define ff first
#define ss second
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
#define showmap(it, mp) each(it, mp) {cout << it->ff.ff << " " << it->ff.ss  << "\t" << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

map<pii, int> st;
map<pii, int>:: iterator it;


bool ok (vint &v, int n) {
	rep (i, 1, n) {
		if (v[i] != v[i-1]) return false;
	}
	return true;
}

int gdc(int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	it = st.find(mk(a,b));
	if (it != st.end()) {
		return it->ss;
	}
	int ans;
	
	if (a == 0) {
		ans = b;
	} else {
		ans = gdc(a, b % a);
	}
	st.insert(mk(mk(a, b), ans));
	
	return ans;
}


void next (vint &v, int n) {
	
	rep (i, 0, n) {
		int a = v[i];
		int b = v[(i+1) % n];
		if (a > b) swap(a, b);
		it = st.find(mk(a, b));
		if (it != st.end()) {
			v[i] = it->ss;
		} else {
			v[i] = gdc(a, b);
		}
	}
}

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	
	while (not ok(v, n)) {
		next(v, n);
		showmap(it, st);
		ans++;
	}
	
	cout << ans << endl;
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
