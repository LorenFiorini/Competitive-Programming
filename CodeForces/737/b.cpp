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

mpii :: iterator it;

bool cool(vint &v, mpii &mp, int l, int r) {
	if (v[r] <= v[l]) {
		// ... left --- right ...
		mp[v[r]]--;
		return (v[r] == v[l]);
	} 
	
	// NEXT ELEMENT IS GREATER THAN PREVIOUS FOR SURE
	for (it = mp.find(v[l]); it != mp.end(); it++) 
	{
		
		if (it->ff == v[r]) {
			mp[v[r]]--;
			return true;
		} else if (it->ss != 0){
			mp[v[r]]--;
			return false;
		}
	}
	return 1;
}

void solve () {
	int n, k;
	cin >> n >> k;
	mpii mp;
	vint v(n);
	rep (i, 0, n) {
		cin >> v[i];
		if (i) mp[v[i]]++;
	}
	
	if (n == k) {show("YES"); return;}
	
	vint sub;
	int l = 0;
	rep (i, 1, n) 
	{
		if (cool(v, mp, l, i)) {
			continue;
		} else {
			sub.pb(i - l);
			l = i;
		}
	}
	sub.pb(n-l);
	
	//showv(sub, len(sub));
	
	if (len(sub) <= k) {
		show("YES");
	} else {
		show("NO");
	}
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
 
