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


bool cmp(vint &a, vint &b) {
	//if (a[1] == b[1]) return a[0] < b[0];
	return a[1] < b[1];
}

bool cmp2(vint &a, vint &b) {
	//if (a[1] == b[1]) return a[0] < b[0];
	return a[0] < b[0];
}

void solve () {
	int ans = 0;
	int n, le, ri, num;
	cin >> n;
	vvi v(n, vint(3));
	vint a(n);
	
	// id -> [l, r]
	rep(i, 0, n) {
		cin >> num;
		// inclusive UB
		if (num) ri = (i + 1) / num;
		else ri = n;

		le = (i+1) / (num+1) + 1;
		v[i] = {le, ri,  i};
	}
	sort(all(v), cmp);
	sort(all(v), cmp2);
	
	rep(i, 0, n) {
		a[v[i][2]] = i + 1;
		 
	}
	showv(a, n);

	//rep(i, 0, n) {	cout << v[i][3] << " ";}cout << "\n";
	//showvv(v, n, 3); show("");
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
