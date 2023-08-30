#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Debugging Tools
#define show(x_) cout << x_ << "\n";
#define showbin(x_, n_) for (int i_ = (1 << n_); i_ > 0; i_ >>= 1) {cout << ((x_&i_)? 1: 0);} cout << "\n";
#define showp(x_, y_) cout << x_ << " " << y_ << "\n";
#define showv(v_) for (auto a_: v_) {cout << a_ << " ";} cout << "\n";
#define showvp(v_) for (auto p_: v_) {showp(p_.first, p_.second);}
#define showmat(mat_) for (auto r_: mat_) {showv(r_);}
#define showset(st_) for (auto a_: st_) {cout << a_ << " ";} cout << "\n";
#define showmap(mp_) for (auto a_: mp_) {cout << a_->first << " " << a_->second << "\n";} cout << "\n";

void solve(void) {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	vector<string> mat(n);
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	map<pair<int, int>, int> lr;
	map<pair<int, int>, int> ud;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'L') {
				lr[{j , j + 1}]++;
			} else if (mat[i][j] == 'U') {
				ud[{i, i + 1}]++;
			}
		}
	}

	// Case when it's impossible
	// cout << "lr\n";
	for (auto p : lr) {
		// cout << p.first.first << " " << p.first.second << ": " << p.second << "\n";
		if (p.second % 2 == 1) {
			cout << "-1\n";
			return;
		}
	}
	// cout << "ud\n";
	for (auto p : ud) {
		// cout << p.first.first << " " << p.first.second << ": " << p.second << "\n";
		if (p.second % 2 == 1) {
			cout << "-1\n";
			return;
		}
	}

	// Case when it's possible
	for (int i = 0; i < n; i++) {
		int UD = 0;
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'U') {
				if (UD == 0) {
					UD = 1;
					mat[i][j] = 'W';
					mat[i + 1][j] = 'B';
				} else {
					UD = 0;
					mat[i][j] = 'B';
					mat[i + 1][j] = 'W';
				}
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int LR = 0;
		for (int i = 0; i < n; i++) {
			if (mat[i][j] == 'L') {
				if (LR == 0) {
					LR = 1;
					mat[i][j] = 'W';
					mat[i][j + 1] = 'B';
				} else {
					LR = 0;
					mat[i][j] = 'B';
					mat[i][j + 1] = 'W';
				}
			}
		}
	}
	
	// Show the matrix
	for (int i = 0; i < n; i++) {
		cout << mat[i] << "\n";
	}
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t; while (t--)
	solve();
	
	return 0;
}

// Lorenzo Fiorini

/*
D. Two-Colored Dominoes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is an n×m
 board divided into cells. There are also some dominoes on this board. Each domino covers two adjacent cells (that is, two cells that share a side), and no two dominoes overlap.

Piet thinks that this board is too boring and it needs to be painted. He will paint the cells of the dominoes black and white. He calls the painting beautiful if all of the following conditions hold:

for each domino, one of its cells is painted white and the other is painted black;
for each row, the number of black cells in this row equals the number of white cells in this row;
for each column, the number of black cells in this column equals the number of white cells in this column.
Note that the cells that are not covered by dominoes are not painted at all, they are counted as neither black nor white.

Help Piet produce a beautiful painting or tell that it is impossible.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤10000
). The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (2≤n,m≤500
).

The next n
 lines describe the tiling of the board, row by row from top to bottom. Each of these lines contains m
 characters, describing the cells in the corresponding row from left to right. Each character is one of U, D, L, R, or ., meaning that the cell is covered with a top, bottom, left, right half of a domino or nothing, respectively. The tiling is guaranteed to be valid.

It is guaranteed that the sum of n⋅m
 over all test cases does not exceed 250000
.

Output
For each test case, output a single integer −1
 if a beautiful painting does not exist. Otherwise, print n
 lines, each containing m
 characters, describing the colors in the corresponding row of a beautiful painting. Every character corresponding to a cell not covered by a domino must be . (a dot), and all other characters must be B if the corresponding cell is black or W if it is white.
*/
