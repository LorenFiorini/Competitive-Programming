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

map<string, char> mp;


string help(string s, string ab, char c) {
	string t = "";
	int n = len(s);
	rep (i, 0, n) {
		if (i==n-1) {
			t.pb(s[i]);
		} else if (s[i]==ab[0] && s[i+1]==ab[1]) {
			t.pb(c);
			i++;
		} else {
			t.pb(s[i]);
		}
	}
	//show(t);
	return t;
}

bool change(string &s) {
	bool ans = false;
	
	each(it, mp) {
		string tmp = help(s, it->first, it->ss);
		if (len(tmp) < len(s)) {
			s.swap(tmp);
			ans=1;
		}
	}
	
	return ans;
}

void solve () {
	int n;
	cin >> n;
	string s;
	string t;
	cin >> s;
	
	while (n > 1 && change(s)) {
		n = len(s);
	}
	
	
	show(s);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp["01"] = '2';
	mp["12"] = '3';
	mp["23"] = '4';
	mp["34"] = '5';
	mp["45"] = '6';
	mp["56"] = '7';
	mp["67"] = '8';
	mp["78"] = '9';
	mp["89"] = '0';
	mp["90"] = '1';
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
