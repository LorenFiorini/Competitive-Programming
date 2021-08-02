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
typedef vector<pii> vii;
typedef vector<vint> vvi;
typedef map<int,int> mapii;
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
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(i, vv, n, m) rep(i, 0, n) {showv(j, vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";


void solve () {
	int ans = 0;
	int n;
	cin >> n;
	//vector< pair<double, double> > v(n);
	//cin >> v[i].ff >> v[i].ss;
	vii v(n);
	double fi = 12 / log(2);
	double ls = log(440);
	rep (i, 0, n) {
		string a, b;
		cin >> a >> b;
		
		double aa = 0, bb = 0;
		double pla = 0, plb = 0;
		int sz = a.size();
		if (sz > 15) {
			a.resize(15);
			pla = (double) sz - 15;
		}
		sz = b.size();
		if (sz > 15) {
			b.resize(15);
			plb = (double) sz - 15;
		}
		
		aa = stod(a);
		bb = stod(b);
		
		v[i].ff = round(fi * (log(aa) - ls + pla));
		v[i].ss = round(fi * (log(bb) - ls + plb));
	}
	int an=0, bo=0;
	rep (i, 0, n){
		an += v[i].ss % n;
		bo += v[i].ff % n;
	}
	
	an = an % n;
	bo = bo % n;
	ans = abs(bo - an);
	
	//cout << setprecision(8) << fixed;
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

