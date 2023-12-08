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


void solve (void) {
	string s;
	cin >> s;
	int n = s.size();
	int lower_case = 0;
	int upper_case = 0;
	vector<bool> is_printed(n, 0);


	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'b') {
			lower_case++;
		} else if (s[i] == 'B') {
			upper_case++;
		} else {
			if ('a' <= s[i] && s[i] <= 'z') {
				if (lower_case > 0) {
					lower_case--;
				} else {
					is_printed[i] = 1;
				}
			} else if ('A' <= s[i] && s[i] <= 'Z') {
				if (upper_case > 0) {
					upper_case--;
				} else {
					is_printed[i] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (is_printed[i]) {
			cout << s[i];
		}
	}
	cout << endl;
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
