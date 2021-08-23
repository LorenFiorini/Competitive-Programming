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

// < powers of 2 (or their prefixes) , numbers to add on the right >
map<string, int> mp;

void powers() {
	// First add all powers of two
	for (ll i = 1; i < 1e15; i *= 2) {
		string s = to_string(i);
		mp.insert({s, 0});
	}
	// then add prefixes 
	each (it, mp) {
		string s = it->ff;
		int N = len(it->ff);
		rep (i, 1, N) 
		{
			string tmp = s.substr(0, i);
			int changes = min(N-i, i+1);
			auto it2 = mp.find(tmp);
			
			if (it2 == mp.end()) {
				mp.insert({tmp, changes});
			} else {
				it2->ss = min(it2->ss, changes);
			}
		}
	}	
}

void solve () {
	string n;
	cin >> n; 
	int ans = len(n) + 1;
	
	// generate all substrings of N
	set<string> sub; 
	sub.insert("");	
	rep (i, 0, len(n)) 
	{
		// TODO: modify this to search in a map
		string s{n[i]};	// <== amazing way to convert char int to string
		vector<string> add;
		for (auto it = sub.begin(); it != sub.end(); it++) 
		{
			string tmp = *it + s;
			if (mp.find(tmp) != mp.end()) {				
				//int changes = min(len(n) - len(tmp) + mp[tmp], len(tmp) + 1);
				//mp[tmp] = min(mp[tmp], changes);
				ans = min(ans, len(n) - len(tmp) + mp[tmp]);
			} else {
				mp[tmp] = len(tmp)+1;
			}
			add.pb(tmp);
		}
		
		for (string str : add) sub.insert(str);
	}
	
	mp[n] = ans;
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	powers();
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
