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


void solve () {
	int n, l;
	cin >> n >> l;
	//distance to direction
	map<int, vint> mp;
	// position to id
	mpii mpi;
	
	rep(i,0,n) {
		int p, d;
		cin >> p >> d;		
		int dis;
		//IDs
		if (d) {
			dis = l-p;
		} else {
			dis = p;
		}
		mpi[p] = i+1;
		mp[dis].pb(d);		
	}
	deque<int> dq;
	each(it, mpi) {
		dq.pb(it->ss);
	}
	
	each(it, mp) {
		vint order;
		for (int d: it->ss) {
			if (d) {
				order.pb(dq.back());
				dq.pop_back();
			} else {
				order.pb(dq.front());	
				dq.pop_front();
			}
		}
		sort(all(order));
		for (int ans: order) {
			cout << ans << " ";
		}
	}
	
	show("");
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
