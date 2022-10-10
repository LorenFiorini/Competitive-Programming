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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve () {
	ll a, b, k;
	cin >> a >> b;
	ll ans = b - a;

	if (a >= b) {
		ans = a - b;
	} else if (b % a == 0) {
		ans = 0;
	} else {
		/*
		ll dif = b - a;
		ll rem = 0;
		ll i = 0;
		while (i < ans) {
			rem = (b % (a+i));
			if (rem == 0) {
				ans = i;
				break;
			} 

			k = b / (a + i) + 1;
			dif = (a+i) * k - b;
			
			if (dif + i <= ans) {
				ans = dif + i;
			} 
			D = min(D, dif);

			//cout << i << ": "; showp(dif, rem);

			i++;
		}*/
		ll val;
		rep (i,0,1000) {
			val = 2 * i + a - (b % (a+i));
			if (val < ans) {
				ans = val;
				cout << "-> ";
			}
			showp(i, val);
		}

	}
	
	show(ans);
	show("-");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
