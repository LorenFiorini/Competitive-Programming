#include "bits/stdc++.h"
using namespace std;
// My Favorite Macros
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
#define ff first
#define ss second
#define por(i, a, b, in) for (int i = a; i < (b); i += in)
#define rep(i, a, b) por(i, a, b, 1)
#define each(it, mp) for (auto it = mp.begin(); it != mp.end(); it++)
#define all(c) c.begin(), c.end()
#define allg(c) all(c), greater<> ()
#define len(v) (int) v.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(x) cout << x << "\n";
#define showbin(x) for (int i = (1 << 30); i > 0; i >>= 1) {cout << ((x&i)? 1: 0);} cout << "\n";
#define showp(x, y) cout << x << " " << y << "\n";
#define showv(v) for (auto val: v) {cout << val << " ";} cout << "\n";
#define showvp(v) for (auto par: v) {showp(par.ff, par.ss);}
#define showmat(mat) for (auto row: mat) {showv(row);}
#define showset(it, st) each(it, st) {cout << *it << " ";} cout << "\n";
#define showmap(it, mp) each(it, mp) {cout << it->ff << " " << it->ss << "\n";} cout << "\n";

int n, m;
int answer[2];
// row_signature -> indexes with the same
//map<vint, vint> r_ids;
// cnt_of_ones - > row_signature
map<vint, int> comp;
vint rooot;


int oreq(vint &par, vint &chi)
{
	//cout << "oreq" << endl;
	int ans = 0;
	rep (i, 0, n) {
		ans += (!par[i] && chi[i]);
		par[i] |= chi[i];
	}
	return ans;
}

void reachable(vvi &adj, vvi &dir, vvi &con)
{
	//cout << "reachable" << endl;
	vint act(n, 0);
	queue<int> q;

	rep (i, 0, n) {
		if (con[i].empty()) continue;
		q.push(i);
		act[i] = 1;
	}
	// 0 not in queue
	// 1 wating to be processed
	while (!q.empty()) {
		int chi = q.front();
		q.pop();
		
		for (auto par: con[chi]) {
			int changed = oreq(adj[par], adj[chi]);
			if (changed && !act[par]) {
				q.push(par);
				act[par] = 1;
			}
		}
		act[chi] = 0;
	}
}


bool or_is_complete(vint &a, vint &b)
{
	//cout << "or_is_complete" << endl;
	rep (i, 0, n) {	if (!(a[i] | b[i])) return 0;}
	return 1;
}


int dfs_start(vvi &keys, int p, int n_keys, vint cur, vint &cnt)
{
	//cout << "dfs_start" << endl;
	if (p >= n_keys) return n_keys;
	if (cnt.size() >= answer[0]) return n_keys;

	int wo = n_keys, wi = n_keys;
	wo = dfs_start(keys, p + 1, n_keys, cur, cnt);
	answer[0] = min(answer[0], wo);

	if (cnt.size() + 1 < answer[0]) {
		cnt.push_back(p);
		oreq(cur, keys[p]);
		if (accumulate(all(cur), 0) == n) {
			wi = cnt.size();
		} else {
			wi = dfs_start(keys, p + 1, n_keys, cur, cnt);
		}
		if (wi < answer[0]) {
			answer[0] = wi;
			rooot = cnt;
		}
		cnt.pop_back();
	}
	
	//showp("p:", p); showp("wo:", wo); showp("wi:", wi); 
	
	return answer[0];
}


void fill_map(vvi &adj)
{
	//cout << "fill_map" << endl;
	rep (i, 0, n) {
		comp[adj[i]] = accumulate(all(adj[i]), 0);
	}
	// Two things left
	// 1. Calculate how many computers I needed at the beggining
	// 2. Connect sinks to sources
	vvi keys(1, vint(n, 0));
	for (auto &p: comp) {
		keys.push_back(p.first);
	}
	int n_keys = keys.size();
	//showp("Keys:", n_keys); showmat(keys);
	vint cnt;
	dfs_start(keys, 1, n_keys, keys[0], cnt);
}


void solve (void)
{
	answer[0] = answer[1] = 1e9;
	cin >> n >> m;
	vvi adj(n, vint(n));
	vvi dir(n);
	vvi con(n);

	rep (i, 0, n) adj[i][i] = 1;
	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		dir[a].pb(b);
		con[b].pb(a);
		adj[a][b] = 1;
	}
	//show("Adjacency"); showmat(adj);
	//show("Dir: Parent -> Child"); showmat(dir);
	//show("Con: Parent <- Child"); showmat(con);

	reachable(adj, dir, con);
	//show("Adjacency"); showmat(adj);

	fill_map(adj);
	//show(r_ids.size());
	//answer[1] = r_ids.size();
	//for (auto p: r_ids) {
	//	cout << "Key: "; showv(p.first);
	//	cout << "Ids: "; showv(p.second);
	//}
	
	//for (auto p: comp) {
	//	cout << "Count: "; show(p.second);
	//	cout << "Key: "; showv(p.first);
	//}

	//show(comp.size());
	answer[1] = comp.size();
	if (answer[0] <= 1) answer[1]--;
	showp(answer[0], answer[1]);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	int a[2] = {1, 0};
	//int b[2] = {2, 3};
	//a = a ^ b;
	//showp(a[0], a[1]);
	show((sizeof(a)));
	show((sizeof(bool)));
	show((sizeof(byte)));
	bitset<128> B;
	show((sizeof(B)));
	bitset<16> C;
	show((sizeof(C)));
	*/
	solve();
	
	return 0;
}

// Lorenzo Fiorini
/*

Adjacency
1 1 1 1 0 
0 1 0 1 1 
0 0 1 0 0 
0 0 0 1 0 
1 0 0 0 1

*/
