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

bool cmp(string &a, string &b) {
	int n = len(a);
	int m = len(b);
	if (n == m) return a > b;
	return n > m;
}

/*
vstr get(string t) {
	set<string> sub;
	string s;
	rep(i, 0, n) {
		rep(j, i + 1, n) {

		}
	}
}*/

void solve () {
	string t;
	cin >> t;
	int n, m = len(t);
	cin >> n;
	vstr v(n);
	rep(i, 0, n) cin >> v[i];
	//sort(all(v), cmp);

	//vstr sub = get(t);
	//showv(v, n);
	int ans = 0;
	vvi vec(n, vint(m, 0));
	vint suma(m);

	rep(i, 0, n) {
		int sz = len(v[i]);

		rep (j, 0, m - sz + 1) {
			bool ok = 1;
			rep(k, 0, sz) {
				ok &= (v[i][k] == t[j + k]);
				if (!ok) break;
			}
			rep(k, 0, sz) {
				if (!ok) break;
				vec[i][j + k]++;
				suma[j + k]++;
			}
		}
	}

	rep(i, 0, m) if (suma[i] == 0) {
		show("-1");
		return;
	}



	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
