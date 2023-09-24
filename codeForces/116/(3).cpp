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

string S;
int n;
void count(int &ab, int &ba, string s) {
	ab = ba = 0;
	rep (i, 1, n)  {
		ba += (s[i-1] == 'b' && s[i] == 'a');
		ab += (s[i-1] == 'a' && s[i] == 'b');
	}
}

void change(int ab, int ba, string &s) {
	string str;
	if (ab > ba) str = "ab";
	else str = "ba";
	if (n > 2 && s[n-1] == s[n-2] && s[n-3] == s[n-2] && s[n-1] == str[1]) {
		s[n-1] = str[0];
		return;
	} 
	rep (i, 0, n-1) {
		if (s[i] == str[0] && s[i+1] == str[1] && (i+2>=n || s[i+2] == str[1])) {
			s[i] = str[1];
			return;
		}
	} 
	
	rep (i, 0, n-1) {
		if (s[i] == str[0] && s[i+1] == str[1]) {
			s[i] = str[1];
			return;
		}
	} 
}
/*
void more(int ab, int ba, string s) {
	string str;
	if (ab < ba) str = "ab";
	else str = "ba";
	rep (i, 0, n-1) {
		if (s[i] == s[i+1] && s[i] == str[0] && (i+2>=n || s[i+2] == str[1])) {
			s[i] = str[1];
			return;
		}
	} 	
	rep (i, 0, n-1) {
		if (s[i] == str[0] && s[i+1] == str[1]) {
			s[i] = str[1];
			return;
		}
	} 
}*/


void solve () {
	cin >> S;
	n = len(S);
	int ab = 0, ba = 0;
	// change to make the longer less
	int csl = 0;
	string sl = S;
	count(ab, ba, sl);
	while (ab != ba) {
		//cout << ab << " " << ba << endl;
		change(ab, ba, sl);
		count(ab, ba, sl);
		csl++;
	}
	/*
	// change to make the longer less
	int csm = 0;
	string sm = S;
	count(ab, ba, sm);
	while (ab != ba) {
		change(ab, ba, sm);
		count(ab, ba, sm);
		csm++;

	if (csl <= csm) {
		show(sl);
	} else {
		show(sm);
	}*/
	show(sl);
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
