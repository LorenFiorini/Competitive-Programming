#include <bits/stdc++.h>
using namespace std;

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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "\t";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

const ll inf = 1e10;

void solve () {
	long long ans = 0;
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> v(n, vector<long long> (n, inf));
	
	while (m--) {
		long long a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		v[a][b] = c;
	}
	for (long long i = 0; i < n; i++) v[i][i] = 0;
	
	
	for (long long k = 0; k < n; k++) {
		vector<vector<long long>> time(n, vector<long long> (n, 0));
		for (long long i = 0; i < n; i++) {
			for (long long j = 0; j < n; j++) 
			{
				time[i][j] = min(v[i][j], v[i][k] + v[k][j]);
				if (time[i][j] < inf) {
					ans += time[i][j];
				}
			}
		}
		v = time;
	}
	cout<< ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
