#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vint> vvi;
typedef map<ll ,ll> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
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
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

void check(mpii &st, mpii::iterator low) {
	if (low->ss < low->ff) st.erase(low);
}

void solve () {
	ll n, m;
	cin >> n >> m;
	mpii st;
	mpii::iterator low;
	rep (i, 0, n)  {
		ll le, ri;
		cin >> le >> ri;
		st[le] = ri;
	}
	
	rep (i, 0, m) {
		ll stu, ans;
		cin >> stu;
		low = st.lower_bound(stu);
		
		if (low == st.end()) {
			low--;
			ans = low->ss;
			low->ss--;
			check(st, low);
		} else if (low == st.begin()) {
			ans = low->ff;
			pii pa = mk(ans+1, low->ss);
			st.erase(ans);
			st.insert(pa);
					low = st.find(ans+1);
				check(st, low);
		} else {
			if (low->ff == stu) {
				ans = stu;
				pii pa = mk(ans+1, low->ss);
				st.erase(ans);
				st.insert(pa);
				low = st.find(ans+1);
				check(st, low);
			} else {
				ll pr, nx;
				nx = low->ff; low--;
				pr = low->ss;
				if (abs(stu - pr) <= abs(nx - stu)) {
					ans = low->ss;
					low->ss--;
					check(st, low);
				} else {
					low++;
					ans = low->ff;
					pii pa = mk(ans+1, low->ss);
					st.erase(ans);
					st.insert(pa);
					low = st.find(ans+1);
					check(st, low);
				}
			}
		}
		
		
		cout << ans << " ";
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
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
