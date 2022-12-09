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

using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n = 100;
	vector<string> v(n);
	for (auto &a: v) cin >> a;
	vector<vector<bool>> arr(n, vector<bool> (n, 0));
	char le = 0, to = 0, ri = 0, bo = 0;
	
	for (int i = 0; i < n; i++) {
		le = 0;
		ri = 0;
		for (int j = 0; j < n; j++) {
			// From Left
			if (le < v[i][j]) {
				arr[i][j] = 1;
				le = v[i][j];
			}
			// From Right
			if (v[i][n-j-1] > ri) {
				arr[i][n-j-1] = 1;
				ri = v[i][n-j-1];
			}
		}
	}
	for (int j = 0; j < n; j++) {
		to = 0;
		bo = 0;
		for (int i = 0; i < n; i++) {
			// From Top
			if  (to < v[i][j]) {
				arr[i][j] = 1;
				to = v[i][j];
			}
			// From Bottom
			if (v[n-1-i][j] > bo) {
				arr[n-1-i][j] = 1;
				bo = v[n-1-i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += arr[i][j];
		}
	}

	cout << ans << endl;
	return 0;
}

// Lorenzo Fiorini
// 8355
// 5860
// 299
// 1043
// 1723
// 1367
// 1679

