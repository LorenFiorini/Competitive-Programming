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

typedef long long ll;

bool check_for_left_right(vector<vector<ll>> &v, ll n, ll k, ll le, ll ri) {
	for (long long i = 0; i < n; i++) {
		if (ri + k < v[i][0] || le - k > v[i][1])
			return false;

		if (v[i][1] >= ri) {
			ri = min(v[i][1], ri + k);
		} else {
			ri = max(v[i][1], le - k);
		}
		if (v[i][0] <= le) {
			le = max(v[i][0], le - k);
		} else {
			le = min(v[i][0], ri + k);
		}
		if (le > ri) return false;
	}
	return true;
}

bool check(vector<vector<ll>> &v, long long n, long long k) {
	// long long le = v[0][0];
	// long long ri = v[0][1];
	
	// if (!check_for_left_right(v, n, k, le, ri)) return false;
	// long long mid = (le + ri) / 2;
	// if (check_for_left_right(v, n, k, mid, mid)) return 1;
	// if (check_for_left_right(v, n, k, ri, ri)) return 1;
	// if (check_for_left_right(v, n, k, le, le)) return 1;
	if (check_for_left_right(v, n, k, 0, 0)) return true;
	return 0;
}
void solve (void) {
	long long ans = 0;
	long long n;
	cin >> n;
	vector<vector<long long>> v(n, vector<long long>(2));
	for (long long i = 0; i < n; ++i) {
		cin >> v[i][0] >> v[i][1];
	}
	long long mn_k = 0;
	long long mx_k = 1e9 + 1;

	while (mn_k < mx_k) {
		int mid = (mn_k + mx_k) / 2;
		if (check(v, n, mid)) {
			// cout << mid << " ";
			ans = mid;
			mx_k = mid;
		} else {
			mn_k = mid + 1;
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


