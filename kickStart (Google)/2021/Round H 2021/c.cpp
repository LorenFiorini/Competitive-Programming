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

bool cmp(string s, string  t) {
	int m = len(t);
	if (m!=n) return 0;
	return 1;
}

bool change(string &s) {
	string t = "";
	//bool put = 0;
	rep (i, 0, n) {
		if (i == n-1) {
			t.pb(s[i]);
			break;
		}
		int a = (s[i] - '0');
		int b = (s[i+1] - '0');
		
		if ((a+1)%10 == b) {
			t.pb((char) ((b+1)%10 + '0'));
			i++;
		} else {
			t.pb(s[i]);
		}
	}
	//if (put) t.pb(s[n-1]);
	
	if (cmp(s,t)) return false;
	
	s.swap(t);
	return 1;
}

void solve () {
	cin >> n;
	string s;
	cin >> s;
	
	while (n > 1 && change(s)) {
		//show(s);
		n = len(s);
	}
	
	
	show(s);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
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
