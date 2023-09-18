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

int dfs(int pos, string s) {
	
	vint v(3);
	rep (i, pos, n) {
		int c = s[i] - 'a';
		int ans = i - pos + 1;
		v[c]++;
		if (v[0] > max(1, max(v[1], v[2]))) {
			return ans;
		}
		if (ans > 7) break;
	}
	return INF;
}

void solve () {
	int ans = INF;
	
	cin >> n;
	string s;
	cin >> s;
	
	//find 2 next to each other
	rep (i, 1, n) {
		if (s[i-1] == 'a' && s[i] == 'a') {
			show(2);
			return;
		}
		if (i>=2 && s[i-2] == 'a' && s[i] == 'a') {
			ans = min(ans, 3);
		}
		
		if (i>=3 && s[i-3] == 'a' && s[i] == 'a') {
			if (s[i-2] != s[i-1]) {
				ans = min(ans, 4);			
			} else {
				if (i+3 < n) {
					vint v(3, 0);
					rep (j, i-3, i+4) {
						int c = s[j] - 'a';
						v[c]++;
					}
					if (v[0] > max(v[1], v[2])) ans = min(ans, 7);
				}
			}
		}
	}
	
	
	
	if (ans == INF) ans = -1;
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
