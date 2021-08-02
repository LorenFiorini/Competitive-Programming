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
	int ans = 0;
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	
	
	if (a < 0) {
		ans = n * (a + b);
		show(ans);
		return;
	} else if (a == 0) {
		if (b == 0) {
			show(0);
			return;
		} else if (b > 0) {
			ans =  n * (a + b);
			show(ans);
			return;
		} 
	}
	
	int uno = 0, zero = 0; 
	vint v;
	rep (i, 0, n) {
		if (s[i] == '1') {
			uno++;
			if (zero) v.pb(zero);
			zero = 0;
		} else{
			zero++;
			if (uno) v.pb(uno);
			uno = 0;
		}
		if (i == n-1) {
			if(uno) v.pb(uno);
			if(zero) v.pb(zero);
		}
	}
	//showv(v, len(v));
	int oa = 0;
	rep (i, 0, len(v)) {
		if (i % 2 == 0) {
			oa += v[i];
		} else {
			ans += (a * v[i]) + b;
		}
	}
	ans += a * oa + b;
	
	show(ans);
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
