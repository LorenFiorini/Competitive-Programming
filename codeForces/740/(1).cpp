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

map<pii, seti> mp;

void dfs(seti &st, int a, int b, int match, int brs) {
	if (a + b == 0) {
		st.insert(brs);
		return;
	}
	
	map<pii, seti>::iterator it = mp.find({a,b});
	if (it != mp.end()) {
		if ((it->ss).find(brs) != (it->ss).end()) {
			return; 
		}
	}
		
	// When A wins 
	if (a > 0)
	{
		int bre = (match&1);
		dfs(st, a-1, b, match+1, brs+bre);
	}
	// When B wins 
	if (b > 0)
	{
		int bre = !(match&1);
		dfs(st, a, b-1, match+1, brs+bre);
	}
	mp[{a,b}].insert(brs);	
}

void count(seti &tmp, int n) {
	seti st(all(tmp));
	each(it, st) {
		int won = *it;
		tmp.insert(won);
		tmp.insert(n - won);
	}
}

void solve () {
	mp.clear();
	seti st;
	int a, b;
	cin >> a >> b;
	
	dfs(st, a, b, 0, 0);
	count(st, a+b);
	
	int ans = len(st);
	show(ans);
	showset(it, st);
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
