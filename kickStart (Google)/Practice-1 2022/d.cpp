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

bool inside(int r, int c) {
	if (min(r,c) < 0 || max(r, c) >= n) return false;
	return true;
}

int count(vstr &v) {
	map<char, int> mp;
	for (string s : v) {
		for (char c : s) mp[c]++;
	}
	return abs(mp['B'] - mp['R']);
} 

int checkBlue(vstr &v) {
	// <Row, Column>
	int start = 0, emd = 0;
	queue<pair<int, int>> q;
	vector<vector<bool>> vis(n, vector<bool> (n, 0));
	rep(i, 0, n) {
		if (v[i][0] == 'B') {
			q.push({i, 0});
			vis[i][0] = true;
			start++;
		}
	}
	
	while (!q.empty()) {
		pii p = q.front();
		if (p.ss +1 == n) emd++;
		q.pop();
		
		rep(i, 0, 3) {
			rep(j, 0, 3) {
				if (i+j == 0 || i+j == 4) continue;
				int r = p.first + i - 1;
				int c = p.ss + j - 1;
				if (inside(r, c) && (not vis[r][c]) && v[r][c] == 'B') {
					vis[r][c] = true;
					q.push({r, c});
				}
			}
		}
	}
	//showp(start, emd);
	return min(emd, start);
}
int checkRed(vstr &v) {
	// <Row, Column>
	int start = 0, emd = 0;
	queue<pair<int, int>> q;
	vector<vector<bool>> vis(n, vector<bool> (n, 0));
	rep(j, 0, n) {
		if (v[0][j] == 'R') {
			q.push({0, j});
			vis[0][j] = true;
			start++;
		}
	}
	
	while (!q.empty()) {
		pii p = q.front();
		if (p.ff +1 == n) emd++;
		q.pop();
		
		rep(i, 0, 3) {
			rep(j, 0, 3) {
				if (i+j == 0 || i+j == 4) continue;
				int r = p.first + i - 1;
				int c = p.ss + j - 1;
				if (inside(r, c) && (not vis[r][c]) && v[r][c] == 'R') {
					vis[r][c] = true;
					q.push({r, c});
				}
			}
		}
	}
	return min(emd, start);
}

void solve () {
	// R -> red
	// B -> blue
	// . -> empty
	cin >> n;
	vstr v(n);
	rep(i,0,n) cin >> v[i];
	
	// Count B and R |B-R| <= 1
	if (count(v) > 1) {
		show("Impossible");
		return;
	}
	
	int B = checkBlue(v);
	int R = checkRed(v);
	//showp(B, R);
	if (max(B,R) > 1 || (B == 1 && R == 1)) {
		show("Impossible");
	} else if (B == 1) {
		show("Blue wins");
	} else if (R == 1) {
		show("Red wins");
	} else {
		show("Nobody wins");
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; 
	cin >> t; 
	for (int C = 1; C <= t; C++){
		cout << "Case #" << C << ": ";
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
