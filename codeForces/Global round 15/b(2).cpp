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

void solve () {
	int n;
	cin >> n;
	vector<vpii> v(5, vpii(n));
	rep (j, 0, n) {
		rep (i, 0, 5) {
			// SCORE, COMPETITOR
			cin >> v[i][j].ff;
			v[i][j].ss = j;
		}
	}
	//sprt by performance
	rep (i, 0, 5) {
		sort(all(v[i]));
	}
	/*
	//calculate points
	vpii best(n, {0, 0});
	rep (j, 0, n) rep (i, 0, 5) {
		best[v[i][j].ss].ff += n - j;
		best[v[i][j].ss].ss = v[i][j].ss;
		
	}*/
	
	// get top points
	/*vint ans;
	int mx = 0;
	rep (i, 0, n) {
		if (best[i] > mx) {
			mx = best[i];
			ans.clear();
			ans.pb(i);
		} else if (best[i] == mx) ans.pb(i);
	}*/
	//sort(allg(best));
	int m = min(n, max(n/80, 300));
	unordered_set<int> st;
	rep (j, 0, m) {
		rep (i, 0, 5) {
			st.insert(v[i][j].ss);
		}
	}
	
	//check best ones
	//rep (kk, 0, m)
	for (int comp : st)
	{
		//int comp = best[kk].ss;
		vint vec(n, 0);
		rep (i, 0, 5) {
			bool flag = false;
			rep (j, 0, n) {
				if (v[i][j].ss == comp) flag = true;
				if (flag) {
					vec[v[i][j].ss]++;
				}
			}
		}
		// CHECK IF >= 3
		bool ok = true;
		rep (i, 0, n) {
			if (vec[i] < 3) {
				ok = false;
				break;
			}
		}
		if (ok) {
			show(comp+1);
			return;
		}
	}
	
	
	show(-1);
	
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
