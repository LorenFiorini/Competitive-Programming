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
#include <unordered_map>
#include <unordered_set>
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

int get_max_k(vector<vector<int>> &v, int n) {
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int k = max(v[i][1] - v[i - 1][0], v[i][0] - v[i - 1][1]);
		
		ans = max(ans, k);
	}
	return ans;
}

int get_max_p(vector<vector<int>> &v, int n) {
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int p = max(v[i][1] - v[i - 1][1], v[i][0] - v[i - 1][0]);
		
		ans = max(ans, p);
	}
	return ans;
}

void solve (void) {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(2));
	for (int i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
	}
	int K = get_max_k(v, n);
	int P = get_max_p(v, n);
	cout << K << " " << P << endl;

}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
