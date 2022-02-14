#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
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

ll n;

ll sumSq(vvi &v) {
	ll ans = 0;
	rep(i, 0, n) {
		rep(j, i+1, n) {
			ans += pow(v[i][1] + v[j][1], 2);
		}
	}
	rep(i, 0, n) {
		rep(j, i+1, n) {
			ans += pow(v[i][2] + v[j][2], 2);
		}
	}
	return ans;
}

void solve () {
	ll ans = 0;
	cin >> n;
	vvi v(n, vint(3));
	rep(i, 0, n) cin >> v[i][1];
	rep(i, 0, n) cin >> v[i][2];
	
	rep(i, 0, n) {
		v[i][0] = abs(v[i][1] - v[i][2]);
	}
	sort(allg(v));
	
	
	ll A[2] = {0, 0};
	ll B[2] = {0, 0};
	rep (i, 0, n) {
		int mn = min(v[i][1], v[i][2]);
		int mx = max(v[i][1], v[i][2]);
		if (A >= B) {
			B += v[i][0];
			v[i][1] = mn;
			v[i][2] = mx;
		} else {
			A += v[i][0];
			v[i][1] = mx;
			v[i][2] = mn;
		}
	}
	
	//showvv(v, n ,3);
	ans = sumSq(v);
	show(ans);
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
