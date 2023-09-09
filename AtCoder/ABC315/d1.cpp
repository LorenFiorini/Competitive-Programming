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
#include <iomanip>
using namespace std;

/*
Problem Statement There are H×W cookies in H rows and W columns. The color of the cookie at the i-row from the top and j-th column from the left is represented by a lowercase English letter c i,j ​ . We will perform the following procedure. 1. For each row, perform the following operation: if there are two or more cookies remaining in the row and they all have the same color, mark them. 2. For each column, perform the following operation: if there are two or more cookies remaining in the column and they all have the same color, mark them. 3. If there are any marked cookies, remove them all and return to 1; otherwise, terminate the procedure. Find the number of cookies remaining at the end of the procedure.
*/

void print_vstr(vector<string> &c) {
	for (string s : c) {
		cout << s << endl;
	}
}

void print_vvbool(vector<vector<bool>> &marked) {
	for (vector<bool> v : marked) {
		for (bool b : v) {
			cout << b << " ";
		}
		cout << endl;
	}
}

vector<string> procedure(vector<string> &c) {
	int ans = 0;
	int H = c.size();
	int W = c[0].size();
	vector<vector<bool>> marked(H, vector<bool>(W, false));
	
	// 1. For each row, perform the following operation: if there are two or more cookies remaining in the row and they all have the same color, mark them.

	for (int i = 0; i < H; i++) {
		bool all_same = true;
		for (int j = 0; j < W - 1; j++) {
			if (c[i][j] != c[i][j + 1]) {
				all_same = false;
				break;
			}
		}
		if (H > 1 && all_same) {
			for (int j = 0; j < W; j++) {
				marked[i][j] = true;
			}
		}
	}
	//print_vvbool(marked);
	// 2. For each column, perform the following operation: if there are two or more cookies remaining in the column and they all have the same color, mark them.

	for (int j = 0; j < W; j++) {
		bool all_same = true;
		for (int i = 0; i < H - 1; i++) {
			if (c[i][j] != c[i + 1][j]) {
				all_same = false;
				break;
			}
		}
		if (W > 1 && all_same) {
			for (int i = 0; i < H; i++) {
				marked[i][j] = true;
			}
		}
	}
	//print_vvbool(marked);

	// 3. If there are any marked cookies, remove them all and return to 1; otherwise, terminate the procedure.

	// for (int i = 0; i < H; i++) {
	// 	for (int j = 0; j < W; j++) {
	// 		ans += (!marked[i][j]);
	// 	}
	// }

	// if (ans == 0) {
	// 	return 0;
	// }
	
	// Create new vector<string> c
	vector<string> new_c;
	for (int i = 0; i < H; i++) {
		string new_row = "";
		for (int j = 0; j < W; j++) {
			if (!marked[i][j]) {
				new_row += c[i][j];
			}
		}
		if (new_row != "") {
			new_c.push_back(new_row);
		}
	}
	return new_c;
}

void solve () {
	int H, W;
	cin >> H >> W;
	vector<string> c(H);


	for (int i = 0; i < H; i++) {
		cin >> c[i];
	}

	int final_h = 0;
	int final_w = 0;
	vector<string> new_c = c;
	while (H > 1 || W > 1) {
		//print_vstr(c);		cout << endl; // Debug
		new_c = procedure(c);
		H = c.size();
		W = c[0].size();
		final_h = new_c.size();
		if (final_h == 0) {
			break;
		}
		final_w = new_c[0].size();
		if (H == final_h && W == final_w) {
			break;
		} else {
			c = new_c;
			H = c.size();
			W = c[0].size();
		}
	}

	//cout << "Final:"; // Debug
	//cout << H << " " << W << endl; // Debug
	//print_vstr(c); cout << endl;// Debug
	//cout << final_h << " " << final_w << endl;

	int ans = H * W;
	
	cout << ans << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini

