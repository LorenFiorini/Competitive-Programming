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
typedef map<int,int>  :: iterator mit;
typedef set<int> :: iterator sit;
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

void solve () {
	int n;
	cin >> n;
	vector<string> v(n);
	pii top = mk(-1,-1);
	pii bot = mk(-1,0);
	rep (i, 0, n) {
		cin >> v[i];
		rep (j, 0, n) {
			if (v[i][j] == '*') {
				if(top.ff == -1) {
					top.ff = i;
					top.ss = j;
				} else if (bot.ff == -1){
					bot.ff = i;
					bot.ss = j;					
				}
			}
		}
	}
	v[top.ff][top.ss] = '*';
	v[bot.ff][bot.ss] = '*';
		v[top.ff][bot.ss] = '*';
		v[bot.ff][top.ss] = '*';
	if (top.ff == bot.ff) {
		//int le = (bot.ss - top.ss);
		int le = 1;
		if (top.ff + le < n && bot.ff + le < n){
			v[top.ff + le][top.ss] = '*';
			v[bot.ff + le][bot.ss] = '*';
		} else {
			v[top.ff - le][top.ss] = '*';
			v[bot.ff - le][bot.ss] = '*';
		}
	} else if (top.ss == bot.ss) {
		//int le = (bot.ff - top.ff);
		int le = 1;
		if (top.ss + le < n && bot.ss + le < n){
			v[top.ff][top.ss + le] = '*';
			v[bot.ff][bot.ss + le] = '*';
		} else {
			v[top.ff][top.ss - le] = '*';
			v[bot.ff][bot.ss - le] = '*';	
		}
	} else {
		v[top.ff][bot.ss] = '*';
		v[bot.ff][top.ss] = '*';
	}
	
	
	rep (i, 0, n) {
		show(v[i]);
	}	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

