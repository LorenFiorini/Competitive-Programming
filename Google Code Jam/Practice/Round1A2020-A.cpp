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
#define showv(v, n) rep(i, 0, n) {cout << v[i] << "\n";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
//cout << setprecision(d) << fixed;

list<string>:: iterator it; 

bool begin(string &beg, string &s) {
	int n = len(beg);
	int m = len(s);
	if (0 == n) {
		beg = s;
		return 1;
	}
	rep (i, 0, min(n, m)) {
		if (s[i] != beg[i]) {
			show("*");
			return 0;
		}
	}
	if (m > n) beg = s;
	return 1;
}


bool endd(string &end, string &s) {
	int n = len(end);
	int m = len(s);
	if (n == 0) {
		end = s;
		return 1;
	}
	rep (i, 0, min(n, m)) {
		if (s[m-1 - i] != end[n-1 - i]) {
			show("*");
			return 0;
		}
	}
	if (m > n) end = s;
	return 1;
}
/*
void middle (list<string> &mid, string &s, string &before) {
	it = mid.begin();
	while (it != mid.end() || *it != before) it++;
	mid.insert(it, s);
}*/

void solve () {
	int n;
	cin >> n;
	vstr v(n);
	rep (i, 0, n) cin >> v[i];
	
	string beg = "";
	string en = "";
	//list<string> mid;
	vstr mid;
	
	rep (i, 0, n) 
	{
		int m = len(v[i]);
		int st = 0;
		//string before = "";
		rep (j, 0, m) {
			if ( !st && v[i][j] == '*') {
				string s = v[i].substr(0, j);
				if (!begin(beg, s)) return;
				st = j + 1;
			} else if (v[i][j] == '*'){
				string s = v[i].substr(st, j);
				//middle(mid, s, before);
				//before = s;
				mid.push_back(s);
				st = j + 1;
			}
		}
		string s = v[i].substr(st, m - st);
		if (!endd(en, s)) return;
		
	}

	cout << beg;
	//for (it = mid.begin(); it != mid.end(); it++) {	cout << *it;}
	cout << en << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int c = 1;
	while (c <= t) {
		cout << "Case #" << c << ": ";
		solve();
		c++;
	}
	
	return 0;
}

