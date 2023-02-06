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
#define showv(v, n) rep(index, 0, n) {cout << v[index] << " ";} cout << "\n";
#define showvp(v, n) rep(index, 0, n) {showp(v[index].ff, v[index].ss);}
//#define showvv(vv, n, m) rep(row, 0, n) {showv(vv[row], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

void showmat(vvi &v) {
	for (auto r: v) {
		for (auto a: r) cout << a << " ";
		cout << endl;
	}
}

void solve () {
	int ans = 0;
	int n, m;
	cin >> n;
	vvi v(n);
	vll nums(n, 0);

	rep (i, 0, n) {
		cin >> m;
		vint row(m);
		rep (j, 0, m) {
			cin >> row[j];
			nums[i] += (1LL << row[j]);
		}
		v[i] = row;
	}

	showv(nums, n);
	showmat(v);
	if (ans) {
		show("Yes");
	} else {
		show("No");
	}
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
