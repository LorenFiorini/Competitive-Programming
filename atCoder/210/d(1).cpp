#include <bits/stdc++.H>
using namespace std;
typedef long long ll;
#define INF (ll)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef pair<ll ,ll> pii;
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
#define f first
#define s second

void solve () {
	ll H, W, c;
	cin >> H >> W >> c;
	vector<vll> v(H, vll(W)); 
	vector<vll> cost(H, vll(W)); 
	
	rep (i, 0, H) rep (j, 0, W) {
		cin >> v[i][j];
		cost[i][j] = c * (i+j);
	}
	
	vector<vll> dp(H, vll(W)); 
	dp[0][1] = v[0][0] + v[0][1] + c;
	dp[1][0] = v[0][0] + v[1][0] + c;
	rep (i, 0, H) {
		rep (j, 0, W) {
			if (i+j <= 1) {
				dp[i][j] = dp[0][0] + cost[i][j] + v[i][j]; 
			} else if (i == 0) {
				dp[i][j] = min(dp[i][j-1], cost[i][j] + v[i][j] );//- dp[i][j-1]); 
			} else if (j == 0) {
				dp[i][j] = min(dp[i-1][j], cost[i][j] + v[i][j] ); //- dp[i-1][j]); 
			} else {
				ll tmp = min(dp[i][j-1], cost[i][j] + v[i][j]); //- dp[i][j-1]); 
				tmp = min(tmp, min(dp[i-1][j], cost[i][j] + v[i][j]));// - dp[i-1][j])); 
				dp[i][j] = tmp; 
			}
		}
	}
	
	//D.P.
	
	rep (i, 0, H) {
		rep (j, 0, W) {
			cout << dp[i][j] << " "; 
		}
		show("");
	}
	
	ll ans = dp[H-1][W-1];
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
