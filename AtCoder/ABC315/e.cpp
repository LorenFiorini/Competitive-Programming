#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
using namespace std;

/**
 * Problem Statement
 * We have N books numbered 1 to N. Book i assumes that you have read C i ​ books, the j-th of which is book P i,j ​ : you must read all these C i ​ books before reading book i. Here, you can read all the books in some order. You are trying to read the minimum number of books required to read book 1. Print the numbers of the books you must read excluding book 1 in the order they should be read. Under this condition, the set of books to read is uniquely determined. If there are multiple reading orders that satisfy the condition, you may print any of them.
 * Constraints
 * Constraints 2≤N≤2×10 5 0≤C i ​ <N ∑ i=1 N ​ C i ​ ≤2×10 5 C 1 ​ ≥1 1≤P i,j ​ ≤N P i,j ​  =P i,k ​ for 1≤j<k≤C i ​ . It is possible to read all the books.
 */

void dfs(vector<vector<int>> &adj, int cur, vector<int> &used, vector<int> &ans) {
	used[cur] = 1;
	for (int v : adj[cur]) {
		if (used[v - 1]) continue;
		dfs(adj, v - 1, used, ans);
	}
	ans.push_back(cur + 1);
	// cout << cur + 1 << " ";
}

void solve () {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		int ci;
		cin >> ci;
		adj[i].resize(ci);
		for (int j = 0; j < ci; j++) {
			cin >> adj[i][j];
		}
	}
	
	vector<int> ans;
	vector<int> used(n, 0);
	dfs(adj, 0, used, ans);
	
	int m = ans.size();
	for (int i = 0; i < m-1; i++) {
		cout << ans[i] << " ";
	}
	
	
	cout << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}
