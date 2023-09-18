#include <bits/stdc++.h>
using namespace std;
// My Favorite Macros
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
#define por(i, a, b, in) for (ll i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

ll p = 998244353;
vll f;

void init() {
	ll N = 1e5 + 2;
    f.assign(N, 0);
    f[0] = f[1] = 1;
    for (ll i=2;i<N;i++) f[i] = (i * f[i-1]) % p;
}

ll exp(ll a, ll b) {
    if (b == 0) return 1;
    if (b ==  1) return a;
    ll half = exp(a, b/2) % p;
    ll ans = (half * half) % p;
    if (b % 2) {
    	ans *= a;
    	ans %= p;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    return ((f[n] * exp(f[r], p-2)) % p * exp(f[n-r], p-2)) % p;
}

void solve (void) {
	ll ans = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep (i, 0, n) cin >> v[i];


	ll cnt = 0;
	ll cnt3 = 0;
	por (i, 0, n, 3) {
		sort(v.begin() + i, v.begin() + i + 3);
		if (v[i] == v[i+2]) cnt3++;
		else if (v[i+1] == v[i]) cnt++;
	}
	//showv(v)

	ans = nCr(n/3, n/6);
	//if (cnt) ans = exp(ans, cnt + 1);

	ll k = ans;
	while (cnt > 0) {
		ans = (ans * 2) % p;
		cnt--;
	}
	while (cnt3 > 0) {
		ans = (ans * 3) % p;
		cnt3--;
	}


	show(ans);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	solve();
	
	return 0;
}

// Lorenzo Fiorini

/*
2 blue 1 red
1 blue 2 red
	3 3 6 3

N = 4
36 = 2*2 * 3*3
4 choose 2 = 6
0011



N = 2
2 choose 1 = 6

6
3 2 1 3 3 3
RBB RRB
	RBR
	BRR
BRR BBR
	BRB
	RBB

RRB 

WTF??
don't even know why it works now
lol
lmao
*/
