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
/*
0001
0010
0011
0100
0101
0110
0111

0100
*/
void bin(int n) {
	vector<bool> v;
	while (n > 0) {
		v.pb(n & 1);
		n >>= 1;
	}
	reverse(all(v));
	for (auto a: v) cout << a;
	cout<< endl;
}

void solve () {
	int n;
	cin >> n;
	if (n == 3) {show(-1); return;}
	vint v(n);
	/*
	int a = 1, b = n;
	rep(i,0,n) {
		if (i % 2) {
			v[i] = a++;
		} else {
			v[i] = b--;
		}
	}*/

	rep(i,0,n) v[i] = n-i;

	rep(i,2,n) {
		if ((v[i-2] ^ v[i-1]) == v[i]) {
			bin(n);
			return;
		}
	}
	show("ok");
	//showv(v, n);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
