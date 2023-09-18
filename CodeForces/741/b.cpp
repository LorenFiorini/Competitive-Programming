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



seti sieve(){
	vector<int> pr;
	int mx = 33000;
	int lp[mx];
	rep (i,2,mx) {
		if (lp[i] == 0) {
			pr.pb(i);
			lp[i] = i;
		}
		for (int j = 0; j < len(pr) && pr[j] <= lp[i] && i*pr[j] < mx; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
	seti pri(all(pr));
	return pri;
}

bool not_prime(int num, seti &pri) {
	if (pri.find(num) == pri.end()) return true;
	return false;
}

void solve (seti &pri) {
	int k;
	cin >> k;
	string s;
	cin >> s;
	vector<int> v(k);
	rep (i,0,k) v[i] = s[i] - '0';
	
	// one digit
	int d = 1;
	rep (i, 0, k) {
		// pick first
		int num = v[i];
		rep (left, i+1, k) {
			
			rep (j, i+1, min(k, i+d)) {
				num *= 10;
				num += v[j];
			}
			
			if (not_prime(num, pri)) {
				show(d);
				show(num);
				return;
			}
		}
		
		d++;
		if (d > 9) break;
	}
	
	show(k);
	show(s);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	seti pr = sieve();
	int t; cin >> t; while (t--)
	
	solve(pr);
	
	return 0;
}

// Lorenzo Fiorini
