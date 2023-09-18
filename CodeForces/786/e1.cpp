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

void solve () {
	int n, m, q;
	cin >> n >> m >> q;
	int total = 0;
	// column to set<row>
	map<int, seti> mp;
	string s;
	rep(i,0,n) {
		cin >> s;
		rep(j,0,m) {
			if (s[j] == '*') {
				mp[j].insert(i);
				total++;
			}
		}
	}
	
	while (q--) {
		int r, c;
		cin >> r >> c;
		r--; c--;
		if ((mp.find(c) != mp.end()) && (mp[c].find(r) != mp[c].end())) {
			mp[c].erase(r);
			total--;
			if (mp[c].size() == 0) {
				mp.erase(c);
			}
		} else {
			mp[c].insert(r);
			total++;
		}
		
		int ans = total;
		int comC = total / n;
		int comR = total % n;
		each(it, mp) {
			if ((it->ff) < comC) {
				ans -= len(it->ss);
			} else if ((it->ff) == comC) {
				each(ite, it->ss) {
					if ((*ite) < comR) {ans--;}
					else {break;}
				}
				break;
			} else {
				break;
			}
		}
		
		show(ans);
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
