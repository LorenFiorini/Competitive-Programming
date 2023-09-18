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

bool okay(int a, int b, int c) {
	vint v;
	v.pb(a);
	v.pb(b);
	v.pb(c);
	sort(all(v));
	if (v[2] == v[0] + v[1]) {
		return false;
	} 
	return true;
}


void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vint v(n);
	rep(i, 0, n) {
		cin >> v[i];
	} 
	
	ans += 2 * n - 1; // length 1 and 2
	if (n < 3) {
		show(ans);
		return;
	}
	
	//vint d;
	int sta = 0;
	rep (i, 2, n) 
	{
		int nw = i;
		rrep (j, i, sta + 1) 
		{
			int dij = i - j + abs(v[i] - v[j]);
			rrep (k, j, sta) 
			{
				int dik = i - k + abs(v[i] - v[k]);
				int djk = j - k + abs(v[j] - v[k]);
				if (okay(dij, dik, djk)){
					cout << k << " " << j << " " << i << "\n";
					//ans++;
					nw = min(nw, k);
				} else {
					break;
				}
			}
			if (nw != sta) break;
		}
		sta = nw;
	}
	
	
	show(ans);
	show("--------");
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
