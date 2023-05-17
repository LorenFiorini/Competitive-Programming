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
#define out(X_) cout << X_ << "\n";
#define out_bin(X_) for (int I = (1 << 30); I > 0; I >>= 1) {cout << ((X_&I)? 1: 0);} cout << "\n";
#define out_p(X_, Y_) cout << X_ << " " << Y_ << "\n";
#define out_v(V_) for (auto A_: V_) {cout << A_ << " ";} cout << "\n";
#define out_vp(V_) for (auto P_: V_) {out_p(P_.first, P_.second);}
#define out_mat(MAT) for (auto R_: MAT) {out_v(R_);}
#define out_set(ST) for (auto X_: ST) {cout << X_ << " ";} cout << "\n";
#define out_map(MP) for (auto P_: MP) {cout << P_.first << " " << P_.second << "\n";} cout << "\n";

void cadj(map<int, vector<bool>> &adj);
int oreq(vector<bool> &par, vector<bool> &chi, int n);
void reachable(map<int, vector<bool>> &adj, vvi &con, int n);
vector<vector<bool>> conn_comp(map<int, vector<bool>> &adj, vvi &con, int n);
vector<vector<bool>> adjacency(int n, int m);
vint srcs(vector<vector<bool>> &ad, int n);


int cnt_sinks(vector<vector<bool>> &ad, int n) {
	if (n == 1) return 0;
	int ans = 0;
	rep (i, 0, n) {
		int sum = 0;
		rep (j, 0, n) {
			sum += ad[i][j] != 0;
			if (sum > 1) break;
		}
		ans += (sum == 1);
	}
	return ans;
}

void solve (void) {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> ad = adjacency(n, m);
	n = ad.size();
	if (n == 1) {out("1 0"); return;}

	//out_mat(ad);
	vint src = srcs(ad, n);
	int ans = src.size();
	cout << ans << " ";
	ans = n+1;
	rep (i, 0, n-1) {
		int dia = 0;
		rep (j, 0, n) {
			int r = j;
			int c = (i + j + 1) % n;
			dia += (ad[r][c] == 0);
		}
		ans = min(ans, dia);
	}
	
	cout << ans << "\n";
}


int main (void) 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}



// Lorenzo Fiorini

void cadj(map<int, vector<bool>> &adj) {
	out("Adjacency");
	for (auto p: adj) {
		cout << p.first << " -> ";
		out_v(p.second);
	}
}

int oreq(vector<bool> &par, vector<bool> &chi, int n) {
	int ans = 0;
	rep (i, 0, n) {
		ans += (!par[i]) & chi[i];
		par[i] = par[i] | chi[i];
	}
	return ans;
}

void reachable(map<int, vector<bool>> &adj, vvi &con, int n) {
	vector<bool> act(n, 0);
	queue<int> q;

	rep (i, 0, n) {
		if (con[i].empty()) continue;
		q.push(i);
		act[i] = 1;
	}

	while (!q.empty()) {
		int chi = q.front();
		q.pop();
		
		for (auto par: con[chi]) {
			int changed = oreq(adj[par], adj[chi], n);
			if (changed > 0 && !act[par]) {
				q.push(par);
				act[par] = 1;
			}
		}
		act[chi] = 0;
	}
}

vector<vector<bool>> conn_comp(map<int, vector<bool>> &adj, vvi &con, int n) {
	map<int,int> new_id;

	each(it, adj) {
		vint tm;
		auto jt = it;
		jt++;
		for ( ; jt != adj.end(); jt++)
			if (it->second == jt->second) 
				tm.push_back(jt->first);

		for (auto id: tm) {
			new_id[id] = it->first;
			adj.erase(id);
		}
	}
	vector<vector<bool>> vec;
	each(it, adj) {
		vector<bool> t;
		rep (i, 0, n) {
			if (new_id.find(i) != new_id.end()) continue;
			t.push_back(it->second[i]);
		}
		vec.pb(t);
	}
	return vec;
}

vector<vector<bool>> adjacency(int n, int m) {
	map<int, vector<bool>> adj;
	vvi con(n);
	rep (i, 0, n) {
		vector<bool> row(n, false);
		row[i] = 1;
		adj[i] = row;
	}

	rep (i, 0, m) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		con[b].pb(a);
	}
	//cadj(adj);
	reachable(adj, con, n);
	//cadj(adj);
	return conn_comp(adj, con, n);
}

vint srcs(vector<vector<bool>> &ad, int n) {
	vint ans;
	rep (j, 0, n) {
		int sum = 0;
		rep (i, 0, n) {
			sum += ad[i][j];
			if (sum > 1) break;
		}
		if (sum == 1) ans.push_back(j);
	}
	return ans;
}

// Lorenzo Fiorini

/*
6 4
0 2
1 2
3 4
4 5

5 3
0 1
2 3
3 4
*/
