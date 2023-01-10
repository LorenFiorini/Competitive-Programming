#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vint;
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
#define por(i, a, b, in) for (ll i=a ; i<(b) ; i+=in)
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

ll ans;
ll n, p;

void bfs(vvi &v) {
	
	set< vint > q;
	q.insert( {0, 0, 0} );
	
	while (!q.empty()) {
		auto it = q.begin();
		vint cur = *it;
		q.erase(it);
		
		ll row = cur[0], pre = cur[1], sum = cur[2];
		if (row == n) {
			ans = min(ans, sum);
			continue;
		}
		
		ll dile = pre - v[row][0];
		ll diri = v[row][p-1] - pre;
		if (pre <= v[row][0]) {
			q.insert( {row+1, v[row][p-1], sum + diri} );
		} else if (pre >= v[row][p-1]) {
			q.insert( {row+1, v[row][0], sum + dile} );
		} else {
			ll suma = sum + 2*dile + diri;
			q.insert( {row+1, v[row][p-1], suma} );
			
			ll sumb = sum + dile + 2*diri;
			q.insert( {row+1, v[row][0], sumb} );
		}	
		
	}
	
}

void solve () {
	ans = 1e18;
	cin >> n >> p;
	vvi v(n, vint(p));
	rep(i,0,n) {
		rep(j, 0, p) cin >> v[i][j];
		sort(all(v[i]));
	}
	//show("");
	bfs(v);
	
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
