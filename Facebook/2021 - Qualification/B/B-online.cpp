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
//


void add_row(set<set<pii>> &st, vvi &v, int n, int i) {
	set<pii> coordinates;
	rep (j, 0, n) 
	{
		if (v[i][j] == 0) {
			coordinates.insert({i, j});
		}
	}
	st.insert(coordinates);
}


void add_col(set<set<pii>> &st, vvi &v, int n, int j) {
	set<pii> coordinates;
	rep (i, 0, n) 
	{
		if (v[i][j] == 0) {
			coordinates.insert({i, j});
		}
	}
	st.insert(coordinates);
}


// 1 == X   (mine)
// 0 == .   (free)  
// -1 == O  (theirs)

void solve (){
	// INPUT 
	int n;
	cin >> n;
	vvi v(n, vint(n));
	vint row(n, 0);
	vint col(n, 0);
	rep (i, 0, n) 
	{
		string s;
		cin >> s;
		rep (j, 0, n) 
		{
			switch (s[j]) 
			{
				case 'X':
					v[i][j] = 1;
					break;
				case '.':
					v[i][j] = 0;
					row[i] += 1;
					col[j] += 1;
					// one 'X' more
					break;
				case 'O':
					v[i][j] = -1;
					row[i] = INF;
					col[j] = INF;
					// Impossible
					break;
			}
		}
	}
	
	// Minimum numbers of X I need
	int minX = INF;
	rep (i, 0, n) {
		minX = min(minX, min(row[i], col[i]));
	}
	// Whenever INF => impossible
	if (minX == INF) {
		cout<< "Impossible\n";
		return;
	}
	
	// Check rows and column with minimum possible
	// Store in set<pair<int, int>>  to avoid duplicates 
	set<set<pii>> st;
	// set< i , j >
	rep (i, 0, n) 
	{
		if (row[i] == minX) {
			add_row(st, v, n, i);
		}
		if (col[i] == minX) {
			add_col(st, v, n, i);
		}
	}
	
	int ans = len(st);
	cout << minX << " " << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T, CASE = 0;
	cin >> T;
	while (CASE++ < T) {
		cout << "Case #" << CASE << ": ";
		solve();
	}
	
	return 0;
}


// Lorenzo Fiorini
