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
				for (int k = 0; k < 3; k++) {
					swap(a[k][j], a[k][j + 1]);
				}
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

int increase_beauty (vector<int> &a, vector<int> &b) {
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


void solve (void) {
	// Input
	int n, x;
	cin >> n >> x;
	N = n;
	vector<vector<int>> a(3, vector<int> (n));
	vector<vector<int>> b(3, vector<int> (n));

	for (int i = 0; i < n; i++) {
		cin >> a[0][i];
		a[1][i] = i;
		b[2][i] = a[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[1][i] = i;
		a[2][i] = b[0][i];
	}

	// Current beauty
	int beauty = calculate_beauty(a[0], b);
	while (x < beauty) {
		// To-do: Decrease beauty & break if not possible
		beauty--;
	}
	while (x > beauty) {
		// To-do: Increase beauty & break if not possible
		beauty++;
	}

	if (beauty == x) {
		show("YES");
		showv(b);
	} else {
		show("NO");
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

