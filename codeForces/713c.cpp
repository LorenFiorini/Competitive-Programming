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
typedef map<int,int>  :: iterator mit;
typedef set<int> :: iterator sit;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
//
#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

void solve () {
	int a, b;
	// a == '0'
	// b == '1'
	// inputs
	
	cin >> a >> b;
	string s;
	cin >> s;
	int n = len(s);
	
	// middle
	if (a % 2 == 1) {
		if (s[n/2] == '1') {
			show(-1);
			return;
		} 
		else if (s[n/2] == '?') {
			s[n/2] = '0';
		}
		a--;
	} else if (b % 2 == 1) {
		if (s[n/2] == '0') {
			show(-1);
			return;
		} 
		else if (s[n/2] == '?') {
			s[n/2] = '1';
		}
		b--;
	}
	// compulsory change
	rep (i, 0, n / 2) 
	{
		char l = s[i];
		char r = s[n - 1 - i];
		// 1
		if (l == '?' && r == '?') continue;
		
		//    2
		if (l == '?') 
		{
			if (r == '1') {
				s[i] = '1';
				b -= 2;
			} else if (r == '0') {
				s[i] = '0';
				a -= 2;
			} else {
				show(-1);
				return;
			}
		} // 3333333
		else if (r == '?') 
		{
			if (l == '1') {
				s[n-1 - i] = '1';
				b -= 2;
			} else if (l == '0') {
				s[n-1 - i] = '0';
				a -= 2;
			} else {
				show(-1);
				return;
			}
		} 
		else 
		{
			// 44444
			if (l == r) {
				if (l == '0') a-=2;
				else b -= 2;
			} else {
				// 555555
				show(-1);
				return;				
			}
		}
	}
	// over used
	if (a < 0 || b < 0) {
		show(-1);
		return;
	}
	
	// replacing others
	rep (i, 0, n/ 2) {
		char l = s[i];
		if (l == '?') {
			if (a > 0) {
				s[i] = '0';
				s[n-1 - i] = '0';
				a -= 2;
			} else {
				s[i] = '1';
				s[n-1 - i] = '1';
				b -= 2;	
			}
		}
	}
	if (a < 0 || b < 0) {
		show(-1);
		return;
	}
	
	show(s);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

