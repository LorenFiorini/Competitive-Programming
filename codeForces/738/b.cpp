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

int n;

int score(vint v) {
	int ans = 0;
	rep (i, 1, 0) {
		if (v[i] == v[i-1]) {
			ans++;
			i++;
		}
	}
	return ans;
}

void help(vint &W) {
	vint v(all(W));
	rep (i, 1, n) {
		if (!v[i]) {
			if (v[i-1] == 1) 
				v[i] = 2;
			else if (v[i-1] == 2) 
				v[i] = 1;
		}
	}
	for (int i = n - 2; i >= 0; i--){
		if (!v[i]) {
			if (v[i+1] == 1) 
				v[i] = 2;
			else if (v[i+1] == 2) 
				v[i] = 1;
		}
	}
	
	vint vv(all(W));
	for (int i = n - 2; i >= 0; i--){
		if (!vv[i]) {
			if (vv[i+1] == 1) 
				vv[i] = 2;
			else if (vv[i+1] == 2) 
				vv[i] = 1;
		}
	}
	rep (i, 1, n) {
		if (!vv[i]) {
			if (vv[i-1] == 1) 
				vv[i] = 2;
			else if (vv[i-1] == 2) 
				vv[i] = 1;
		}
	}
	
	
	if (score(v) < score(vv)) {
		W.swap(v);
	} else {
		W.swap(v);
	}
}




void solve () {
	cin >> n;
	string s;
	cin >> s;
	vint v(n, 0);
	rep (i, 0, n) {
		if (s[i] == 'B') v[i] = 1;
		if (s[i] == 'R') v[i] = 2;
	}
	//ESPECIAL CASE
	int tmp = accumulate(all(v), 0);
	if (tmp == 0) {
		rep (i, 0, n) {
			if (i%2)cout << "B";
			else cout << "R";
		}
		cout << "\n";
		return;
	}
	
	help(v);
	
	rep (i, 0, n) {
		switch (v[i]) {
		case 1:
			cout << "B";
			break;
		case 2:
			cout << "R";
			break;
		}
	}
	cout << "\n";
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
