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

int check(ll a, ll b, ll c) {
	if (c - b == b - a) return 1;
	return 0;
}

void solve () {
	vector<vll> v(3, vll(3));
	rep (i,0,3)rep (j,0,3) {
		if (i == 1 && j == 1) continue;
		cin >> v[i][j];
	}
	vll ans(1, 3 * (ll)INF);
	ll num = abs(v[2][2] - v[0][0]);
	if ( num % 2 == 0) {
		ans.pb((v[2][2] + v[0][0]) / 2);
	}
	num = abs(v[2][0] - v[0][2]);
	if ( num % 2 == 0) {
		ans.pb((v[2][0] + v[0][2]) / 2);
	}
	num = abs(v[0][1] - v[2][1]);
	if ( num % 2 == 0) {
		ans.pb((v[0][1] + v[2][1]) / 2);
	}
	num = abs(v[1][0] - v[1][2]);
	if ( num % 2 == 0) {
		ans.pb((v[1][0] + v[1][2]) / 2);
	}
	
	
	ll sum = 0;
	for (ll num : ans) 
	{
		v[1][1] = num;
		ll suma = 0;
		rep (i, 0, 3) {
			suma += check(v[i][0], v[i][1], v[i][2]);
		}
		rep (j, 0, 3) {
			suma += check(v[0][j], v[1][j], v[2][j]);
		}
		
		suma += check(v[0][0], v[1][1], v[2][2]);
		suma += check(v[2][0], v[1][1], v[0][2]);
		
		sum = max(sum, suma);
	}
	
	show(sum);
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
	
	return 0;
}

// Lorenzo
