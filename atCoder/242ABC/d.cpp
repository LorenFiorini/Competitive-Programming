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

map<char, string> mp;


void solve (int t, int k, stack<char> st) {
	int tot = 0;
	int cnt = 0;
	
	while (tot < t) {
		char c = st.top();
		st.pop();
		
		cout << c;
		
		st.push(mp[c][0]);
		st.push(mp[c][1]);
		
		cnt++;
		tot++;
		if (cnt > k) {
			cnt = 0;
			st.pop();
		}
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	mp['A'] = "BC";
	mp['B'] = "CA";
	mp['C'] = "AB";

	string s;
	cin >> s;
	int q;
	cin >> q;
	
	stack<char> st;
	for (char c : s) st.push(c);
	
	while (q--) {
		int t, k;
		cin >> t >> k;
		
		solve(t, k, st);
	}
	
	return 0;
}

// Lorenzo Fiorini
