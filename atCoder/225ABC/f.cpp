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
	int na = len(a);
	int nb = len(b);
	if (na != nb) return na < nb;
	return a < b;
}

int n, k;
string get(vstr &V) {
	vstr v(k);
	rep(i,0,k) v[i] = V[i];
	sort(all(v));
	
	string ans;
	rep (i, 0, k) ans += v[i];
	
	return ans;
}

void solve () {
	// INPUT
	cin >> n >> k;
	vstr a(n);
	vstr b(n);
	rep (i, 0, n) {
		string str;
		cin >> str;
		a[i] = str;
		b[i] = str;
	}
	
	// A concatenation
	string A;
	sort(all(a));
	rep (i, 0, k) A += a[i];
	
	// 2 concatenation
	string B;
	sort(all(b), cmp);
	rep (i, 0, k) B += b[i];
	showv(b, n);
	
	
	if (len(B) < len(A)) {
		// B
		//show("=");
		//show(B);
		B = get(b);
		show(B);
	} else {
		// A
		show(A);
		
	}
}
/*
5 3
ab
ab
ba
a
b

*/

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
