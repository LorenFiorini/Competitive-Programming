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
int n;

int order(vvi &v, vvi &ans) {
	rep(i,1,n) {
		int j = i-1;
		vint key = v[i];
		
		while (0 <= j && v[j][0] >= key[0] && v[j][1] >= key[1]) {
			ans.pb({j, j+1});
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}
	rep(i,1,n) {
		rep(j,0,2) if (v[i-1][j] > v[i][j]) return -1;
	}
	return len(ans);
}

void solve () {
	vvi ans;	
	cin >> n;
	vvi v(n, vint(2));
	rep(i,0,n) cin >> v[i][0];
	rep(i,0,n) cin >> v[i][1];
	
	int sz = order(v, ans);
	
	show(sz);
	if (sz > 0) {
		rep(i,0,sz) {
			showp(ans[i][0]+1, ans[i][1]+1);
		}
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
