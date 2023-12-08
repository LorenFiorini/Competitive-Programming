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

#define show(__a) for (auto __i : __a) cout << __i << " "; cout << endl;

void solve (void) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	vector<int> dir(n, 0);
	vector<int> rev(n, 0);
	int cd = 0;
	int cr = 0;
	int dir_id = -1;
	int rev_id = -1;

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		if (a[i] <= a[j]) {
			dir[i] = 1;
		} else {
			cd++;
			dir_id = i;
		}
		if (a[i] >= a[j]) {
			rev[i] = 1;
		} else {
			cr++;
			rev_id = i;
		}
		if (min(cd, cr) > 1) {
			cout << -1 << endl;
			return;
		}
	}
	// show(dir);
	// show(rev);
	int ans = n;
	if (cd == 0 || cr == 0) {
		ans = 0;
	} else {
		if (cd == 1) {
			dir_id = min(dir_id, n - 1 - dir_id);
			ans = min(ans, dir_id);
		}
		if (cr == 1) {
			rev_id = min (rev_id, n - 1 - rev_id);
			ans = min(ans, rev_id);
		}
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
