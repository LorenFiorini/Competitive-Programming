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

bool cmp(string &a, string &b) {
	int n = len(a);
	int m = len(b);
	if (n != m) return n < m;
	return a < b;
}
int N, k;
int mxlen;

vstr input() {
	cin >> N >> k;
	vstr vs(N);
	vint vl(N);
	rep (i, 0, N) {
		cin >> vs[i];
		vl[i] = len(vs[i]);
	}
	sort(all(vl));
	mxlen = vl[k-1];
	
	vstr v;
	vstr vec;
	rep (i, 0, N) {
		if (len(vs[i]) < mxlen) {
			v.pb(vs[i]);
		} else if (len(vs[i]) == mxlen) {
			vec.pb(vs[i]);
		}
	}
	sort(all(vec));
	for (string &str : vec) {
		v.pb(str);
		if (len(v) >= k) break;
	}	
	return v;
}

string ans;
void dfs(vstr &v, int n, string s, vint &vis) {
	vstr vec;
	rep (i, pos, n) {
		if (!vis[i])
			vec[i].pb(s + v[i]);
	}
	
	sort(all(vec));
	dfs(v, n, vec[0], vis);
	
}


void solve () {
	vstr v = input();
	int n = len(v);
	sort(all(v));
	
	vint vis(n);
	dfs(v, n,  "", vis);
	
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
