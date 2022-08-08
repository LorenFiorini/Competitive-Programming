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

vector<set<char>> vec(4);

void help() {
	set<char> dig;
	set<char> up;
	set<char> low;
	set<char> spe;
	rep(i,0,10) dig.insert(i + '0');
	rep(i,0,26) low.insert(i + 'a');
	rep(i,0,26) up.insert(i + 'A');
	spe.insert('#');	spe.insert('@');	spe.insert('*');	spe.insert('&');
	vec[0] = dig;	vec[1] = low;	vec[2] = up;	vec[3] = spe;
}

void solve () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ok[4] = {0,0,0,0};
	
	for (char c : s) {		
		rep(i,0,4) {
			ok[i] |= (vec[i].find(c) != vec[i].end());
		}
	}
	if (!ok[0]) s.pb('0');
	if (!ok[1]) s.pb('a');
	if (!ok[2]) s.pb('A');
	if (!ok[3]) s.pb('@');
	
	n = len(s);
	while (n < 7) {
		s.pb('a');
		n++;
	}
	show(s);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();
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
