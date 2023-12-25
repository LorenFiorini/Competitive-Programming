/*A. Forked!
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Lunchbox is done with playing chess! His queen and king just got forked again!

In chess, a fork is when a knight attacks two pieces of higher value, commonly the king and the queen. Lunchbox knows that knights can be tricky, and in the version of chess that he is playing, knights are even trickier: instead of moving 1
 tile in one direction and 2
 tiles in the other, knights in Lunchbox's modified game move 𝑎
 tiles in one direction and 𝑏
 tiles in the other.

Lunchbox is playing chess on an infinite chessboard which contains all cells (𝑥,𝑦)
 where 𝑥
 and 𝑦
 are (possibly negative) integers. Lunchbox's king and queen are placed on cells (𝑥𝐾,𝑦𝐾)
 and (𝑥𝑄,𝑦𝑄)
 respectively. Find the number of positions such that if a knight was placed on that cell, it would attack both the king and queen.

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤108
) — describing the possible moves of the knight.

The second line of each test case contains two integers 𝑥𝐾
 and 𝑦𝐾
 (0≤𝑥𝐾,𝑦𝐾≤108
) — the position of Lunchbox's king.

The third line in a test case contains 𝑥𝑄
 and 𝑦𝑄
 (0≤𝑥𝑄,𝑦𝑄≤108
) — the position of Lunchbox's queen.

It is guaranteed that Lunchbox's queen and king will occupy different cells. That is, (𝑥𝐾,𝑦𝐾)≠(𝑥𝑄,𝑦𝑄)
.

Output
For each test case, output the number of positions on an infinite chessboard such that a knight can attack both the king and the queen.*/


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
	int ans = 0;
	int n = 2;
	vector<int> a(n); cin >> a[0] >> a[1];
	int k[2]; cin >> k[0] >> k[1];
	int q[2]; cin >> q[0] >> q[1];


	set<pair<int, int>> sk;
	set<pair<int, int>> sq;

	for (int i = 0; i < 2; i++) {
		sk.insert({k[0] + a[i], k[1] + a[(i + 1) % 2]});
		sk.insert({k[0] + a[i], k[1] - a[(i + 1) % 2]});
		sk.insert({k[0] - a[i], k[1] + a[(i + 1) % 2]});
		sk.insert({k[0] - a[i], k[1] - a[(i + 1) % 2]});
	}
	for (int i = 0; i < 2; i++) {
		sq.insert({q[0] + a[i], q[1] + a[(i + 1) % 2]});
		sq.insert({q[0] + a[i], q[1] - a[(i + 1) % 2]});
		sq.insert({q[0] - a[i], q[1] + a[(i + 1) % 2]});
		sq.insert({q[0] - a[i], q[1] - a[(i + 1) % 2]});
	}

	for (auto x : sk) {
		if (sq.find(x) != sq.end()) {
			ans++;
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


