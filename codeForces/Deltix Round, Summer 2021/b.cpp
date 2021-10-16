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

void help(vint &v, int n, int more, int &ans, int m) {
	// places where v[i] == more (same parity)
	vint st(m);
	int j = 0;
	rep (i,0,n) {
		if (v[i] == more) {
			st[j] = i; j++;
		}
	}
	
	int cor = 0;
	int suma = 0, sumb = 0;
	rep (i, 0, m) {
		suma += abs(st[i] - cor);
		cor += 2;
	}
	
	cor = n-1;
	for (int i = m-1; i >= 0; i--) {
		sumb += abs(st[i] - cor);
		cor -= 2;
	}
	
	ans = min(suma, sumb);
}


void solve () {
	int ans;
	int n;
	cin >> n;
	int par[2] = {0, 0};
	vint v(n);
	rep (i, 0, n) {
		int num;
		cin >> num;
		num %= 2;
		v[i] = num;
		par[num]++;
	}
	
	// Check if impossible
	int mx = (n+1) / 2;
	if (par[0] > mx || par[1] > mx) {
		show(-1);
		return;
	} 
	
	int more = v[0];
	if (par[0] > par[1]) {
		more = 0;
	} else if (par[0] < par[1]) {
		more = 1;
	} 
	
	help(v, n, more, ans, max(par[0], par[1]));
	
	show(ans);
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
