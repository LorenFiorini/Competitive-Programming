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


void solve () {
	cin >> cha.he >> cha.at;
	cin >> mon.he >> mon.at;
	cin >> k >> w >> a;
	
	
	rep(i, 0, k+1) {
		ll r = check(i);
		if (r == 0) {
			show("YES");
			return;
		}
	}
	
	show("NO");
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
