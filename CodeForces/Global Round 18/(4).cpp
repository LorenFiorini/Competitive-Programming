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

int n;
string a;
string b;
set<vvi> st;

bool only_zero() {
	bool ans = true;
	rep (i,0,n) ans &= (a[i] == '0');
	if (ans) return ans;
	ans = true;
	rep (i,0,n) ans &= (b[i] == '0');
	return ans;
}

vvi next(vvi &v, bool col) {
	vvi tmp(2, vint(2));
	tmp[0][0] = v[1][1];
	tmp[1][1] = v[0][0];
	tmp[0][1] = v[1][0];
	tmp[1][0] = v[0][1];
	
	if (col) {
		tmp[0][1]++;
		tmp[1][0]--;
	} else {
		tmp[0][0]++;
		tmp[1][1]--;
	}
	return tmp;
}


int dfs(vvi &v) {	
	int ans = 1e9;
	// Even
	vvi ve = next(v, 1);
	if (ve[0][1] + ve[1][1] == 0 || ve[0][0] + ve[1][0] == 0) {
		return 1;
	} else if (min(min(ve[0][0], ve[1][0]),min(ve[1][1], ve[0][1])) >= 0 && st.find(ve) == st.end()) {
		st.insert(ve);
		ans = min(ans, dfs(ve));
	} 
	
	// Odd
	vvi vo = next(v, 0);
	if (vo[0][1] + vo[1][1] == 0 || vo[0][0] + vo[1][0] == 0) {
		return 1;
	} else if (min(min(vo[0][0], vo[1][0]),min(vo[1][1], vo[0][1])) >= 0 && st.find(vo) == st.end()) {
		st.insert(vo);
		ans = min(ans, dfs(vo));
	} 
	return ans + 1;
}

void solve () {
	int ans = 0;
	cin >> n;	
	cin >> a;
	cin >> b;
	// zero steps
	/*
	if (a == b) {
		show(ans);
		return;
	} else if (only_zero()) {
		show(-1);
		return;
	}*/
	
	
	vvi v(2, vint(2, 0));
	rep (i,0,n) {
		if (a[i] != b[i]) {
			if (a[i] == '1') v[0][0]++;
			else v[1][0]++;
		} else {
			if (a[i] == '1') v[0][1]++;
			else v[1][1]++;
		}
	}
	st.insert(v);
	ans = dfs(v);
	if (ans >= 1e9) ans = -1;
	
	show(ans);
	//show("");
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
