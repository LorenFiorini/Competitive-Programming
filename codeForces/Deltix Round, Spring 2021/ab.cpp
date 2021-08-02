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
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

void solve () {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vpii v;
	int pos = 0;
	rep (i, 0, n) {
		int num = s[i] - '0';
		if (!i || v[pos-1].ff != num) {
			v.pb(mk(num, 1));
			pos++;
		} else {
			v[pos-1].ss++;
		}
	}
	if (len(v) == 1) {
		show(s);
		return;
	}
	rep (i, 0, len(v)) {
		if (v[i].ff == 1) continue;
		if (i == 0) {
			int chan = min(v[i].ss, m);
			v[i].ss -= chan;
			v[i+1].ss += chan;
		} else if (i == len(v)-1) {
			int chan = min(v[i].ss, m);
			v[i].ss -= chan;
			v[i-1].ss += chan;
		} else {
			int chan = min(v[i].ss / 2, m);
			v[i-1].ss += chan;
			v[i+1].ss += chan;
			v[i].ss -= 2 * chan;
			
		}
		
	}
	
	rep (i, 0, len(v)){
		rep (j, 0, v[i].ss) {
			cout << v[i].ff;
		}
	}
	cout << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

