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

vvi make(int &n) {
	int N = 1, num;
	while (N < n) {
		N <<= 1;
	}
	
	vvi v(2 * N, vint(3, 0));
	rep (i, 0, n) {
		cin >> num;
		v[N+i][num-1] = 1;
	}
	//build;

	for (int i = N-1 ; i >= 1; i--) {
		rep(j, 0, 3) {
			v[i][j] = v[2*i][j] + v[2*i + 1][j];
		}
	}
	//showvv(v, 2 * N, 3);
	n = N;
	return v;
}

void update(vvi &v, int id) {
	if (id == 0) return;
	rep(j, 0, 3) {
		v[id][j] = v[2*id][j] + v[2*id + 1][j];
	}
	update(v, id / 2);
}

vint dfs(vvi &v, int id, int le, int ri, int Ql, int Qr) {
	if (Ql <= le && ri <= Qr) return v[id];
	if (Ql > ri || le > Qr) return {0,0,0};

	int last_in_left = (le + ri) / 2;
	vint a = dfs(v, 2*id, le, last_in_left, Ql, Qr);
	vint b = dfs(v, 2*id+1, last_in_left + 1, ri, Ql, Qr);

	vint ans(3);
	rep (j, 0, 3) ans[j] = a[j]+b[j];
	return ans;
}

int cnt(vvi &v, int n, int z) {
	vint a = dfs(v, 1, 1, n, 1, z);
	vint b = dfs(v, 1, 1, n, z+1, n);
	
	cout << endl; showv(a, 3); showv(b, 3);

	int sa = a[0] + 2*a[1] + 3*a[2];
	int sb = b[0] + 2*b[1] + 3*b[2];

	if (sa != sb) {
		if  ((sa + sb) % 2 != 0) return -1;
	} 	

	
	return 0;
}
 
void solve () {
	int ans = 0;
	int n, m, x, y, z;
	cin >> n >> m;
	vvi v = make(n);

	// log2 < n <4> >
	//vector<vvi> v = 

	rep (i, 0, m) {
		cin >> x >> y >> z;
		x--; y--;
		if (v[n+x][y] == 1) continue;

		rep(j, 0, 3) v[n + x][j] = 0; 
		v[n+x][y] = 1;

		update(v, (n+x) / 2);
		//cout << endl;
		//showvv(v, 2*n, 3);

		ans += cnt(v, n, z);
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; 
	cin >> T; 
	for (int C = 1; C <= T; C++) {
		cout << "Case #" << C << ": ";
		//cout << endl;
		solve();
	}
	
	return 0;
}

// Lorenzo Fiorini
