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
typedef map<int,int> mpii;
typedef set<ll> seti;
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


void solve () {
	bool ans = 0;
	ll zero = 0;
	ll n;
	cin >> n;
	vll v(n);
	rep(i,0,n) {
		cin >> v[i];
		if (v[i] == 0) zero++;
	}


	if (n - zero < 2) {
		show("YES");
		return;
	} else if (n - zero == 2) {
		// 2 elements different from 0
		seti st(all(v));
		ll N = len(st);
		if (N == 3) {
			vint vec(all(st));
			if ((vec[1] == 0) && (vec[0]+vec[2] == 0)) {
				show("YES");
			return;
			}
		} 
	} 

	seti st(all(v));
	sort(all(v));
	ll sum = 0, suma = 0;
	rep(i,0,3) sum += v[i];
	rep(i,0,3) suma += v[n-1-i];
	if (st.find(sum) == st.end() || st.find(suma) == st.end()) {
		show("NO");
		return;
	}

	rep(i, 0, n) {
		rep(j, i+1, n) {
			rep(k, j+1, n) {
				sum = v[i]+v[j]+v[k];
				if (st.find(sum) == st.end()) {
					show("NO");
					return;
				}
			}
		}
	}

	show("YES");
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
