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

int mini(vpii &v, int x, int y) {
	int i = 0;
	while (x > 0 || y > 0) {
		if (i == n) return -1;
		x -= v[i].ff;
		y -= v[i].ss;
		i++;
	}
	
	return i;
}
	
void solve () {
	int ans = -1;
	cin >> n;
	int x, y;
	cin >> x >> y;
	
	vpii v1(n);
	vpii v2(n);
	rep (i, 0, n) {
		int a, b;
		cin >> a  >> b;
		v1[i] = {a, b};
		v2[i] = {b, a};
	}
	
	sort(allg(v1));
	sort(allg(v2));
	
	
	int A = mini(v1, x, y);
	int B = mini(v2, y, x);
	
	if (A == -1 || B == -1) {
		if (A == -1 && B == -1) {
			ans = -1;
		} else {
			ans = max(A, B);
		}		
	} else {
		ans = min(A, B);
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
