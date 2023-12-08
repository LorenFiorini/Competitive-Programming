
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

int N = 262144;
map<int, int> cnt;

void show_vector (vector<int> &v) {
	for (int num : v) 
		cout << num << " ";
	cout << endl;
}

// bool is_power_of_two (int x) {
// 	return x && (!(x & (x - 1)));
// }

bool check (vector<int> &v, int val) {
	// if (val > v[1]) return 0;
	// Double pointer technique

	int l = 0, r = 1;
	int sum = 0;

	while (r < N) {
		while (r < min(N, (l + 1) * 2) && sum < val) {
			sum += v[r];
			r++;
		}

		while (l < r && sum >= val) {
			if (sum == val)
				return 1;
			sum -= v[l];
			l++;
		}		
	}
	return false;
}


void solve (void) {
	cnt.clear();
	int n, q; 
	cin >> n >> q;
	vector<int> v(2 * n, 0);
	N = 2 * n;

	for (int i = n; i < 2*n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}

	for (int i = n - 1; i > 0; i--) {
		v[i] = v[2 * i] + v[2 * i + 1];
	}


	// QUERIES
	for (int i = 0; i < q; i++) {
		int op; 
		cin >> op;

		if (op == 1) {
			int s;
			cin >> s;
			
			if (check(v,s) ) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else {
			int id, val;
			cin >> id >> val;
			id += n - 1;
			if (val == v[id]) continue;
			cnt[v[id]]--;
			v[id] = val;
			cnt[v[id]]++;
			while (id > 1) {
				id /= 2;
				v[id] = v[2 * id] + v[2 * id + 1];
			}
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


