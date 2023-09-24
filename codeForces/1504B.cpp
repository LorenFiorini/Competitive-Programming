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
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second
/*
void solve () {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	a += '0';
	b += '0';
	
	int cnt = 0;
	rep (i, 0, n) 
	{
		cnt += (a[i] == '1') - (a[i] == '0');
		// +1 si A[i] == 1
		// -1 si A[i] == 0
		if ((a[i] == b[i]) != (a[i+1] == b[i+1]) and cnt != 0) {
			// TRUE -> si A y B son iguales en 'i', pero ditintas en 'i+1'  (o viceversa)
			// 		-> Y si hay igual numero de '1' y '0' en A hasta posicion 'i'
			show("NO");
			return;
		} 
	}
	show("YES");
}*/
void get(vvi&a, vint &b) {
	string tmpa, tmpb;
	cin >> tmpa >> tmpb;
	rep (i, 0, n) {
		a[i][0] = (tmpa[i] == '1');
		a[i][1] = (tmpa[i] != '1');
		b[i] = (tmpb[i] == '1');
	}
}


void solve () {
	int n;
	cin >> n;
	vvi a(n, vint(2));
	vint b(n);
	get(a, b);
	
	rep (i, 0, n) {
		
	}
	
	
	show("YES");
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
