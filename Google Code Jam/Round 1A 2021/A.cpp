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
typedef map<int,int>  :: iterator mit;
typedef set<int> :: iterator sit;
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
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;




void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep(i,0,n) cin >> v[i];
	
	rep (i, 1, n) 
	{
		if (v[i-1] == v[i]) {
			v[i] *= 10;
			ans++;
		}
		else if (v[i-1] >= v[i]) {
			// adding enough 0 zeroes
			ll num = v[i];
			ll d = 0;
			while (num < v[i-1]) 
			{
				num *= 10;
				d++;
			} 
			
			// changgin digist inside
			ll ex = 1, cnt = 1;
			while (cnt < d) {
				ex *= 10; cnt++;
			}
			//show(ex);
			//show(v[i] / ex);
			if (v[i-1] / ex <= v[i]) 
			{
				ll end = v[i-1] % ex + 1;
				v[i] *= (d-1);
				v[i] += end; 
				ans += d-1;
			} else {
				v[i] = num;
				ans += d;
			}
		}
	}
	showv(v,n);
	
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int C = 1;
	while (C <= T) {
		cout << "Case #" << C << ": ";
		solve();
		C++;
	}
	
	return 0;
}

