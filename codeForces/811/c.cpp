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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "\n";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

int MX = 46;
vint ans(MX);

void help() {
	rep(i, 1, MX) {
		if (i < 10) {
			ans[i] = i;
		} else if (i < 18) {
			ans[i] = (i-9)*10 + 9;
		} else if (i < 25) {
			ans[i] = (i-17)*100 + 89;
		} else if (i < 31) {
			ans[i] = (i-24)*1000 + 789;
		} else if (i < 36) {
			ans[i] = (i-30)*10000 + 6789;
		} else if (i < 40) {
			ans[i] = (i-35)*100000 + 56789;
		} else if (i < 43) {
			ans[i] = (i-39)*1000000 + 456789;
		} else if (i < 45) {
			ans[i] = (i-42)*10000000 + 3456789;
		} else {
			ans[i] = 123456789;
		}
	}
	//showv(ans, MX);
}

void solve () {
	int num;
	cin >> num;
	show(ans[num]);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();

	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
