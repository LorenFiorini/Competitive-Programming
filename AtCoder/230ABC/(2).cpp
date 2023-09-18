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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << "";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

ll n,a,b;
ll p,q,r,s;
	
pii bin(pii ra) {
	//pii row = {max(p, a+ra.ff), min(q, a+ra.ss}); 
	//pii col = {max(r, b+ra.ff), min(q, b+ra.ss}); 
	// I, J
	pii start = {a+ra.ff, b+ra.ff};
	if (a+ra.ff < p) {
		ll d = p - a+ra.ff;
		start.ff += d; 
		start.ss += d; 
	}
	if (start.ss < r) {
		ll d = r - start.ss;
		start.ff += d; 
		start.ss += d; 
	}
	if (start.ff >= q || start.ss >= s) {
		return {0, 0};
	}
	return start;
}

pii binb(pii ra) {
	//pii row = {max(p, a+ra.ff), min(q, a+ra.ss}); 
	//pii col = {max(r, b+ra.ff), min(q, b+ra.ss}); 
	// I, J
	pii start = {a+ra.ff, b-ra.ff};
	if (a+ra.ff < p) {
		ll d = p - a+ra.ff;
		start.ff += d; 
		start.ss += d; 
	}
	if (start.ss > r) {
		ll d = r - start.ss;
		start.ff += d; 
		start.ss += d; 
	}
	if (start.ff >= q || start.ss >= s) {
		return {0, 0};
	}
	return start;
}

void paint(vector<vector<char>> &v, pii ran, ll n,ll m) {
	int i = 0;
	while (i+ran.ff-p < n && i+ran.ss-r < m) {
		v[i+ran.ff-p][i+ran.ss - r] = '#';
		i++;
	}
}

void paintb(vector<vector<char>> &v, pii ran, ll n,ll m) {
	int i = 0;
	while (i + ran.ff-p < n && ran.ss-i-r >= 0) {
		v[i+ran.ff - p][-i+ran.ss - r] = '#';
		i++;
	}
}

void solve () {
	cin >> n >> a >> b;
	cin >> p >> q >> r >> s;
	ll N = q-p+1;
	ll M = s-r+1;
	vector<vector<char>> v(N, vector<char> (M, '.'));
	
	// inclusive K
	pii ra = {max(1-a, 1-b) , min(n-a, n-b)}; 	
	pii ran = bin(ra);
	paint(v, ran, N, M);
	
	pii rb = {max(1-a, b-n) , min(n-a, b-1)}; 	
	pii ranb = binb(rb);
	paintb(v, ranb, N, M);
	
	showvv(v, N, M);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
