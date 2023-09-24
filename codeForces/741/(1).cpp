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
#define showp(x, y) cout << x << "\n" << y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(vv, n, m) rep(r, 0, n) {showv(vv[r], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
#define precision(d) cout << setprecision(d) << fixed;
#define ff first
#define ss second

seti hola(){
	vector<int> pr;
	int mx = 33000;
	int lp[mx];
	rep (i,2,mx) {
		if (lp[i] == 0) {
			pr.pb(i);
			lp[i] = i;
		}
		for (int j = 0; j < len(pr) && pr[j] <= lp[i] && i*pr[j] < mx; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
	seti pri(all(pr));
	return pri;
}
bool not_holas(int num, seti &pri) {
	if (pri.find(num) == pri.end()) return true;
	return false;
}
int bfs(vpii &v, int n, seti &pri) {
	queue<pii> q;
	for (pii p : v) q.push(p);
	
	while (!q.empty()) {
		pii num = q.front();
		q.pop();
		if (not_holas(num.ff, pri)) {
			return num.ff;
		}
		rep (i, 0, n) {
			if (num.ss >= v[i].ss) continue;
			pii tmp = num;
			tmp.ff *= 10;
			tmp.ff += v[i].ff;
			tmp.ss = v[i].ss;
			q.push(tmp);
		}
		
	}
	return -1;
}
void solve (seti &pri) {
	int k;
	cin >> k;
	string s;
	cin >> s;
	vpii v(k);
	rep (i,0,k) {
		v[i].ff = s[i] - '0';
		v[i].ss = i;
	}
	
	
	//sort(all(v));
	
	int ans = bfs(v, k, pri);
	int a = len(to_string(ans));
	showp(a , ans);
}
int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	seti pr = hola();
	int t; cin >> t; while (t--)	solve(pr);
	return 0;
}

// Lorenzo Fiorini
