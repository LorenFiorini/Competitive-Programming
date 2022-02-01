#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
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
#define he first
#define at second

pii cha;
pii mon;
ll k, w, a;
vint vis;

ll check(ll mid) {
	pii C = cha;
	//pii M = mon;
	C.he += mid * a;
	C.at += (k - mid) * w;
	//showp(C.he, C.at);
	
	// num of rounds to destroy the monster
	ll rou = mon.he / C.at;
	if (mon.he % C.at) rou++;
	// num of rounds to destroy the hero
	ll roun = C.he / mon.at;
	if (C.he % mon.at) roun++;
	
	if (rou <= roun) {
		return 0;
	} else {
		return rou - roun;
	}
}


bool dfs(ll l, ll r) {
	if (l >= r) return check(l);
	
	ll m1 = max(l + (r-l) / 3, l);
	ll m2 = min(l +  (2 * (r-l)) / 3, r); 
	
	ll r1 = check(m1);
	ll r2 = check(m2);
	vis[m1] = r1;
	vis[m2] = r2;
	
	if (r1 == 0 || r2 == 0) {
		return true;
	}
	
	if (r1 > r2) {
		if (dfs(m1 + 1, r)) return 1;
		if (dfs(l, m2 - 1)) return 1;
	} else {
		if (dfs(l, m2 - 1)) return 1;
		if (dfs(m1 + 1, r)) return 1;		
	}
	return false;
}

void solve () {
	cin >> cha.he >> cha.at;
	cin >> mon.he >> mon.at;
	cin >> k >> w >> a;
	vis.resize(k, 0);
	
	if (check(0) == 0 || check(k) == 0) {
		show("YES");
		return;
	}
	ll l = 0;
	ll r = k;
	if (dfs(l, r)) {
		show("YES");
	} else {
		show("NO");
	}
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
