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
ifstream input("valid-input.txt");
ofstream output("valid-output.txt");

// INPUT
vint get_input(int &n, int &k) {
	input >> n >> k;
	vint gold(n);
	rep (i, 0, n) {
		input >> gold[i];
	}	
	return gold;
}

vvi adj(int n) {
	vvi v(n);
	rep (i, 0, n-1) {
		int a, b;
		input >> a >> b;
		a--; b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	return v;
}

// Depth first search
vpii dfs(vvi &v, vint &gold, vector<bool> &vis, int pos, vint &leaves) {
	vis[pos] = true;
	
	// Vector of children
	vector<vpii> children;
	for (int nxt : v[pos]) {
		if (! vis[nxt])
			children.pb(dfs(v, gold, vis, nxt, leaves));
	}
	
	// Pick the one with higest sum
	vpii ans;
	int sum = 0;
	for (vpii &tmp : children) {
		int cnt = 0;
		rep (i, 0, len(tmp)) cnt += tmp[i].ss;
		if (cnt > sum) {
			sum = cnt;
			ans = tmp;
		}
	}
	// Add current mine
	ans.pb({pos, gold[pos]});
	
	// Add leaf
	if (len(ans) == 1) {
		leaves.pb(pos);
	}
	return ans;
}

vpii dfs_leaf(vvi &v, vint &gold, vint &vis, int pos, seti &used) {
	vis[pos] = true;
	
	// Vector of children
	vector<vpii> children;
	for (int nxt : v[pos]) {
		if (!vis[nxt] && used.find(nxt) == used.end())
			children.pb(dfs_leaf(v, gold, vis, nxt, used));
	}
	
	// Pick the one with higest sum
	vpii ans;
	int sum = 0;
	for (vpii &tmp : children) {
		int cnt = 0;
		rep (i, 0, len(tmp)) cnt += tmp[i].ss;
		if (cnt > sum) {
			sum = cnt;
			ans = tmp;
		}
	}
	// Add current mine
	ans.pb({pos, gold[pos]});
	
	return ans;
}

// Sum of the first path
int firstTunel(vpii &root, seti &used) {
	int cnt = 0; 
	rep (i, 0, len(root)) {
		used.insert(root[i].ff);
		cnt += root[i].ss; 
	}
	return cnt;	
}

void solve (){
	int n, k;
	vint gold = get_input(n, k);
	vvi v = adj(n);
	// No extra tunels
	if (!k) {output << gold[0] << "\n"; return; }
	
	
	// DFS 	from first node
	vector<bool> firstPath(n, false);
	vint leaves;
	vpii root = dfs(v, gold, firstPath, 0, leaves);
	
	// Initial answer
	seti used;
	int ans = firstTunel(root, used); k--;
	
	// only one tunel extra || only one needed
	if (!k || len(root) == n) {	output << ans << "\n"; return;}
	
	
	//rep (i,0,len(root))	showp(root[i].ff, root[i].ss);
	showv(leaves, len(leaves));
	
	
	rep (i, 0, k) {
		if (len(used) > n) break;
		vector<vpii> tunels;
		rep (i, 0, len(leaves)) {
			if (used.find(leaves[i]) == used.end()) {
				vint vis(n, 0);
				tunels.pb(dfs_leaf(v, gold, vis, leaves[i], used));
			}
		}
		vpii answer;
		int sum = 0;
		for (vpii &tmp : tunels) {
			int cnt = 0;
			rep (i, 0, len(tmp)) cnt += tmp[i].ss;
			if (cnt >= sum) {
				sum = cnt;
				answer = tmp;
			}
		}
		
		ans += firstTunel(answer, used);
	}
	
	
	output << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T, CASE = 0;
	input >> T;
	while (CASE++ < T) {
		output << "Case #" << CASE << ": ";
		solve();
	}
	output.close();
	return 0;
}


// Lorenzo Fiorini
