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

int remove_adjacent_pairs_when_possible (int n, string s) {
	int ans = n;
	stack<char> stk;

	for (char ch : s) {
		if (stk.empty()) {
			stk.push(ch);
		} else {
			if (stk.top() != ch) {
				stk.pop();
				ans -= 2;
			} else {
				stk.push(ch);
			}
		}
	}

	return ans;
}

void solve (void) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = remove_adjacent_pairs_when_possible(n, s);
	reverse(s.begin(), s.end());
	int b = remove_adjacent_pairs_when_possible(n, s);

	// cout << a << " " << b << endl; // debug
	cout << min(a, b) << endl;
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
