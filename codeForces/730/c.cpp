#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef double db;
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

db ans;

void dfs(vector<db> v, db vol, int pos, int race) {
	if (pos == 2) {
		db tmp = 1;
		rep(i,0,3) if (v[i] > 0) tmp *= v[i];
		ans += (tmp * race);
		return;
	}
	
	rep (i,0,3) {
		if (v[i] > 0)  {
			// PICK v[i]
			vector<db> tmp(all(v));
			if (v[i] <= vol) {
				db re = v[i];
				swich (i) {
					case 0:
						v[0] = 0;
						v[1] += re / 2;
						v[2] += re / 2;
						break;
					case 1:
						v[1] = 0;
						v[0] += re / 2;
						v[2] += re / 2;
						break;
					case 2:
						v[2] = 0;
						v[1] += re / 2;
						v[2] += re / 2;
						
						break;
				}
				
			} else {
				v[i] -= vol;
			}
			
			
			v[i] = tmp;
		}
	}
}


void solve () {
	ans = 0;
	vector<db> v(3); 
	rep (i,0,3)cin >> v[i];
	db vol;
	cin >> vol;
	
	rep (i, 0, 3) {
		dfs(v, vol, i, 1);	
	}
	
	
	show(vol);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	precision(8);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
