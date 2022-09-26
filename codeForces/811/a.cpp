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
int n, h, m;

vint get(int H, int M) {
	vint ans(2, 0);
	if (M < m) {
		ans[1] = (60 + M) - m;
		ans[0] = -1;
	} else {
		ans[1] = (M) - m;
	}
	if (H < h) {
		ans[0] += (24 + H) - h;
	} else {
		ans[0] += H - h;
	}
	if (ans[0] == -1) ans[0] = 23;
	return ans;
}

void solve () {
	vint ans(2);
	ans[0] = 23;
	ans[1] = 59;

	cin >> n >> h >> m;
	vvi v(n, vint(2));
	rep(i,0,n) cin >> v[i][0] >> v[i][1];
	
	rep(i, 0, n) {
		vint tmp = get(v[i][0], v[i][1]);

		if (tmp[0] < ans[0] || (tmp[0] == ans[0] && tmp[1] < ans[1])) {
			ans = tmp;
		}
	}


	showv(ans, 2);
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
