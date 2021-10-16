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

int d, n, k;

void help(map<int, vint> &mp) {
	map<int, vint>::iterator it;
	vvi v(n);
	rep (i, 0, n) {
		int h, s, e;
		cin >> h >> s >> e;
		
		v[i] = (vint) {s, e, h};
		vint emp;
		mp[s] = emp;
		mp[e] = emp;
	}
	
	rep (i, 0, n) {		
		it = mp.find(v[i][0]);
		for ( ; it != mp.end(); it++){
			// break when points to day after end
			if (it->ff > v[i][1]) break; 			
			// push H
			
			it->ss.pb(v[i][2]);
		}	
	}
	
}

void solve () {
	ll ans = 0;
	
	map<int, vint> mp;
	help(mp);
	
	each(it, mp) {
		sort(allg(it->ss));
		
		ll sum = 0;
		rep (i, 0, min(k, len(it->ss))) {
			sum += (ll) it->ss[i];
		}
		
		ans = max(ans, sum);
	}
	
	show(ans);
	/*
	rep (i, 0, n) {
		rep (j, 0, 3) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}*/
}

void solvesmall() {
	int ans = 0;
	
	vvi v(n, vint(d+1, 0));
	rep (i, 0, n) {
		int h, s, e;
		cin >> h >> s >> e;
		rep (j, s-1, e) {
			v[i][j] = h;
		}
	}
	
	rep (j, 0, d) {
		vint day(n);
		rep (i, 0, n) {
			day[i] = v[i][j];
		}
		sort(allg(day));
		int sum = 0;
		rep (i, 0, k) sum += day[i];
		
		ans = max(ans, sum);
	} 
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cin >> d >> n >> k;
		cout << "Case #" << CASE << ": ";
		if (max(n, d) <= 1000) solvesmall();
		else solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
