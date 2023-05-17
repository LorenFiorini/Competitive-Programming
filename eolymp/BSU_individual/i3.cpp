#include "bits/stdc++.h"
using namespace std;
// My Favorite Macros
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<vll> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
#define mk make_pair
#define pb push_back
#define ff first
#define ss second
#define por(I_, A_, B_, in__) for (ll I_ = A_; I_ < (B_); I_ += in__)
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

//void cadj(map<ll, vector<bool>> &adj);
//bool oreq(vector<bool> &par, vector<bool> &chi, ll n);
//void reachable(map<ll, vector<bool>> &adj, vvi &con, ll n);
//vector<vector<bool>> conn_comp(map<ll, vector<bool>> &adj, vvi &con, ll n);
//vector<vector<bool>> adjacency(ll n, ll m);
//vll srcs(vector<vector<bool>> &ad, ll n);



// Lorenzo Fiorini

static void cadj(map<ll, vector<bool>> &adj) {
	out("Adjacency");
	for (auto p: adj) {
		cout << p.first << " -> ";
		out_v(p.second);
	}
}

static bool oreq(vector<bool> &par, vector<bool> &chi, ll n) {
	bool ans = 0;
	rep (i, 0, n) {
		if (!par[i] && chi[i]) {
			ans = 1;
			par[i] = 1;
		}
	}
	return ans;
}

static void reachable(map<ll, vector<bool>> &adj, vvi &con, ll n) {
	vector<bool> act(n, 0);
	queue<ll> q;

	rep (i, 0, n) {
		if (con[i].size() > 0) {
			q.push(i);
			act[i] = 1;
		}
	}

	while (!q.empty()) {
		ll chi = q.front();
		q.pop();
		act[chi] = 0;
		
		for (auto par: con[chi]) {
			bool changed = oreq(adj[par], adj[chi], n);
			if (changed && (!act[par])) {
				q.push(par);
				act[par] = true;
			}
		}
	}
}

static void conn_comp(map<ll, vector<bool>> &adj, vector<vector<bool>> &vec, ll n) {
	set<ll> ids;

	for (auto it = adj.begin(); it != adj.end(); it++) {
		vll tm;
		auto jt = it;
		jt++;

		for ( ; jt != adj.end(); jt++){
			if (it->second == jt->second) {
				tm.push_back(jt->first);
			}
		}

		for (ll id: tm) {
			ids.insert(id);
			adj.erase(id);
		}
	}

	for (auto it = adj.begin(); it != adj.end(); it++) {
		vector<bool> t;
		rep (i, 0, n) {
			if (ids.find(i) == ids.end()) {
				t.push_back(it->second[i]);
			}
		}
		vec.pb(t);
	}

}

static void adjacency(ll &n, ll &m, vector<vector<bool>> &ad) {
	map<ll, vector<bool>> adj;
	vvi con(n);
	rep (i, 0, n) {
		vector<bool> row(n, false);
		adj[i] = row;
		adj[i][i] = 1;
	}

	rep (i, 0, m) {
		ll a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		con[b].pb(a);
	}
	//cadj(adj);
	reachable(adj, con, n);
	reachable(adj, con, n);
	//cadj(adj);
	conn_comp(adj, ad, n);
}

static ll srcs(vector<vector<bool>> &ad, ll n) {
	ll ans = 0;
	rep (j, 0, n) {
		ll sum = 0;
		rep (i, 0, n) {
			sum += ad[i][j];
			if (sum > 1) break;
		}
		if (sum == 1) ans++;
	}
	return (ans);
}

// Lorenzo Fiorini


static ll cnt_sinks(vector<vector<bool>> &ad, ll n) {
	if (n == 1) return 0;
	ll ans = 0;
	rep (i, 0, n) {
		ll sum = 0;
		rep (j, 0, n) {
			sum += (ad[i][j]);
			if (sum > 1) break;
		}
		ans += (sum == 1);
	}
	return (ans);
}

static void solve (void) {
	ll n, m;
	cin >> n >> m;
	if (n > 1 && m == 0) {out_p(n, n); return;}
	vector<vector<bool>> ad;
	adjacency(n, m, ad);
	

	n = ad.size();
	if (n == 1) {out("1 0"); return;}

	//out_mat(ad);
	ll ans = srcs(ad, n);

	cout << ans << " ";
	ans = n;
	rep (i, 0, n-1) {
		ll dia = 0;
		rep (j, 0, n) {
			ll r = j;
			ll c = (i + j + 1) % n;
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

	return (0);
}

