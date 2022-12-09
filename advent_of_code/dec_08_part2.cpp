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

int scenic(vector<string> &v, int r, int c, int n) {
	int le = 1, ri = 1, down = 1, up = 1;
	int A = 0, B = 0, C = 0, D = 0, mx = 0;

	// to left
	mx = 0;
	while (c + le < n && v[r][c] > v[r][c + le]) {
		//if (mx > v[r][c + le]) A++;
		//else mx = v[r][c + le];
		le++;
	}
	//
	if (c + le == n) le--;
	//else if (v[r][c] == v[r][c + le]) le++;


	// to right
	mx = 0;
	while (c - ri >= 0 && v[r][c] > v[r][c - ri]) {
		//if (mx > v[r][c - ri]) B++;
		//else mx = v[r][c - ri];
		ri++;
	}
	if (c - ri < 0) ri--;
	//else if (v[r][c] == v[r][c - ri]) ri++;


	// to down
	mx = 0;
	while (r + down < n && v[r][c] > v[r + down][c]) {
		//if (mx > v[r + down][c]) C++;
		//else mx = v[r + down][c];
		down++;
	}
	if (r + down == n) down--;
	//else if (v[r][c] == v[r + down][c]) down++;


	// to up
	mx = 0;
	while (r - up >= 0 && v[r][c] > v[r - up][c]) {
		//if (mx > v[r - up][c]) D++;
		//else mx = v[r - up][c];
		up++;
	}
	if (r - up < 0) up--;
	//else if (v[r][c] == v[r - up][c]) up++;

	return (le - A) * (ri - B) * (down - C) * (up - D);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n = 100;
	vector<string> v(n);
	for (auto &a: v) cin >> a;


	int ans = 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < n-1; j++) {
			int val = scenic(v, i, j, n);
			ans = max(ans, val);
			//cout << val << " ";
		}
		//cout << endl;
	}

	cout << ans << endl;
	return 0;
}

// Lorenzo Fiorini

// 609120 -> too high
// 2464 -> too low
// 2240 
// 1470
// 1920
// 9720 -> too low

// 255990 -- >That's not the right answer.
// 284256 --> Neither

// 548550


