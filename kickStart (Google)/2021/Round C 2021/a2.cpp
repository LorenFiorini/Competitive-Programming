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
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;


void solve () {
	ll ans = 0;
	// INPUT
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vll v(n);
	rep (i, 0, n) {
		v[i] = s[i] - '`';
	}
	
	if (n == 1) {
		show(v[0] - 1);
		return;
	} else if (n == 1){
		show(min(v[0], v[1]));
		return;
	}
	
	bool ok = false;
	bool impar = false;
	rep (i, 0, n/2) {
		if (v[i] < v[n-1-i]) {
			ok = true;
		}
	}
	
	//POSSIBILITIES
	ll pos = 1;
	ll m = n / 2;
	if (n&1) {
		impar = true;
		m++;
	}
	rep (i, 0, m) {
		if (i == m-1) {
			ans = pos;
			ll tmp = v[i] - 1;
			if (impar && ok) {
				//tmp = max(v[i], k);
				pos *= v[i];
				ans = pos % MOD;
			} else if (impar && !ok) {
				pos *= (v[i] - 1);
				/*tmp = 1;
				rep (j, n/2+1, n) {
					tmp *= v[j];
				}*/
				pos%= MOD;
				ans = pos;
			} else if (!impar && ok) {
				ans *= v[i];
			} else if (!impar && !ok) {
				ans *= (v[i] - 1);
			}
			//show (tmp);
			pos *= tmp;
		}else {
			pos *= v[i];
		}
		pos %= MOD;
		//show (pos);
	}
	
	
	
	ans %= MOD;
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	int C = 1;
	while (C <= T) {
		cout << "Case #" << C << ": ";
		solve();
		C++;
	}
	
	return 0;
}