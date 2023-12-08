#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
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
using namespace std;


// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";


int N = 0;

void bubble_sort (vector<vector<int>> &a) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (a[0][j] > a[0][j + 1]) {
				swap(a[0][j], a[0][j + 1]);
				swap(a[1][j], a[1][j + 1]);
			}
		}
	}
}

int calculate_beauty (vector<int> &a, vector<int> &b) {
	int beauty = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] > b[i])
			beauty++;
	}
	return beauty;
}

int get_max_beauty (vector<int> &a, vector<int> &b) {
	int max_beauty = 0;
	int i = 0, j = 0;
	while (i < N && j < N) {
		if (a[i] > b[j]) {
			max_beauty++;
			j++;
		}
		i++;
	}
	return (max_beauty);
}


// vector<int> create_beauty_array (vector<vector<int>> &a, vector<int> &b, int x) {
// 	vector<int> ans(N);
// 	int i = 0, j = 0;
// 	queue<int> q;
// 	while (x > 0 && i < N && j < N) {
// 		if (a[0][i] > b[j]) {
// 			ans[a[1][i]] = b[j];
// 			i++;
// 			j++;
// 			x--;
// 		} else {
// 			q.push(b[j]);
// 			j++;
// 		}
// 	}
// 	while (i < N && !q.empty()) {
// 		ans[a[1][i]] = q.front();
// 		q.pop();
// 		i++;
// 	}
// 	return ans;
// }

vector<int> create_beauty_array (vector<vector<int>> &a, vector<int> &b, int x) {
	vector<int> ans(N);
	
	queue<int> q;
	for (int num : b) q.push(num);

	for (int i = 0; i < N; i++) {
		if (x > 0) {
			while (a[0][i] <= q.front()) {
				q.push(q.front());
				q.pop();
			}
			ans[a[1][i]] = q.front();
			q.pop();
			x--;
		} else {
			while (a[0][i] > q.front()) {
				q.push(q.front());
				q.pop();
			}
			ans[a[1][i]] = q.front();
			q.pop();
		}
	}

	return ans;
}
void solve (void) {
	// Input
	int n, x;
	cin >> n >> x;
	N = n;
	vector<vector<int>> a(3, vector<int> (n));
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[0][i];
		a[1][i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	// If already beautiful
	int beauty = calculate_beauty(a[0], b);
	if (beauty == x) {	show("YES"); showv(b); return;	}

	// SORT BOTH (ASCENDING)
	bubble_sort(a);
	sort(b.begin(), b.end());

	a[2] = b;
	// for (int i = 0; i < 3; i++) {cout << i << ") "; showv(a[i]);} 			// Debug 

	// MAX BEAUTY
	int max_beauty = get_max_beauty(a[0], b);
	// cout << "- MAX: " << max_beauty << endl; 			// Debug
	if (x > max_beauty) { show("NO");	return;	}

	// MIN BEAUTY
	int min_beauty = get_max_beauty(b, a[0]);
	// cout << "- MIN: " << min_beauty << endl; 			// Debug
	if (x < min_beauty) { show("NO");	return;	}

	
	// SURELY YES

	vector<int> ans = create_beauty_array(a, b, x);
	
	// cout << min_beauty << " <= " << x << " <= " << max_beauty << endl; 			// Debug
	// cout << " Final beauty: " << calculate_beauty(a, ans) << endl; 			// Debug

	// Output
	cout << "YES" << endl;
	showv(ans);
	showv(a[2]);
}

int main (void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T; while (T--)
	
	solve();
	
	return (0);
}

/* Lorenzo Fiorini */

