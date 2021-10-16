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
	int n, m;
	cin >> n >> m;
	
	vstr v(2 * n);
	set<pii> st;
	
	rep (i, 0, 2*n) {
		cin >> v[i];
		st.insert({0, i});
	}
	
	rep (match, 0, m) {
		vpii vec(all(st));
		st.clear();
		
		rep (i, 0, n) {
			pii a = vec[2*i];
			pii b = vec[2*i + 1];
			
			if (v[a.ss][match] == v[b.ss][match]) {
				// nothing
				st.insert({a.ff + 1, a.ss});
				st.insert({b.ff + 1, b.ss});
			} else if ((v[a.ss][match]=='G' && v[b.ss][match]=='C') || (v[a.ss][match]=='C' && v[b.ss][match]=='P') || (v[a.ss][match]=='P' && v[b.ss][match]=='G') ) {
				st.insert({a.ff, a.ss});
				st.insert({b.ff+1, b.ss});
			} else {
				st.insert({a.ff+1, a.ss});
				st.insert({b.ff, b.ss});
			}
		}
		
	}
	
	each(it, st) {
		pii a = *it;
		showp(a.ff, a.ss);
		show(a.ss + 1);
	}
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
