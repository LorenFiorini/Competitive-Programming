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

int ans = 0;
int n, k;
void dfs(int pos, vvi &v, vint sum, int strs) {
	int cnt = 0;
	bool com = 1;
	rep(i, 0, 26) {
		sum[i] += v[pos][i];
		if (sum[i] == k) cnt++;
		if (sum[i] > k) com = 0;
	}
	if (com && cnt == strs) {
		cnt = max(cnt, cnt * 2 - 1);
	}
	if (cnt > ans) {
		
	}
	ans = max(ans, cnt);
	
	rep(nxt, pos + 1, n) {
		dfs(nxt, v, sum, strs + 1);
	}
}

void solve () {
	cin >> n >> k;
	string s;
	vvi v(n, vint(26));
	rep(i,0,n) {
		cin >> s;		
		for (char c: s) {
			int p = c - 'a';
			v[i][p] = 1;
		}
	}
	// length 1 alphabets
	vint sum(26, 0);
	dfs(0, v, sum, 0);

	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
