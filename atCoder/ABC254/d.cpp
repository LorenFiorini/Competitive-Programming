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


vint sieve(int n) {
	vint pr;
	vint lp(n+1);
	rep(i,2,n+1) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < (len(pr)) && pr[j] <= lp[i] && i*pr[j] <= n; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
	return pr;
}

void solve () {
	int n;
	cin >> n;
	ll ans = n;
	
	vint pr = sieve(n);
	int N = len(pr);
	
	
	vint cnt(N);
	rep(i, 1, n+1) {
		int num = i;
		rep(j,0,N) {
			if (num == 1) break;
			while (num % pr[j] == 0) {
				num /= pr[j];
				cnt[j]++;
			}
		}
	}
	showv(cnt, N);
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
