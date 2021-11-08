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
//#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

void showvv(vvi &v, int n, int m){
	rep(i, 0, n) {
		rep (j, 0, m) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve () {
	int ans = 1e9;
	int n, k;
	cin >> n >> k;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	
	vvi mat(n, vint(n, 0));
	
	// banan - price(j-i + 1)
	mpii mp;
	mpii::iterator it;
	mp[0] = 0;
	rep(j, 0, n) 
	{
		vpii col;
		
		rep (i, 0, j+1) 
		{
			mat[i][j] = v[j] + ((j > 0) ? mat[i][j-1] : 0);
			// add distance and check in map
			int itoj = j - i + 1;
			
			// search the numbers of bananas needed
			it = mp.find(k - mat[i][j]); 
			if (it != mp.end()) {
				int cost = (int)(it->ss) + itoj;
				ans = min(ans, cost);
			}
			col.pb({mat[i][j], itoj});
		}
		
		// insert new column
		for (pii par : col) {
			auto it = mp.find(par.ff);
			if (it == mp.end()) {
				mp[par.ff] = par.ss;
			} 
			mp[par.ff] = min(mp[par.ff], par.ss);
		}
		
	}
	
	//showvv(mat, n, n);
	if (ans >= 1e9) ans = -1;
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	cout << endl;
	return 0;
}

// Lorenzo
