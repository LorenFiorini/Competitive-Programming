
#include <bits/stdc++.h>
using namespace std;

#define por(i, a, b, in) for (int i=a ; i<(b) ; i+=in)
#define rpor(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define rep(i, a, b) por(i, a, b, 1)
#define rrep(i, a, b) rpor(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) v.size()
#define notin(c, x) ((c).find(x) == (c).end())
//
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
//
#define show(x) cout << x << "\n";
#define showp(x, y) cout << x << " "<< y << "\n";
#define showv(v, n) rep(i, 0, n) {cout << v[i] << " ";} cout << "\n";
#define showvp(v, n) rep(i, 0, n) {showp(v[i].ff, v[i].ss);}
#define showvv(i, vv, n, m) rep(i, 0, n) {showv(j, vv[i], m);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";
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

int n, m;
queue<pii> ones;
queue<pii> nums;
set<pii> st;
set<pii> :: iterator it;

void around(vvi &v, int r, int c) {
	int ar[4] = {-1, 1, 0, 0};
	rep (i, 0, 4) {
		int row = r + ar[i];
		int col = c + ar[3 - i];
		if (row >= 0 && col >=0 && row < n && col < m && v[row][col] == -1)
			v[r][c]++;
	}
	return;
}

void f1(vvi &v, int r, int c) {
	int ar[4] = {-1, 1, 0, 0};
	pii p1;
	pii p2;
	int cnt = 0;
	rep (i, 0, 4) {
		int row = r + ar[i];
		int col = c + ar[3 - i];
		if (row >= 0 && col >= 0 && row < n && col < m && v[row][col] == -1)
		{
			if (cnt == 0) {
				p1 = mk(row, col);
				cnt++;
			} else if ( cnt == 1) {
				p2 = mk(row, col);
				cnt++;
			}
	}
	
	pii par = mk(r + ar[i], c + ar[3-i]);
		if (notin(st, it)) {
			st.insert(par);
			coor.ff += ar[i];
			coor.ss += ar[3 - i];
		}
	}
	
	v[r][c] -= 1;
	v[coor.ff][coor.ss] -= 1;
	if (v[coor.ff][coor.ss] == 1) ones.push(mk(coor.ff, coor.ss));
	return;
}



void solve () {
	int answer = 0;
	cin >> n >> m;
	vvi v(n, vint (m, -2));
	
	rep (i, 0, n) {
		string s;
		cin >> s; 
		rep (j, 0, m) {
			if (s[j] == 'G') v[i][j] = 0;
			if (s[j] == 'C') v[i][j] = -1;
		}
	}
	rep (i, 0, n) rep (j, 0, m) {
		if (v[i][j] == 0) {
			around(v, i, j);
			int tmp = v[i][j];
			switch (tmp){
				case 1: 
					v[i][j] = 0;
					break;
				case 2: 
					v[i][j] = 1;
					break;
				case 3: 
					v[i][j] = 3;
					break;
				case 4: 
					v[i][j] = 6;
					break;
			}
			pii par = mk(i, j);
			if (v[i][j] == 1) ones.push(par);
			else if (v[i][j] > 1) nums.push(par);
		}
	}
	while (!ones.empty()) {
		int i = ones.front().ff;
		int j = ones.front().ss;
		if (v[i][j] == 1) {
			f1(v, i, j);
			answer++;
		}
		ones.pop();
	}
	while (!nums.empty())
	{
		int i = nums.front().ff;
		int j = nums.front().ss;
		if (v[i][j] <= 0) {
			nums.pop();
			continue;
		}
		answer++;
		v[i][j] = 0;
		nums.pop();
	}
	
	show(answer);
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
