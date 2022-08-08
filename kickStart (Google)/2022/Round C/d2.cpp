#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define mod 1000000007
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

ll n;
ll sum;

ll gcd(ll a, ll b) {
	//cout << ";" << endl;
	if (!b) return a;
	return gcd(b, a%b);
}

bool palindrome(string s, vint &v) {
	int l = 0;
	int r = n-1;
	while (l < r && v[l]) l++;
	while (l < r && v[r]) r--;
	
	while (l < r && s[l] == s[r]) {
		l++; r--;
		while (l < r && v[l]) l++;
		while (l < r && v[r]) r--;
	}
	return l >= r;
}

void dfs(string s, vint &v, int pos, ll cnt) {
	if (cnt == n) {sum++; return;}
	v[pos] = 1;
	sum += palindrome(s,v) * (n - cnt);
	
	
	rep(i,0,n) {
		if (!v[i]) {
			dfs(s, v, i, cnt+1);
		}
	}
	v[pos] = 0;	
}

ll xGCD(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    ll x1, y1;
    ll G = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return G;
}

void solve () {
	ll ans = 0;
	sum = 0;
	cin >> n;
	string s;
	cin >> s;
	
	vint v(n,0);
	rep(i,0,n) {
		dfs(s, v, i, 1);
	}
	
	// width of tree = N^2 - 2
	ll p = sum, q = (1 << n) - 2;
	ll gre = gcd(p, q);
	p /= gre; q /= gre;
	
	ll V, W;
	ll G = xGCD(mod, p, W,V);
	
	
	ans = (V*q);
	if (ans >= mod) ans %= mod;
	while (ans < 0) {
		ans += mod;
	}	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	int CASE = 1;
	while (CASE <= T) {
		cout << "Case #" << CASE << ": ";
		solve();
		CASE++;
	}
	
	return 0;
}

// Lorenzo
