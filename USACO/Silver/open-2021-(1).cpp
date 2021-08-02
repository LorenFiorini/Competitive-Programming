#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
typedef int ll;
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
#define ff first
#define ss second
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (ll i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;

void sumprefix(vll v, vll &pr, ll maxi) {
	ll n = len(pr);
	rep (i, 0, n) {
		pr[i] = v[i];
		if (i) pr[i] += v[i-1];
		pr[i] = min(pr[i], maxi);
	}
}

void input () {
	ll ans = 0;
	// inputs
	ll n, k, l;
	cin >> n >> k >> l;
	vll v(n);
	vll pr(n);
	rep (i, 0, n) cin >> v[i];
	sort(allg(v));
	//
	/*
	ll total = k * l;
	ll mx = v[0];
	sumprefix(v, pr, mx);*/
	//
	priority_queue<pii> q;
	
	rep(i, 0, n) {
		ll alt = min(v[0], v[i] + k);
		ll lar = i + 1;
		ll idx = min(alt, lar);
		pii par = mk(idx, i);
		q.push(par);
	}
	/*
	while (!q.empty()) {
		ll x = q.top().ff;
		ll y = q.top().ss;
		showp(x, y);
		q.pop();
	}*/
	ans = q.top().ff;
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();	
	return 0;
}
