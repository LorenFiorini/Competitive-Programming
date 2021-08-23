#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef long long db;
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

map<int, double> answer;

int until_empty(vint &v, int n) {
	int ans = 1;
	int lst = v[0];
	rep (i, 1, n) {
		if (v[i] > lst) {
			lst = v[i];
			ans++;
		}
	}
	return ans;
}

void get() {
rep (n, 1, 11) 
{
	// precalculate 
	int ans = 0;
	int tot = 1; rep (A, 1, n+1) tot *= A;
	
	vint v(n);
	rep(i,0,n) v[i] = i+1;
	
	do {
		ans += until_empty(v, n);
	} while(next_permutation(all(v)));
	
	double a = ans;
	double b = tot;
	//cout << a << " " << b << "\n";
	//cout << a / b << "\n";
	answer[n] = ((double)(a / b));
}
}


void solve () {
	int n;
	cin >> n;
	cout << setprecision(8) << fixed;
	cout << answer[n] << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(8) << fixed;
	get();
	
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
