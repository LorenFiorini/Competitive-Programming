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

bool check(int le, int ri, string s) {
	while (le <= ri) {
		if (s[le] == '0') return 0;
		le++;
	}
	return 1;
}

bool inco(string s, int n, int k) {
	int ans = 0;

	rep (i, 0, n) {
		if (s[i] == '?') {
			int j = i;
			while (j+1 < n && s[j+1] == '?') {
				j++;
			}
			int d = j - i + 1;
			if (d > k) {
				return 0;
			} else if (d == k) {
				ans++;
				if (ans > 1) return 0;
			}
			i = j;
		}
	}
	return (ans == 1);
}

void solve () {
	int ans = 0;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int i = 0, j = n-1;

	while (i < n && s[i] != '1') i++;
	while (j >= 0 && s[j] != '1') j--;
	
	int d = j - i + 1;
	if (d == k) {
		ans = check(i, j, s);
	} else if (d > k) {
		ans = 0;
	} else if (d >= 0 && d < k) {
		if (check(i, j, s)) {
			if (i == 0 || j == n-1 || s[i-1] == '0' || s[j+1] == '0') {
				while (i > 0 && s[i-1] != '0') i--;
				while (j+1 < n && s[j+1] != '0') j++;
				d = j - i + 1;
				if (d >= k) ans = 1;
			} else {
				while (i > 0 && s[i-1] != '0') i--;
				while (j+1 < n && s[j+1] != '0') j++;
				d = j - i + 1;
				if (d == k) ans = 1;
			}
		} else {
			ans = 0;
		}
	} else if (d < 0) {
		// only 0 and ?
		ans = inco(s, n, k);
	}

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
