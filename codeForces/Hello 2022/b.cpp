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

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vvi v(n, vint(3));
	
	// Left Right Cost
	rep (i, 0, n) {
		rep(j, 0, 3) cin >> v[i][j];
	}
	
	int mni = 0, mxi = 0;
	
	rep (i, 1, n+1) 
	{
		//ans
		if (mni == mxi) {
			ans = v[mni][2];
		} else {
			ans = v[mni][2];
			ans += v[mxi][2];			
		}
		show(ans);
		if (i==n) break;
		
		// when range increases
		if (v[i][0] < v[mni][0]) mni = i;
		if (v[i][1] > v[mxi][1]) mxi = i;
		// same range, choose less cost
		if (v[i][0] == v[mni][0] && v[i][2] < v[mni][2]) mni = i;
		if (v[i][1] == v[mxi][1] && v[i][2] < v[mxi][2]) mxi = i;
		
		// New greater
		if (v[i][0] == v[mni][0] && v[i][1] == v[mxi][1])) {
			if (mni != mxi && (mni == i || mxi == i)) {
				mni = mxi = i;
			}
		}
	}
	
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
