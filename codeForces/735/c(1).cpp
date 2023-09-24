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

/*
1
69 696

*/
vpii bit(30, {1,0});
void bits() {
	rep (i, 1, 30) {
		bit[i].ff = bit[i-1].ff * 2;
	}
}

int n, m, ans;

void dfs(int pos) {
	int sum = 0;
	rep (i, 0, pos) {
		if (bit[i].ss) sum += bit[i].ff;
	}
	if ((sum ^ n)> m) {
		ans = sum ;
		return;
	}
	//show(sum);
	
	if (((sum + bit[pos].ff ) ^  n) > (sum ^ n)) {
		bit[pos].ss = 1;
	}
	
	dfs(pos+1);
}


void solve () {
	ans = 0;
	cin >> n >> m;
	if (n > m) {
		show(0);
		return;
	}
	rep (i,0,30) bit[i].ss = 0;
	
	dfs(0);
	
	show(ans);
	//show("");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bits();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
