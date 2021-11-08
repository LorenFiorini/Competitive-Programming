#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef double db;
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
#define x first
#define y second

void solve () {
	int inf = 1e9 + 100;
	int ans = 0;
	int n;
	cin >> n;
	vpii v(n);
	rep (i,0,n) cin >> v[i].x >> v[i].y;
	sort (all(v));
	
	rep (i,0,n) {
		rep (j, i+1, n) {
			db slope = 0;
			if (v[i].x == v[j].x) slope = inf;
			else slope = (db) (v[j].y - v[i].y) / (db) (v[j].x - v[i].x) ;
			
			rep (k, j+1, n) {
				db tmp = 0;
				if (v[i].x == v[k].x) tmp = inf;
				else tmp = (db) (v[k].y - v[j].y) / (db) (v[k].x - v[j].x) ;
				
				if (tmp != slope) {
					ans++;
				}
			}
		}
	}
	
	
	
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
