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
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

void solve () {
	int n, q;
	cin >> n;
	string s;
	cin >> s;
	cin >> q;
	vint v1(n);
	vint v2(n);
	rep (i, 0, 2 * n) {
		if (i < n) {
			v1[i] = i;
		} else {
			v2[i-n] = i;
		}
	}
	
	rep (k, 0, q)
	{
		int t, a, b;
		cin >> t >> a >> b;
		
		if (t == 1) {
			int c1, c2;
			
			if (a <= n) c1 = v1[a-1];
			else c1 = v2[a-n-1];
			if (b <= n) c2 = v1[b-1];
			else c2 = v2[b-n-1];
			
			
			if (a <= n) v1[a-1] = c2;
			else v2[a-n-1] = c2;
			if (b <= n) v1[b-1] = c1;
			else v2[b-n-1] = c1;
			
		} else if (t == 2) {
			v1.swap(v2);
			
		}
	}
	
	rep (i, 0, n) cout << s[v1[i]];
	rep (i, 0, n) cout << s[v2[i]];
	
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}


