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
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
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

ll N = 1000100;
vector<ll> v(N, 0);

void help() {
	ll cnt = 1;
	ll i = 1;

	ll num = 1;
	while (num < N) {
		v[num] += (num * num);
		ll pre = (i-1) *2;
		if (pre > 0 && num != pre && num != (pre-i))
			v[num] -= v[pre];

		if (num + i < N) {
			v[num+i] += v[num];
		}

		if (num+i+1LL < N) {
			v[num+i+1LL] += v[num];
		}

		if (num == cnt) {
			cnt += i;
			i++;
		} 
		num++;
	}
	//showv(v);
}

void solve (void) {
	ll n;
	cin >> n;

	show(v[n]);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	help();
	int t; cin >> t; while (t--)
	
	solve();

	return 0;
}

// Lorenzo Fiorini
