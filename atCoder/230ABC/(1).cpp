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

pii bina(ll a) {
	//range of k
	pii ran = {max(1-a, 1-b) , min(n-a, n-b)}; 
	pii rbn = {max(1-a, b-n) , min(n-a, b-1)}; 
	// range of paint
	pii ans = {a + max(ran.ff, rbn,ff), a + min(ran.ss, rbn,ss)};
	// actual indexes
	ans.ff = max(ans.ff - p, 0);
	ans.ss = min(ans.ss - p, q-p);
	
	if (ans.ss > ans.ff) return {0,0};
	
	return ans;
}

pii binb(ll a) {
	pii ran = {max(1-a, 1-b) , min(n-a, n-b)}; 
	pii rbn = {max(1-a, b-n) , min(n-a, b-1)};  
	pii ans = {max(ran.ff, rbn,ff), min(ran.ss, rbn,ss)};
	if (ans.ss > ans.ff) return {0,0};
	
	return ans;
}

void solve () {
	ll n,a,b;
	ll p,q,r,s;
	cin >> n >> a >> b;
	cin >> p >> q >> r >> s;
	ll N = q-p+1;
	ll M = s-r+1;
	vector<vector<char>> v(N, vector<char> (M, '.'));
	
	// inclusive K
	
	pii row = bina(a, ran, rbn);
	pii col = binb(b, ran, rbn);
	
	
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
