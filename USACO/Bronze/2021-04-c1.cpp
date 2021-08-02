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
typedef vector<pii> vii;
typedef vector<vint> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(i, vv, n, m) rep(i, 0, n) {showv(j, vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;

int n, m;
// coordenadas to num cow
map<pii, int> mp;
map<pii, int> :: iterator mit;
// 2 cows friends (num)
set<pii> fri;
set<pii> :: iterator sit;

void check(vvi &v, int r, int c) {
	bool mid24 = 0, ok24 = 0, mid34 = 0, ok34 = 0;
	pii v1 = mk(-1, -1);
	pii v2 = mk(-1, -1);
	pii v3 = mk(-1, -1);
	pii v4 = mk(-1, -1);
	if (r - 1 >= 0) v1 = mk(r - 1, c);
	if (c - 1 >= 0) v2 = mk(r, c - 1);
	if (c + 1 < m) v3 = mk(r, c + 1);
	if (r + 1 < n)  v4 = mk(r + 1, c);
	// 1
	if (!notin(mp, v1)) {
		// 1 2
		if (!notin(mp, v2)) 
		{
			int row = r - 1;
			int col = c - 1;
			pii par = mk(mp.at(v1), mp.at(v2));
			pii rap = mk(mp.at(v2), mp.at(v1));
			if (v[row][col]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[row][col] = 0;
				}
			} else if (v[r][c]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r][c] = 0;
				}
			}
		}
		// 1 3
		if (!notin(mp, v3)) 
		{
			int row = r - 1;
			int col = c + 1;
			pii par = mk(mp.at(v1), mp.at(v3));
			pii rap = mk(mp.at(v3), mp.at(v1));
			if (v[row][col]) {
				if (notin(fri, par) && notin(fri, rap)){
					fri.insert(par);
					v[row][col] = 0;
				}
			} else if (v[r][c]) {
				if (notin(fri, par) && notin(fri, rap)){
					fri.insert(par);
					v[r][c] = 0;
				}
			}
		}
		// 1 4
		if (!notin(mp, v4)) 
		{
			pii par = mk(mp.at(v1), mp.at(v4));
			pii rap = mk(mp.at(v4), mp.at(v1));
			if (v[r][c]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r][c] = 0;
				}
			}
		}
	}
	// 2
	if (!notin(mp, v2)) 
	{
		// 2 3
		if (!notin(mp, v3)) 
		{
			pii par = mk(mp.at(v2), mp.at(v3));
			pii rap = mk(mp.at(v3), mp.at(v2));
			if (v[r][c]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r][c] = 0;
				}
			}
		}
		// 2 4
		if (!notin(mp, v4)) 
		{
			if (v[r][c]) mid24 = true;
			if (v[r+1][c-1]) ok24 = true;
		}
	}
	// 3
	if (!notin(mp, v3)) 
	{
		// 3 4
		if (!notin(mp, v4)) 
		{
			if (v[r][c]) mid34 = true;
			if (v[r+1][c-1]) ok34 = true;
		}
	}
	if (mid24 && !mid34) {
		pii par = mk(mp.at(v4), mp.at(v2));
		pii rap = mk(mp.at(v2), mp.at(v4));
		if (v[r][c]) {
			if (notin(fri, par) && notin(fri, rap)) {
				fri.insert(par);
				v[r][c] = 0;
			}
		}
		// agregar ok34 maybe -> no hay v3
		return;
	} else if (!mid24 && mid34) {
		pii par = mk(mp.at(v4), mp.at(v3));
		pii rap = mk(mp.at(v3), mp.at(v4));
		if (v[r][c]) {
			if (notin(fri, par) && notin(fri, rap)) {
				fri.insert(par);
				v[r][c] = 0;
			}
		}
		return;
		// agregar ok24 maybe -> no hay v2
	}
	if (!mid24 && !mid34) {
		if (ok24) {
			pii par = mk(mp.at(v4), mp.at(v2));
			pii rap = mk(mp.at(v2), mp.at(v4));
			if (v[r + 1][c - 1]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r + 1][c - 1] = 0;
				}
			}
		}
		if (ok34) {
			pii par = mk(mp.at(v4), mp.at(v3));
			pii rap = mk(mp.at(v3), mp.at(v4));
			if (v[r + 1][c + 1]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r + 1][c + 1] = 0;
				}
			}
		}
		return;
	}
	if (mid24 && mid34) {
		if (ok24 && !ok34) {
			pii par = mk(mp.at(v4), mp.at(v3));
			pii rap = mk(mp.at(v3), mp.at(v4));
			if (v[r][c]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r][c] = 0;
				}
			}
			par = mk(mp.at(v4), mp.at(v2));
			rap = mk(mp.at(v2), mp.at(v4));
			if (v[r + 1][c - 1]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r + 1][c - 1] = 0;
				}
			}
			return;			
		}
		if (!ok24 && ok34) {
			pii par = mk(mp.at(v4), mp.at(v2));
			pii rap = mk(mp.at(v2), mp.at(v4));
			if (v[r][c]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r][c] = 0;
				}
			}
			par = mk(mp.at(v4), mp.at(v3));
			rap = mk(mp.at(v3), mp.at(v4));
			if (v[r + 1][c + 1]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[r + 1][c + 1] = 0;
				}
			}
			return;			
		} else {
			check(v, r + 1, c - 1);
			check(v, r + 1, c + 1);
			int ava = 0;
			if (v[r][c]) ava++;
			if (v[r+1][c-1]) ava++;
			if (v[r+1][c+1]) ava++;
			if (ava >= 2) {
				pii par = mk(mp.at(v4), mp.at(v2));
				pii rap = mk(mp.at(v2), mp.at(v4));
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
				}
				par = mk(mp.at(v4), mp.at(v3));
				rap = mk(mp.at(v3), mp.at(v4));
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
				}
			}
		}
	}
	return;
}


void solve () {
	int ans = 0;
	// INPUT
	cin >> n >> m;
	vvi v(n, vint (m, 0));
	int cnt = 1;
	rep (i, 0, n) {
		string str;
		cin >> str;
		rep (j, 0, m) {
			if (str[j] == 'C') {
				pii coor = mk(i, j);
				mp[coor] = cnt;
				cnt++;
			}
			if (str[j] == 'G') v[i][j] = 1;
		}
	}
	// TASKS
	rep (i, 0, n) rep (j, 0, m) {
			if (v[i][j]) check(v, i, j);
	}
	ans = len(fri);	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}



