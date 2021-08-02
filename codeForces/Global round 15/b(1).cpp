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
	int n;
	cin >> n;
	vvi v(n, vint(5));
	rep (i ,0, n) {
		rep (j , 0, 5) cin >> v[i][j];
	}
	
	//  COMPETITOR , times over others
	map<int, vint> mp;
	map<int, vint>::iterator it;
	rep (j, 0, 5) 
	{
		// score , competitor
		vpii comp(n);
		rep (i, 0, n) {
			comp[i] = {v[i][j], i};
		}
		sort(all(comp));
		rep (k, 0, n/2 + 1) 
		{
			// las veces que a ganaron los otros
			it = mp.find(comp[k].ss);
			if (it == mp.end()) {
				//first time top
				vint vec(n, 1);
				rrep (l, k, 0){
					int posi = comp[l].ss;
					vec[posi] = 0;
				}
				mp[comp[k].ss] = vec;
			} else {
				rep (l, 0, n-k) {
					int posi = comp[k+l].ss;
					it->ss[posi]++;
				}
			}
		}
		
	}
	
	
	each (it, mp) {
		bool ok = true;
		rep (i, 0, n) {
			if (it->ss[i] < 3) {
				ok = false;
				break;
			}
		}
		if (ok) {
			show(it->ff + 1);
			return;
		}
	}
	
	show(-1);
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
