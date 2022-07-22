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
  1 2 3 4
	1 	2 	3 	4
	x   1   y   z

	0 	2 	0 	1
x = 2,3,4
c = 1
y = 4
z = 3,4
	2 < z <= 4
	num/2 < z <= num

if 0 then i < Xi
if 1 then 	i/2 < Xi <= i

if 2 then 	i/(2*v[i]) < Xi <= i/v[i]
if 2 then 2*i <= Xi < 3*i

	[ i / v[i] ] upper bound (inclusive)
[1/0] = in -> greater than 1
[2/2] = 1  -> upper bound
[3/0] = in -> greater than 3
[4/1] = 4  -> upper bound

	[ i / (v[i]+1) ] lower bound
[1/x] = 0 -> 1.1 is LB
[2/x] = 2 -> 0.67 = (2 / (2+1))
[3/x] = 0 -> 3.1
[4/x] = 1 -> (4 / (1+1)) = 2.1

*/

void solve () {
	int ans = 0;
	int n, num, den;
	cin >> n;
	vint v(n);
	vint a(n);
	rep(i, 0, n) cin >> v[i];
	
	// id -> [l, r]
	rep(i, 0, n) {
		num = i + 1;
		if (v[i] == 0) {
			// any number larger than NUM

		} else if (v[i] == 1) {
			// any number smaller than or equal to NUM
			// but larger than 2*NUM
			// 

		} else {

		}
	}


	show(ans);
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
