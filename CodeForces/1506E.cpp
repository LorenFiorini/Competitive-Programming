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
int n;

void get_min(vint &v, seti st) {
	rep (i, 0, n) {
		if (v[i] == 0) {
			v[i] = *(st.begin());
			st.erase(v[i]);
		}
	}
}

void get_max(vint &v, seti st) {
	rep (i, 0, n) {
		if (v[i] == 0) 
		{
			for (int num = v[i-1] - 1; num > 0; num--) {
				if (st.find(num) != st.end()) {
					v[i] = num;
					st.erase(num);
					break;
				}
			}
		}
	}
}

void solve () {
	cin >> n;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	
	seti stn;
	seti stx;
	rep (i, 1, n+1) {
		stn.insert(i);
		stx.insert(i);
	}
	
	vint mn(all(v));
	vint mx(all(v));
	rep (i, 0, n) {
		if (i == 0 || v[i-1] != v[i]) {
			stn.erase(v[i]);
			stx.erase(v[i]);
		} else {
			//min vector
			mn[i] = *(stn.begin());
			stn.erase(mn[i]);
			
			// max vector
			/*	
			for (int num = v[i-1] - 1; num > 0; num--) {
				if (stx.find(num) != stx.end()) {
					mx[i] = num;
					stx.erase(num);
					break;
				}
			}*/
			auto up = stx.begin();
			if (len(stx) > 1) {
				up = upper_bound(all(stx), v[i]);
				up--;
			}
			mx[i] = *(up);
			stx.erase(up);
		}
	}
	
	//get_min(mn, st);
	//get_max(mx, st);
	
	showv(mn, n);
	showv(mx, n);
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
