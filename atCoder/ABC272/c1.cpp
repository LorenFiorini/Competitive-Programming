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


void solve () {
	int ans = 0;
	int n;
	cin >> n;
	vint v(n);
	rep (i, 0, n) cin >> v[i];
	sort(allg(v));

	if (n == 2) {
		if ((v[0] + v[1]) % 2 == 0) {
			ans = v[0] + v[1];
		} else {
			ans = -1;
		} 
	} else if (n == 3) {
		rep (i, 0, 3) {
			rep (j, i + 1, 3) {
				if ((v[i] + v[j]) % 2 == 0) {
					ans = max(ans, (v[i] + v[j]));
				} 
			}
		}
	} else {
		int even[2] = {-1, -1};
		int odd[2] = {-1, -1};
		for (auto num: v) {
			if (num % 2) {
				if (odd[0] == -1) odd[0] = num;
				else if (odd[1] == -1) odd[1] = num;
			} else {
				if (even[0] == -1) even[0] = num;
				else if (even[1] == -1) even[1] = num;
			}
			if (odd[1] != -1 && even[1] != -1) {
				ans = max(even[0] + even[1], odd[0] + odd[1]);
				break;
			}
		}

		if (odd[1] == -1) ans = even[0] + even[1];
		else if (even[1] == -1) ans = odd[0] + odd[1];
	}

	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
