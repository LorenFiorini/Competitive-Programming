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

int n, cnt, m;
vint pr;
void sieve() {
	int N = 32000;
	vint lp(N+1, 0);
	rep (i, 2, N+1) {
		if (!lp[i]) {
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < len(pr) && pr[j]<=lp[i] && i*pr[j] <= N; j++) {
			lp[i * pr[j]] = pr[j];
		} 
	}
}

bool valid() {
	if (n == 1) return false;
	//int prime = 0;
	
	vint :: iterator low = upper_bound(all(pr), n);
	int start = low - pr.begin();
	
	//for (int i = 0; 2 * pr[i] <= n && i < m; i++) 
	rrep (i, start, 0)
	{
		if (n % pr[i] == 0 && n != pr[i]) {
			//show(pr[i]);
			
			//int num = n / pr[i];
			//n -= num;
			
			n -= pr[i];
			return true;
			
			//prime = pr[i];
		}
	}
	/*
	if (prime) {
		n -= prime;
		//showp(prime, n);
		return true;
	}*/
	return false;
}


void solve () {
	cin >> n;
	cnt = 0;
	while (valid()) cnt++;
	
	if (cnt % 2 == 1) {
		show("Alice");
	} else {
		show("Bob");
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	m = len(pr);
	//showv(pr, len(pr));
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
