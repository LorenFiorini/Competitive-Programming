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
int length(ll x) {
	string s = to_string(x);
	return len(s);
}
vll get(ll num) {
	vll ans;
	while (num > 0) {
		if (num % 10 > 1) {
			ans.pb(num % 10);
		}
		num /= 10;
	}
	sort(allg(ans));
	return ans;
}
void solve () {
	ll ans = 0;
	ll x, n;
	cin >> n >> x;
	ll leg = length(x);
	// when done
	if (leg == n) {	show(0);return;	}
	else if (x == 1 || n < leg) {	show(-1);return;}
	
	queue<ll> q;
	q.push(x);
	while (!q.empty()) {
		set<ll> st;
		while (!q.empty()) {
			ll num = q.front();
			q.pop();			
			vll v = get(num);
			
			for (ll dig : v) {
				ll tmp = dig * num;
				leg = length(num);
				if (leg == n) {
					show(ans);
					return;
				} else if (leg < n) {
					st.insert(tmp);
				}
			}
		}
		for (auto it = st.rbegin(); it != st.rend(); it++){
			q.push(*it);
		}
		ans++;
	}
	
	show(-1);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
