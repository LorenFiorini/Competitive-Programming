#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
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
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
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
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;

ll n, m;
// coordenadas to num cow
map<pii, ll> mp;
map<pii, ll> :: iterator mit;
// 2 cows friends (num)
set<pii> fri;
set<pii> :: iterator sit;

void check(vector<vll> &v, ll r, ll c) {
	pii v1 = mk(r - 1, c);
	pii v2 = mk(r, c - 1);
	pii v3 = mk(r, c + 1);
	pii v4 = mk(r + 1, c);
	// 1
	if (!notin(mp, v1)) {
		// 1 2
		if (!notin(mp, v2)) 
		{
			ll row = r - 1;
			ll col = c - 1;
			pii par = mk(mp.at(v1), mp.at(v2));
			pii rap = mk(mp.at(v2), mp.at(v1));
			if (v[row][col]) {
				if (notin(fri, par) && notin(fri, rap)) {
					fri.insert(par);
					v[row][col] = 0;
				}
			} else if (v[r][c] && notin(fri, rap)) {
				if (notin(fri, par)) {
					fri.insert(par);
					v[r][c] = 0;
				}
			}
		}
		// 1 3
		if (!notin(mp, v3)) 
		{
			ll row = r - 1;
			ll col = c + 1;
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
			ll row = r + 1;
			ll col = c - 1;
			pii par = mk(mp.at(v4), mp.at(v2));
			pii rap = mk(mp.at(v2), mp.at(v4));
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
	}
	// 3
	if (!notin(mp, v3)) 
	{
		// 3 4
		if (!notin(mp, v4)) 
		{
			ll row = r + 1;
			ll col = c + 1;
			pii par = mk(mp.at(v4), mp.at(v3));
			pii rap = mk(mp.at(v3), mp.at(v4));
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
	}
}


void solve () {
	ll ans = 0;
	// INPUT
	cin >> n >> m;
	vector<vll> v(n, vll (m, 0));
	ll cnt = 1;
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
	showvv(v, n, m);
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

