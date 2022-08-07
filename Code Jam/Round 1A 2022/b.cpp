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
ll n;

void query() {
	rep(num, 1, n+1) cout << num << " ";
	cout << endl;
}

vint read() {
	vint v(n);
	rep(i,0,n) cin >> v[i];
	return v;
}

vint ans;
ll N;
void complete(ll dif) {
	for (ll num = n; num > 0; num--) {
		if (dif <= num) {
			ans.pb(dif);
			return;
		}
		ans.pb(num);
		dif -= num;
	}
}

//make difference less than N
bool dfs(vint &v, ll suma, ll sumb, int pos) {
	if (pos >= n) {
		if (abs(sumb - suma) <= N) {
			if (suma < sumb) {
				complete(sumb - suma);
			}
			return 1;
		}
		return 0;
	}
	
	cout << "-" << endl;
	if (suma > sumb) {
		if (dfs(v, suma, sumb + v[pos], pos + 1)) return 1;
		ans.pb(v[pos]);
		if (dfs(v, suma + v[pos], sumb, pos + 1)) return 1;
		ans.pop_back();
	} else {
		ans.pb(v[pos]);
		if (dfs(v, suma + v[pos], sumb, pos + 1)) return 1;	
		ans.pop_back();
		if (dfs(v, suma, sumb + v[pos], pos + 1)) return 1;		
	}
	return 0;
}

void solve () {
	cin >> n;
	N = n*(n+1) / 2;
	query();
	vint v = read();
	sort(allg(v));
	showv(v, n);
	
	ll suma = 0;
	ll sumb = 0;
	dfs(v, suma, sumb, 0);
	
	
	showv(ans, len(ans));
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		//cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
