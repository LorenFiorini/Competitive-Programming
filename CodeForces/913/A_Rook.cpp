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

	for (char c = '1'; c <= '8'; c++) {
		if (s[1] != c) {
			cout << s[0] << c << endl;
		}
	}
	for (char c = 'a'; c <= 'h'; c++) {
		if (s[0] != c) {
			cout << c << s[1] << endl;
		}
	}
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */
