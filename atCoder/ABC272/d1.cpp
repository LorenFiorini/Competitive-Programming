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
	int n, m, row, col, num;
	cin >> n >> m;
	vvi v(n, vint(n, -1));

	mpii mp;
	while (ans * ans <= m) {
		mp[ans * ans] = ans;
		ans++;
	}

	// BFS
	v[0][0] = 0;
	queue<pii> q;
	q.push({0, 0});

	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		num = v[p.first][p.second];

		rep(i, 0, m) {
			if (2*i*i > m) break;

			int d = m - i*i;
			if (mp.find(d) != mp.end()) {
				int j = mp[d];

				// down right
				row = i + p.first;
				col = j + p.second;
				if (row < n && col < n && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}
				// down left
				col = p.second - j;
				if (row < n && col >= 0 && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}
				// up left
				row = p.first - i;
				if (row >= 0 && col >= 0 && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}
				// up right
				col = j + p.second;
				if (row >= 0 && col < n && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}

				// down right
				row = j + p.first;
				col = i + p.second;
				if (row < n && col < n && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}
				// down left
				col = p.second - i;
				if (row < n && col >= 0 && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}
				// up left
				row = p.first - j;
				if (row >= 0 && col >= 0 && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}
				// up right
				col = p.second + i;
				if (row >= 0 && col < n && v[row][col] == -1) {
					v[row][col] = num + 1;
					q.push({row, col});
				}

			}
		}
	}

	
	showvv(v, n ,n);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
