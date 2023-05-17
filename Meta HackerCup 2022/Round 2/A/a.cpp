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
string s;

bool diff(int l, int r, vvi &v) {
	int mid = (l + r) / 2;
	int d = 0;
	vint vec(26);
	rep(j, 0, 26) {
		vec[j] = v[r][j];
		vec[j] -= v[mid][j];
		vec[j] -= v[mid-1][j];
		vec[j] += v[l-1][j];
		d += abs(vec[j]);
	}

	//cout << endl;
	//showv(vec, 26);

	if (d == 2) {
		rep(j, 0, 26) {
			if (vec[j] != 0) {
				if ((s[mid-1] - 'a') == j) {
					//show(s[mid-1]);
					return 1;
				}
			}
		}
	}
	return d == 0;
}

void solve () {
	int ans = 0;
	cin >> s;
	n = len(s);
	vvi v(n+1, vint(26, 0));

	rep (i, 1, n+1) {
		v[i] = v[i-1];
		v[i][s[i-1] - 'a']++;
	}


	int q, l ,r;
	cin >> q;
	while (q--) {
		cin >> l >> r;

		if ((r - l + 1) % 2) {
			ans += diff(l, r, v);
		}
	}
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; 
	cin >> T; 
	for (int C = 1; C <= T; C++) {
		cout << "Case #" << C << ": ";
		//cout << endl;
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
