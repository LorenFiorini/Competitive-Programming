#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
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
#define ff first
#define ss second
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";


bool solve (void) {
	int ans = 0;
	string s;
	cin >> s;
	int n = len(s);
	if (n != 8) return 0;
	
	map<char, int> mp;
	for (char c: s) mp[c]++;
	if (mp['K'] != 1 || mp['Q'] != 1 || mp['R'] != 2 || mp['B'] != 2 || mp['N'] != 2)
		return 0;

	int rs = 0;
	for (char c: s) {
		if (c == 'R') rs++;
		if (c == 'K' && rs != 1) return 0;
	}
	
	int bs = -1;
	rep (i, 0, n) {
		if (s[i] == 'B') {
			if (bs == -1) {
				bs = i;
			} else {
				if (bs % 2 == i % 2)
					return 0;
			}
		}
	}

	return 1;
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	if (solve()) {
		show("Yes");
	} else {
		show("No");
	}
	
	return 0;
}

// Lorenzo Fiorini
