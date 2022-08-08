#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
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
	ll ans = 0;
	ll n,m,q;
	cin >> n >> m >> q;
	ll le, ri, x, id, jd, op;
	
	vvi query(q, vll(4));
	map<int, vint> mpij;
	map<int, vint> mpji;
	map<pii, ll> val;
	
	rep(i,0,q) {
		cin >> query[i][0];	
		op = query[i][0];	
		if (op == 1) {
			rep(j,1,4) cin >> query[i][j];
			query[i][1]--;	query[i][2]--;
		} else if (op == 2) {			
			rep(j,1,3) cin >> query[i][j];
		} else {
			rep(j,1,3) cin >> query[i][j];
			query[i][1]--;	query[i][2]--;
			id = query[i][1]; jd = query[i][2];
			mpij[id].pb(jd);
			mpji[jd].pb(id);
			val[{id, jd}] = 0;
		}
	}
	
	
	rep(i, 0, q) {
		op = query[i][0];
		if (op == 1) {
			le = query[i][1]; ri = query[i][2]; x = query[i][3]; 
			auto it = mpji.lower_bound(le);
			while (it != mpji.end() && it->ff <= ri) {
				for (auto i : it->ss) {
					val[{i, it->ff}] += x;					
				}
				it++;
			}
		} else if (op == 2) {			
			id = query[i][1]; x = query[i][2];
			if (mpij.find(id) != mpij.end()) {
				for (auto jo : mpij[id]) {
					val[{id, jo}] = x;					
				}
			}
			
		} else {
			id = query[i][1]; jd = query[i][2];
			ans = val[{id, jd}];
			show(ans);
		}
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
