
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
typedef map<int,int>  :: iterator mit;
typedef set<int> :: iterator sit;
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
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(i, 0, n) {showv(vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;

void solve () {
	int ans = 0;
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	
	int sz = r - l + 1;
	if (s < sz * (sz+1) / 2) {
		show(-1);
		return;
	}
	vint v;
	seti st;
	seti :: iterator it;
	
	int sum = 0;
	rep(i,1, 501) {
		if (len(st) > 0) break;
		if (i <= sz) {
			sum += i; 
			continue;
		}
		
		if (sum == s) {
			rep (num, i-sz, i) {
				st.insert(num);
			}
			break;
		}
		sum += i;
		sum -= (i-sz);
		
		int c = 0;
		while (sum > s) {
			sum += i-sz + c;
			c++;
			sum -= i-sz + c;
			if (sum == s) {
				rep (num, i-sz, i+1) {
					if (num != i-sz + c)
						st.insert(num);
				}
				break;
			}
		}
	}
	
	int ad = 0;
	rep (i, 1, n+1) {
		if (notin(st, i))
		v.pb(i);
	}
	
	it = st.begin();
	rep (i, 1, l+1) {
		cout << v[i-1] << " ";
	}
	each(it, st) {
		cout << *it << " ";
	}
	rep (i, l+1, r+1) {
		cout << v[i-1] << " ";
	}
	
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
//$ sudo g++ -o name name.cpp
//$ ./name

