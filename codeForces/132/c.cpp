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
	// left most and right most
	/*int i = 0;
	while (i < n/2 && s[i] == '?') {
		mp['?']--;
		mp['(']++;
		i++;
	}
	i = n-1;
	while (i >= n/2 && s[i] == '?') {
		mp['?']--;
		mp[')']++;
		i--;
	}*/

int n;

int dfs(string s, int pos, int cnt) {
	if (pos == n) return (cnt == 0);
	if (cnt < 0) return 0;


	int ans = 0;
	if (s[pos] == '?') {
		int a = dfs(s, pos+1, cnt + 1);
		if (a == -1) return -1;
		int b = dfs(s, pos+1, cnt - 1);
		if (b == -1) return -1;
		if (a == 1 && b == 1) return -1;
		if (a == 1 || b == 1) return 1;
	} else {
		if (s[pos] == '(') 
			ans = dfs(s, pos+1, cnt + 1);
		else 
			ans = dfs(s, pos+1, cnt - 1);
	}
	return ans;
}

void solve () {
	int ans = 0;
	string s;
	cin >> s;
	n = len(s);

	map<char, int> mp;
	for (char c : s) mp[c]++;
	if (max(mp['('], mp[')']) == n/2) ans = 1;

	//vint cnt = {mp['('], mp[')'], mp['?']};
	//showv(cnt, 3);

	if (!ans) ans = dfs(s, 0, 0);
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
