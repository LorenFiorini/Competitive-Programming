#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define mod 998244353 
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

int n;

void next(vint &vec) {
	int tmp = vec[n-1];
	rrep(i, n, 1) {
		vec[i] = vec[i-1];
	}
	vec[0] = tmp;
}


void solve () {
	cin >> n;
	vvi v(2 * n, vint (n));
	// <Permutation, pos>
	map<vint, int> mp;
	map<vint, int>::iterator it;
	rep (i, 0, 2 * n) {
		rep (j, 0, n) {
			cin >> v[i][j];
		}
		mp[v[i]] = i;
	}
	//show("LEN");
	//show(len(mp));
	// SECONDLINE
	seti ans;
	vint fir(n);
	rep (i, 0, n) fir[i] = i + 1;
	rep (i, 0, n) {
		it = mp.find(fir);
		if (it != mp.end()) {
			ans.insert(it->ss + 1);
			mp.erase(it);
		}
		next(fir);
	}
	
	// COUNT 
	int res = 1;
	while (len(mp) > 0) {
		it = mp.begin();
		vint tmp(all(it->ff));
		int cnt = 0;
		rep (i, 0, n+1) {
			it = mp.find(tmp);
			if (it != mp.end()) {
				showv(it->ff, n);
				mp.erase(it);
				cnt++;
			}
			next(tmp);
		}
		if (cnt > 1)res++;
	}
	
	
	show(res);
	each(iter, ans) {
		cout << *iter << " ";
	}
	cout << "\n";
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
