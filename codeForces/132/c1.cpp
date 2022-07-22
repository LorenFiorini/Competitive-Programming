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

int n;
string s;
map<vint, int> mp;

int dfs(int pos, int c0, int c1) {

	//cout << pos << " ";
	//cout << c0 << " ";
	//cout << c1 << "\n";

	if (pos == n) return (c0 == c1);
	int mx = max(c0, c1);
	if (mx > n/2) return 0;
	vint vec = {pos, c0, c1};
	if (mp.find(vec) != mp.end()) return mp[vec];
	


	int ans = 0;
	if (s[pos] == '?') {
		int a = dfs(pos+1, c0+1, c1);
		if (a == -1) {
			ans = -1;
		} else {
			int b = dfs(pos+1, c0, c1+1);
			if (b == -1) {
				ans = -1;
		}

			continue;
		}
		
		if (a == 1 && b == 1) ans = -1;
		else if (a == 1 || b == 1) ans = 1;
	} else {
		if (s[pos] == '(') ans = dfs(pos+1, c0+1, c1);
		else ans = dfs(pos+1, c0, c1+1);
	}

	mp[vec] = ans;
	return ans;
}

void solve () {
	mp.clear();
	int ans = 0;
	cin >> s;
	n = len(s);

	map<char, int> mp;
	for (char c : s) mp[c]++;
	if (max(mp['('], mp[')']) == n/2) ans = 1;

	if (!ans) ans = dfs(0, 0, 0);
	//cout << ans;
	if (ans == 1) {
		show("YES");
	} else {
		show("NO");
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
