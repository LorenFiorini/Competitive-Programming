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

void help(int n, vint &v) {
	int ans = 0;
	
	if (n % 2 == 0) 
	{
		// par = minimize the differerce
		int a = 0;
		int b = 0;
		
		int i = 0;
		while (i < n && a == b) {
			//showp(a, b);
			a *= 10;
			a += v[i];
			i++;
			b *= 10;
			b += v[i];
			i++;
		}
		
		for (int j = n-1; i < j; ) {
			a *= 10;
			a += v[j];
			b *= 10;
			b += v[i];
			//showp(a, b);
			i++;
			j--;
		}
		
		//showp(a, b);
		ans = a * b;		
	} else 
	{
		int a = v[0];
		int b = v[1];
		rep (i, 2, n-1) {
			if (i%2) {
				a *= 10; 
				a += v[i];
			} else {
				b *= 10;
				b += v[i];
			}
		}
		ans = max((a*10+v[n-1]) * b , (b*10+v[n-1]) * a );
	}
	
	cout << ans << endl;
}

void solve () {
	int n;
	cin >> n;
	
	vint v;
	while (n > 0) {
		v.pb(n%10);
		n /= 10;
	}
	sort(allg(v));
	//showv(v, len(v));
	
	help(len(v), v);
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini