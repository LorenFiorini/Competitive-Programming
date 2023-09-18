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

int best(vvi &v, vint &mni, vint &mxi) {
	int n = len(mni);
	int m = len(mxi);
	int ans = 2* 1e9 + 1;
	
	rep (i,0,n) {
		rep (j,0,m) {
			if (mni[i] == mxi[j]) {
				ans = min(ans, v[mni[i]][2]);
			} else {
				ans = min(ans, v[mni[i]][2] + v[mxi[j]][2]);				
			}
		}
	}
	
	return ans;
}


void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vvi v(n, vint(3));
	
	// Left Right Cost
	rep (i, 0, n) {
		rep(j, 0, 3) cin >> v[i][j];
	}
	
	vint mni(1, 0);
	vint mxi(1, 0);
	int mn = v[0][0];
	int mx = v[0][1];
	
	rep (i, 1, n+1) 
	{
		//ans
		ans = best(v, mni, mxi);
		show(ans);
		if (i==n) break;
		
		// when range increases		
		if (v[i][1] > mx) {
			mx = v[i][1];
			mxi.clear();
			mxi.pb(i);
		} else if (v[i][1] == mx) {
			mxi.pb(i);
		}
		
		if (v[i][0] < mn) {
			mn = v[i][0];
			mni.clear();
			mni.pb(i);
		} else if (v[i][0] == mn) {
			mni.pb(i);
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
