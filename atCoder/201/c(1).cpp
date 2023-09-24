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
#define precision(d) cout << setprecision(d) << fixed;

bool next(vint &v) {
	v[3]++;
	if (v[3] > 9) {
		v[3] = 0;
		v[2]++;
	}
	if (v[2] > 9) {
		v[2] = 0;
		v[1]++;
	}
	if (v[1] > 9) {
		v[1] = 0;
		v[0]++;
	}
	if (v[0] > 9) {
		return false;
	}
	return true;
}

bool ok(vint &v, int in, int nose) {
	seti must;
	rep (i, 0, in) must.insert(i);
	vector<bool> init(in, false);
	seti may;
	rep (i, in, in + nose) may.insert(i);
	
	rep (i, 0, 4) {
		int num = v[i];
		if (notin(must, num) && notin(may, num)) return false;
		if (num < in) init[num] = true;
	}
	rep (i, 0, in) {
		if (init[i] == false) return false;
	}
	return true;
}

void solve () {
	int ans = 0;
	string s;
	cin >> s;
	int in = 0, no = 0, nose = 0;
	
	rep (i, 0, 10) {
		if (s[i] == 'o') in++;
		else if (s[i] == 'x') no++;
		else nose++;
	}
	if (in > 4) {
		show(0);
		return;
	}
	vint v(4, 0);
	do {
		if (ok(v, in, nose)) {
			ans++;
		} 
	} while(next(v));
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}

