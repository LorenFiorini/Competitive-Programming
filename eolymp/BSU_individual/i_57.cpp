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

//int N = 1601;
//int M = 120001;

void cout_mat(vector<bitset<1600>> &v, int n) {
	rep (i, 0, n) {
		rep (j, 0, n) {
			cout << v[i][j] << "";
		}
		cout << "\n";
	}
}

void bfs(vector<bitset<1600>> &v, vvi &edge, int n) {
	vector<bool> act(n, 0);
	queue<int> q;

	rep (i, 0, n) {
		if (!edge[i].empty()) {
			q.push(i);
			act[i] = 1;
		} 
	}

	while (!q.empty()) {
		int ch = q.front();
		q.pop();
		
		for (auto pa: edge[ch]) {
			bitset<1600> bef = v[pa];
			v[pa] |= v[ch];
			if (bef != v[pa] && !act[pa]) {
				q.push(pa);
				act[pa] = 1;
			}
		}
		act[ch] = 0;
	}
}

void update(vector<bitset<1600>> &v, int &n) {
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

	int r = 0, c = 0;
	rep (i, 0, n) {
		if (sti.find(i) != sti.end()) continue;
		rep (j, 0, n) {
			if (sti.find(j) == sti.end()) {
				V[r][c] = v[i][j];
				c++;
			}
		}
		r++;
		c = 0;
	}
	swap(N, n);
	swap(V, v);
}

void get_nodes(vector<bitset<1600>> &v, int n, vint &srcs, vint &sinks, vint &iso)
{
	rep (d, 0, n) {
		int i = 0, c = 0;
		while (i < n && c < 2) {c += v[i][d]; i++; }
		bool src = (c == 1);
		bool sink = (v[d].count() == 1);
		if (src && sink) {
			iso.pb(d);
		} else if (src) {
			srcs.pb(d);
		} else if (sink) {
			sinks.pb(d);
		}
	}
}

void solve (void) {
	int n, m;
	cin >> n >> m;
	vector<bitset<1600>> v(n);
	vvi edges(n);

	rep (i, 0, n) v[i][i] = 1;
	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		edges[b].pb(a);
	}

	// BFS or Dijkstra
	//showp("1.", n); cout_mat(v, n);
	bfs(v, edges, n);
	//showp("2.", n); cout_mat(v, n);
	update(v, n);
	//showp("3.", n); cout_mat(v, n);
	if (n == 1) {showp(1, 0); return ;}

	vint srcs, sinks, iso;
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

	int A = a + c;
	int B = b + c; //min(a+c, b+c) + abs((a+c) - (b+c)) - 1;
	int d = A - B;
	if (d > 0) {
		B += d;//max(d - 1, 1);
	} 
	//else if (A < B) {
	//	B--;
	//}

	showp(A, B);
}

int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}

// Lorenzo Fiorini