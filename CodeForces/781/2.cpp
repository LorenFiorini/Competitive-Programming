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
	int ans = 1;
	int n;
	cin >> n;
	mpii mp;
	//mp[0] = 1;
	
	rep(i,0,n-1) {
		int num;
		cin >> num;
		mp[num]++;
	}
	
	
	vint v;
	each(it, mp) {
		v.pb(it->ss);
	}
	sort(allg(v));
	int sz = len(v);
	int odd = 0;
	
	if (v[0] == 1) {
		ans = n;
	} else {
		//at least one is >= 2
		//if (v[0]) 
		//showp("sz",sz);
		rep(i, 0, sz) {
			if (v[i] % 2 == 0) {
				ans += v[i] / 2;
			} else if (v[i] == 1) {
				//show("-");
				int num = sz - i;
				//showp(i, num);
				ans += num;
				odd -= num;
				
				//showp(i+100, ans);
				if (odd > 0) {
					ans += odd / 2;
					if (odd % 2) odd = 1;
				} else{
				odd = 0;	
				}
				
				break;
			} else {
				ans += v[i] / 2;
				odd++;
			}
			
			//showp(i, ans);
		}
		//show(ans);
	}
	//showp(ans, odd);
	ans += odd;
	show(ans);
	///show("---");
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
