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

bool help(priority_queue<pair<int, char>> &v, string &s, int n) {
	map<char, int> mp;
	rep (i, 0, n) {
		mp[s[i]]++;
	}
	// number left, char
	each(it, mp) {
		if (it->ss *2 > n) {
			return true;
		}
		v.push( {it->ss, it->ff} );
	}
	return false;
}

void solve () {
	string s;
	cin >> s;
	int n = len(s);
	
	priority_queue<pair<int, char>> v;
	bool imp = help(v, s, n);
	if (imp) {show("IMPOSSIBLE");	return;	}
	
	
	// make wheneevr possible
	string str;
	rep (i, 0, n) {
		vector<pair<int, char>> tmp;
		pair<int, char> p;
		do{
			p = v.top();
			v.pop();
			tmp.pb(p);		
		} while (p.ss == s[i]);
		
		tmp[len(tmp) - 1].ff -= 1;
		str.pb(p.ss); // ADD
		
		for (pair<int, char> par : tmp) {
			if (par.ff > 0) v.push(par);
		}
	}
	
	show(str);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
