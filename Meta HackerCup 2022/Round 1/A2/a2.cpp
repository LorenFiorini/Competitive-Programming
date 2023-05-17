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
typedef map<ll, ll> mpii;
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
#define showv(v, n) rep(i, 0, n) {cout << v[i];} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

ll n, k;
bool input(vint &a, vint &b) {
	mpii mp;
	rep (i, 0, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	rep (i, 0, n) {
		cin >> b[i];
		mp[b[i]]--;
	}
	each(it, mp) {
		if ((it->ss) != 0) return false;
	}
	return true;
}

bool shifted(vint &a, vint &b, ll &shift_a, ll &shift_b) {
	ll j;
	rep (i, 0, n) {
		j = 0;
		while (j < n && a[(i+j) % n] == b[j]) j++;

		if (j == n){
			if (shift_a == -1) {
				shift_a = i;
			} else {
				shift_b = i;
				return 1;
			}
		}
	}
	return (shift_a != -1);
}

void solve () {
	ll shift_a = -1, shift_b = -1;
	cin >> n >> k;
	vint a(n); vint b(n);


	if (!input(a, b) || !shifted(a, b, shift_a, shift_b)) {
		show("NO");
		return;
	}


	if ( 
		(n == 2 && (shift_a == (k%2) || (shift_b >= 0)) ) ||
		(n > 2 && (k != 1 && shift_a == 0)) ||
		(n > 2 && (k == 1 && shift_b > 0)) ||
		(n > 2 && shift_a > 0 && k > 0)
		) {
		show("YES");
	} else {
		show("NO");
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; 
	cin >> T; 
	for (int C = 1; C <= T; C++) {
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
