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
	int ans = 0;
	int n;
	cin >> n;
	vint v(n);
	rep (i, 0, n) cin >> v[i];

	mpii mp;
	for (int num: v) mp[num]++;
	priority_queue<pair<int, int> > pq;
	priority_queue<pair<int, int> > tmp;
	for (auto p: mp) pq.push({p.second, p.first});

	int pre, nxt, id;
	bool ok = 1;
	while (pq.top().first > 1) {
		ok = 0;

		while (!ok && len(pq) > 0) {
			pii top = pq.top();
			rep (i, 1, n+1) {
				pre = (i-1) % n;
				nxt = (i+1) % n;
				id = i % n;
				if (v[pre] != v[nxt] && top.ss == v[id]) {
					v.erase(v.begin() + id);
					ok = 1;
					ans++;
					n--;
					pq.pop();
					pq.push({top.ff - 1, top.ss});
					break;
				}
			}
			if (!ok) {
				tmp.push(top);
				pq.pop();
			}
		}
		if (len(pq) > 0) {
			while  (!tmp.empty()) {
				pq.push(tmp.top());
				tmp.pop();
			}
		} else {
			ans += n / 2 + 1;
			while (!pq.empty()) pq.pop();
			break;
		}
	}

	ans += len(pq);
	
	show(ans);
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
