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


int n ;

void show (vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

map<pair<int, stack<char>>, int> dp;

int remove_adjacent(string s, stack<char> stk, int i) {
	if (i == n)
		return stk.size();
	
	if (dp.find({i, stk}) != dp.end())
		return dp[{i, stk}];
	
	int ans = remove_adjacent(s, stk, i + 1);
	if (!stk.empty() && stk.top() != s[i]) {
		stk.pop();
		ans = min(ans, remove_adjacent(s, stk, i + 1));
	}
	dp[{i, stk}] = ans;
	return ans;
}


void solve (void) {
	dp.clear();
	cin >> n;
	string s;
	cin >> s;

	stack<char> stk;
	int ans = remove_adjacent(s, stk, 0);

	// show(a); // debug
	// show(b); // debug
	
	cout << ans << endl;
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
