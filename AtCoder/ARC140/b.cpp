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

int dis(string s, int a) {
	int j = 1;
	while (a-j >= 0 && a+j < n && s[a-j] == 'A' && s[a+j] == 'C') {
		j++;
		//if (a-j < 0 || a+j == n) return j;
	}
	return j-1;
}

void solve () {
	int ans = 0;
	cin >> n;
	string s;
	cin >> s;
	vint v;
	
	rep(i, 0, n) {
		if (s[i] == 'R') {
			int d = dis(s, i);
			if (d > 0) v.pb(d);
			i += d;
		}
	}
	
	int m = len(v);
	int sum = 0;
	for (int num: v) sum += num-1;
	
	
	if (sum == m) {
		ans = 2 * m;
	} else if (sum > m) {
		ans = 2*m + 1;
	} else {
		ans = m + sum;
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
