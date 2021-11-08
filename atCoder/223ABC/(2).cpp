#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef double db;
typedef pair<db, db> pii;
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
#define a first
#define b second

void solve () {
	db ans = 0;
	int n;
	cin >> n;
	vpii v(n);
	rep (i, 0, n) cin >> v[i].a >> v[i].b;
	
	if (n == 1) {
		show(v[0].a / v[0].b);
		return;
	}
	
	vint leng(n);
	vector<db> tr(n);
	vector<db> tl(n);
	rep (i ,0 ,n) {
		tr[i] = v[i].a / v[i].b;
		tl[n-1-i] = v[n-1-i].a / v[n-1-i].b;
		leng[i] = v[i].a;
		if (i) {
			tr[i] += tr[i-1];
			tl[n-1-i] += tl[n-i];			
			leng[i] += leng[i-1];
		}
	}
	
	
	int pi = 0;
	int pj = n-1;
	while (pi < pj) {
		if (tr[pi] == tl[pj] && pi+1==pj) {
			// when they dont meet in the middle
			show((db)leng[pi]);
			return;
		} else if (tr[pi] < tl[pj]) {
			pi++;
		} else if (tr[pi] > tl[pj]) {
			pj--;
		} else {
			pi++;
			pj--;
		}
	}
	
	if (pi > 0) ans = leng[pi - 1];
	
	db R = ((pi - 1 >= 0) ? tr[pi-1] : 0);
	db L = ((pi + 1 < n) ? tl[pi+1] : 0);
	if (R < L) {
		db x = (L - R) * v[pi].b;
		ans += x;
		db left = v[pi].a - x;
		ans += left / (db)2;
	} else {
		db x = (R - L) * v[pi].b;
		db left = v[pi].a - x;;
		ans += left / 2;		
	} 
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cout << setprecision(12) << fixed;
	solve();
	
	return 0;
}

// Lorenzo Fiorini
