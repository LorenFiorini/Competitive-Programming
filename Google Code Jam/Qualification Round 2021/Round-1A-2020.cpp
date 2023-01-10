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
typedef map<int,int>  :: iterator mit;
typedef set<int> :: iterator sit;
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
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "\n";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;





void solve () {
	int ans;
	int n;
	cin >> n;
	vstr v(n);
	rep (i, 0, n) cin >> v[i];
	
	string be = "";
	string en = "";
	
	rep (i, 0, n) 
	{
		int m = len(v[i]);
		if (v[i][m-1] == '*') 
		{
			string s = v[i].substr(0, m-1);
			if (!len(be)) {
				be = s;
				continue;
			}
			rep (j, 0, min(m - 1, len(be))) {
				if (s[j] != be[j]) {
					show("*");
					return;
				}
			}
			if (m-1 > len(be)) be = s;
			
		}
		else if (v[i][0] == '*')
		{
			string s = v[i].substr(1, m);
			if (!len(en)) {
				en = s;
				continue;
			}
			rep (j, 0, min(m-1, len(en))) {
				if (s[m-2-j] != en[len(en) - 1 - j]) {
					show("*");
					return;					
				}
			}
			if (m-1 > len(en)) en = s;			
		}
		else 
		{
			
		}
		
	}

	show(be + en);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int c = 1;
	while (c <= t) {
		cout << "Case #" << c << ": ";
		solve();
		c++;
	}
	
	return 0;
}

