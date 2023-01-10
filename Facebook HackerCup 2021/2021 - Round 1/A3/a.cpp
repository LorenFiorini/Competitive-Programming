#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
//#define mod (ll) 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
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
//
ifstream input("valid-input.txt");
ofstream output("valid-OUTPUT.txt");

ll mod = 1000000007;
ll n;

vvi help() {
	input >> n;
	string s;
	input >> s;
	
	// FOX - condensation vector
	vvi v;
	rep (i, 0, n) {
		char st = s[i];
		int lst = i;
		rep (j, i+1, n) {
			if (st == s[j]) {
				lst = j; //last position of the same X or O
			} else if (s[j] != 'F') {
				break;
			}
		}
		vint tmp(2, s[i]);
		tmp[1] = lst - i + 1;
		v.pb(tmp);
		i = lst;
	}
	return v;
}

vpii hey(vvi &v) {
	vpii vec;
	// [char, len] 	
	rep (i, 0, len(v)) {		
		if (v[i][0] != 'F') {
			int a = v[i][1];
			if (i > 0 && v[i-1][0] == 'F') a += v[i-1][1];
			int b = v[i][1];
			if (i+1 < len(v) && v[i+1][0] == 'F') b += v[i+1][1];
			
			vec.pb({a, b});
		}
	}
	return vec;
}

void solve (){
	ll ans = 0;
	vvi vec = help();
	vpii v = hey(vec);
	
	// Smaller sums
	ll N = len(v);
	vll B(N);
	vll BJ(N);
	for (ll i = N-1; i >= 0; i--){
		B[i] = v[i].ss;
		if (i+1 < N) B[i] += B[i+1];
		
		BJ[i] = v[i].ss * i;
		if (i+1 < N) BJ[i] += BJ[i+1];
	}
	
	// Final sum
	rep (i, 0, N-1) {
		ll tmp = BJ[i+1];
		tmp -= ((ll)i) * B[i+1];
		
		
		ans += (v[i].ff * tmp) % mod;
		ans %= mod;
	}
	
	output << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T, CASE = 0;
	input >> T;
	while (CASE++ < T) {
		output << "Case #" << CASE << ": ";
		solve();
	}
	output.close();
	return 0;
}


// Lorenzo Fiorini
