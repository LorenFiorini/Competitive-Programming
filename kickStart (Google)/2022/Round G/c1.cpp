#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vint;
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
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
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


void solve () {
	ll ans = 0;
	ll n;
	cin >> n;
	vint v(n);
	rep (i, 0, n) {
		cin >> v[i];
		ans += v[i] * n;
	}

	ll le = 0, ri = 0;
	vvi left(n, vint(2, 0));
	rep (i, 0, n) {
		if (v[i] < 0) {
			ll sum = v[i];
			left[i][0] = v[i];
			left[i][1] = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (v[j] < 0) {
					left[i][0] += sum * left[j][1];
					left[i][1] += left[j][1];
					break;
				}

				sum += v[j];
				if (sum < 0) {
					left[i][0] += sum;
					left[i][1]++;
				} else {
					break;
				}
			}
			le += left[i][0];
		}
	}

	vvi right(n, vint(2, 0));
	for (int i = n-1; i >= 0; i--) {
		if (v[i] < 0) {
			ll sum = v[i];
			for (int j = i + 1; j < n; j++) {
				if (v[j] < 0) {
					break;
				} else {
					sum += v[j];
				}

				if (sum < 0) {
					//right[i][0] += sum;
					//right[i][1]++;
					ri += sum;
				} else {
					break;
				}
			}
			//ri += right[i][0];
		}
	}
	
	show(ans);
	showp(le, ri);
	showvv(left, n, 2);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T; 
	rep(C, 1, T+1) {
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
