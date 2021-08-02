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

int a[4] = { -1, 0, 1, 0 };
int b[4] = { 0, -1, 0, 1 };
int n;

bool notvalid(int i , int j) {
	if (j > i || i < 0 || j < 0 || i >= n) return true;
	return false;
}



bool help(vvi &v, int num, int cant, int i, int j) {
	if (v[i][j] != 0) return 1;
	
	v[i][j] = num;
	cant--;
	if (cant == 0) return 0;
	
	rep (p, 0, 4) {
		int ii = i + a[p];
		int jj = j + b[p];
		if (notvalid(ii, jj)) continue;
		if (! help(v, num, cant, ii, jj)) return 0;
	}
	
	return 1;
}



void solve () {
	cin >> n;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	
	vvi ans(n, vint (n, 0));
	
	rep (po, 0, n) {
		int num = v[po];
		int cant = num;
		//show(num);
		if (help(ans, num, cant, po, po)) {
			show(-1);
			return;
		}
		/*
		int j = po;
		while (num > 0 && j >= 0) {
			if (ans[po][j] != 0) break;
			ans[po][j] = v[po];
			j--;
			num--;
		}
		if (num > 0) 
		{
			help(ans, num, po, j);
		}*/
		
		
	}
	
	
	
	rep (i, 0, n) {
		rep (j, 0, i + 1) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}


