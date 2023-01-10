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


void solve (int CASE) {
	int n, k;
	cin >> n >> k;
	
	vint v(n);
	rep (i, 0, n) cin >> v[i]; 
	v.pb(0); v.pb(k + 1);
	sort(all(v));
	//showv(v, n+2);
	
	vint pr;
	
	rep (i, 1, n + 2) 
	{
		int l = v[i-1];
		int r = v[i];
		if (r - l <= 1) continue;
		
		int prob = r - l - 1;
		if (l == 0 || r == k+1 || prob == 1) {
			pr.pb(prob);
		} else {
			if (prob & 1) {
				prob /= 2;
				pr.pb(prob);
				pr.pb(prob + 1);
			} else {
				prob /= 2;
				pr.pb(prob);
				pr.pb(prob);
			}
		}
		
		
	}
	pr.pb(0); pr.pb(0);
	sort(all(pr), greater<int> ());
	double ans = (double) pr[0] + (double) pr[1];
	ans /= (double) k;
	
	//showv(pr, len(pr));
	
	cout << "Case #" << CASE << ": " << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	precision(8);
	int c = 1;
	int t; cin >> t; 
	while (t--) {
		solve(c);
		c++;
	}
	
	return 0;
}


