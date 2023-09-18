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
#define ff first
#define ss second
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
#define showvv(vv, n, m) rep(j, 0, n) {showv(vv[j], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

ll dp[31][31];

string find_kth(ll a, ll b, ll k) {
	if (a == 0) return string(b, 'b');
	if (b == 0) return string(a, 'a');
	
	if (k <= dp[a-1][b]) {
		return string("a") + find_kth(a - 1, b, k);
	} else {
		return string("b") + find_kth(a, b - 1, k - dp[a-1][b]);
	}
	
}

void solve () {
	ll a,b,k;
	cin >> a >> b >> k;
	
	dp[0][0] = 1;
	rep (i, 0, a + 1) {
		rep (j, 0, b + 1) {
			if (i > 0) {
				dp[i][j] += dp[i - 1][j];
			}
			if (j > 0) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}
	
	//showvv(dp, a+1, b+1);
	show(find_kth(a, b, k));
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

