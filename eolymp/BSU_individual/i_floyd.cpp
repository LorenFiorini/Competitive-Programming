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
#define por(I_, A_, B_, in__) for (int I_ = A_; I_ < (B_); I_ += in__)
#define rep(I_, A_, B_) por(I_, A_, B_, 1)
#define each(it, MP) for (auto it = MP.begin(); it != MP.end(); it++)
#define all(C_) C_.begin(), C_.end()
#define allg(C_) all(C_), greater<> ()
#define len(V_) (int) V_.size()
#define precision(d) cout << setprecision(d) << fixed;
// Debugging Tools
#define show(X_) cout << X_ << "\n";
#define showbin(X_) for (int I = (1 << 30); I > 0; I >>= 1) {cout << ((X_&I)? 1: 0);} cout << "\n";
#define showp(X_, Y_) cout << X_ << " " << Y_ << "\n";
#define showv(V_) for (auto A_: V_) {cout << A_ << " ";} cout << "\n";
#define showvp(V_) for (auto P_: V_) {out_p(P_.first, P_.second);}
#define showmat(MAT) for (auto R_: MAT) {out_v(R_);}
#define showset(ST) for (auto X_: ST) {cout << X_ << " ";} cout << "\n";
#define showmap(MP) for (auto P_: MP) {cout << P_.first << " " << P_.second << "\n";} cout << "\n";



void cout_mat(vector<bitset<1600>> &v, int n) {
	rep (i, 0, n) {
		rep (j, 0, n) {
			cout << v[i][j] << "";
		}
		cout << "\n";
	}
	return ;
}

void bfs(vector<bitset<1600>> &v, vvi &edge, int n) {
	vector<bool> act(n, 0);
	queue<int> q;

	rep (i, 0, n) {
		if (!edge[i].empty()) {
			q.push(i);
			act[i] = true;
		} 
	}

	while (!q.empty()) {
		int ch = q.front();
		q.pop();
		act[ch] = false;
		
		for (auto pa: edge[ch]) {
			bitset<1600> bef = v[pa];
			v[pa] |= v[ch];
			if ((bef != v[pa]) && !act[pa]) {
				q.push(pa);
				act[pa] = true;
			}
		}
	}
	return ;
}

void update_v(vector<bitset<1600>> &v, int &n) {
	set<string> sts;
	set<int> sti;
	rep (i, 0, n) {
		string s = v[i].to_string();
		if (sts.find(s) == sts.end()) {
			sts.insert(s);
		} else {
			sti.insert(i);
		}
	}

	int N = n - (int) sti.size();
	vector<bitset<1600>> V(N);

	int row = 0, col = 0;
	rep (i, 0, n) {
		if (sti.find(i) != sti.end()) continue;
		col = 0;

		rep (j, 0, n) {
			if (sti.find(j) == sti.end()) {
				if (v[i].test(j)) {
					V[row].set(col);
				}
				col++;
			}
		}
		row++;
	}
	n = N;
	v.swap(V);
	return ;
}

void get_nodes(vector<bitset<1600>> &v, int n, vint &srcs, vint &sinks, vint &iso)
{
	rep (d, 0, n) {
		int i = 0, c = 0;
		while (i < n) { if (v[i].test(d)) c++; i++; }
		bool src = (c == 1);

		i = 0, c = 0;
		while (i < n) { if (v[d].test(i)) c++; i++; }
		bool sink = (c == 1);
		
		if (src && sink) {
			iso.pb(d);
		} else if (src) {
			srcs.pb(d);
		} else if (sink) {
			sinks.pb(d);
		}
	}
	return ;
}

void dfs(vector<bitset<1600>> &adj, vint &col, int p, int n) {
	rep (i, 0, n) {
		if ((adj[p].test(i)) && col[i] == 0) {
			col[i] = col[p];
			dfs(adj, col, i, n);
		}
	}
	return ;
}


void solve(void) {
	int n, m;
	cin >> n >> m;
	vector<bitset<1600>> v(n);
	vvi edges(n);

	rep (i, 0, n) v[i][i] = 1;
	rep (i, 0, m) {
		int aa, bb;
		cin >> aa >> bb;
		v[aa].set(bb);
		edges[bb].pb(aa);
	}

	// BFS or Dijkstra
	//showp("1.", n); cout_mat(v, n);
	bfs(v, edges, n);
	
	//showp("2.", n); cout_mat(v, n);
	update_v(v, n);
	//showp("3.", n); cout_mat(v, n);

	vint srcs;
	vint sinks;
	vint iso;
	get_nodes(v, n, srcs, sinks, iso);
	//showv(srcs);
	//showv(sinks);
	//showv(iso);

	int a = srcs.size();
	int b = sinks.size();
	int c = iso.size();
	//showp("a: ", a);
	//showp("b: ", b);
	//showp("c: ", c);



	// Get number of components
	map<int, int> mp_col;
	vint col(n, 0);
	vector<bitset<1600>> adj(n);

	rep (i, 0, n) {
		rep (j, 0, n) {
			if (v[i].test(j)) {
				adj[i].set(j);
				adj[j].set(i);
			}
		}
	}
	
	//showp("4.", n); cout_mat(adj, n);
	int color = 1;
	rep (id, 0, n) {
		if (col[id] == 0) {
			mp_col[color] = 0;
			col[id] = color;
			dfs(adj, col, id, n);
			color++;
		}
	}
	//showv(col);
	
	

	for (auto src: srcs)  mp_col[col[src]] += 1;
	for (auto sink: sinks) mp_col[col[sink]] += 1;
	for (auto both: iso)  mp_col[col[both]] += 2;
	//showmap(mp_col);

	int A = a + c;
	int B = 0;
	for (auto p: mp_col) {
		B += (p.second - 1);
	}

	showp(A, B);
	return ;
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}

// Lorenzo Fiorini


