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


void remove_adjacent_left_to_right(string s, vector<int> &a) {
	stack<char> stk;

	for (int i = 0; i < n; i++) {
		if (stk.empty()) {
			stk.push(s[i]);
		} else {
			if (stk.top() != s[i]) {
				stk.pop();
			} else {
				stk.push(s[i]);
			}
		}
		a[i + 1] = stk.size();
	}
}

void solve (void) {
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n + 1, 0);
	vector<int> b(n + 1, 0);
	remove_adjacent_left_to_right(s, a);
	reverse(s.begin(), s.end());
	remove_adjacent_left_to_right(s, b);
	reverse(b.begin(), b.end());

	// show(a); // debug
	// show(b); // debug
	int ans = n;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, a[i] + b[i]);
	}
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
