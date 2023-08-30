#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

void no_dependencies(long long n, vector<long long> h, long long k) {
	// find the maximum hour after which a quest can be completed
	sort(h.begin(), h.end());
	long long ans = 0;
	if (n > 1) {
		ans = h[n-1] - h[0];
		for (long long i = 0; i < n; i++) {
			// ll time = min()
			ans = min(ans, k - h[(i + 1) % n] + h[i]);
		}
	}
	cout << ans << "\n";
	return;
}

// From the source, find the maximum hour after which a quest can be completed
bool dfs(vector<vector<long long>> adj, vector<bool> &vis, vector<ll> &h, vector<ll> &v, ll cur) {
	
	if (adj[cur].size() == 0) {
		v[cur] = h[cur];
		return true;
	}
	for (auto a: adj[cur]) {
		if (!vis[a]) {
			vis[a] = true;
			if (dfs(adj, vis, v, a)) {
				v[cur] = max(v[cur], v[a]);
			}
		}
	}
}

void solve(void) {
	// Read input
	// Number of quests, dependencies, and hours in a game day
	long long n, m, k;
	cin >> n >> m >> k;
	// Hour after each quest can be completed
	vector<long long> h(n);
	for (long long i = 0; i < n; i++) {
		cin >> h[i];
	}
	// Build graph
	vector<vector<long long>> adj(n);
	// vector<long long> indeg(n);
	for (long long i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		a--; b--;
		adj[b].push_back(a);
		// indeg[a]++;
	}

	// Special case when there are no dependencies
	if (m == 0) return no_dependencies(n, h, k);

	long long ans = 0;
	vector<bool> vis(n, false);
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		if (!vis) {
			dfs(adj, vis, h, v, i);
		}
	}
	
	cout << ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t; while (t--)
	solve();
	
	return 0;
}

// Lorenzo Fiorini

/*
E. Speedrun
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are playing a video game. The game has n
 quests that need to be completed. However, the j
-th quest can only be completed at the beginning of hour hj
 of a game day. The game day is k
 hours long. The hours of each game day are numbered 0,1,…,k−1
. After the first day ends, a new one starts, and so on.

Also, there are dependencies between the quests, that is, for some pairs (ai,bi)
 the bi
-th quest can only be completed after the ai
-th quest. It is guaranteed that there are no circular dependencies, as otherwise the game would be unbeatable and nobody would play it.

You are skilled enough to complete any number of quests in a negligible amount of time (i. e. you can complete any number of quests at the beginning of the same hour, even if there are dependencies between them). You want to complete all quests as fast as possible. To do this, you can complete the quests in any valid order. The completion time is equal to the difference between the time of completing the last quest and the time of completing the first quest in this order.

Find the least amount of time you need to complete the game.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤100000
). The description of the test cases follows.

The first line of each test case contains three integers n
, m
, and k
 (1≤n≤200000
, 0≤m≤200000
, 1≤k≤109
) — the number of quests, the number of dependencies between them, and the number of hours in a game day, respectively.

The next line contains n
 integers h1,h2,…,hn
 (0≤hi<k
).

The next m
 lines describe the dependencies. The i
-th of these lines contains two integers ai
 and bi
 (1≤ai<bi≤n
) meaning that quest bi
 can only be completed after quest ai
. It is guaranteed that all dependencies are pairwise distinct.

It is guaranteed that the sum of n
 over all test cases does not exceed 200000
.

It is guaranteed that the sum of m
 over all test cases does not exceed 200000
.

Output
For each test case, output a single integer — the minimum completion time.
*/
