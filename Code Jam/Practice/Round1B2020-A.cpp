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
typedef map<int,int>  :: iterator mit;
typedef set<int> :: iterator sit;
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
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;

string answer;
map<char, pii> mp;

void dfs(pii start, pii end, string dir, string ans, int nxtstp) {
	if (len(answer) > 0) return;
	if (start == end) {
		answer = ans;
		return;
	}
	
	
	
	rep (i, 0, 4) {
		pii par = mp.at(dir[i]);
		pii xy = mk(start.ff + par.ff * nxtstp, start.ss + par.ss * nxtstp);
		if (abs(xy.ff) > 1e9 || abs(xy.ss) > 1e9) continue;
		dfs(xy, end, dir, ans + dir[i], nxtstp * 2);
	}
}
 

void solve () {
	int x , y;
	cin >> x >> y;
	
	if (x + y % 2 == 0) {
		show("IMPOSSIBLE");
		return;
	}
	// 1 2 4 8 16 32 64 128 256 
	int step = 1;
	string s;
	string dir = "SEWN";
	
	mp['N'] = mk(-1, 0);
	mp['S'] = mk(1, 0);
	mp['E'] = mk(0, 1);
	mp['W'] = mk(0, -1);
	
	dfs(mk(x, y), mk(0,0), dir, s, step);
	
	
	show(answer);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int C = 1;
	while (C <= T) {
		cout << "Case #" << C << ": ";
		solve();
		C++;
	}
	
	return 0;
}

