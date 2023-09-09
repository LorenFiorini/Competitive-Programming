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
		if (W > 1 && all_same) {
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
		if (H > 1 && all_same) {
			for (int i = 0; i < H; i++) {
				marked[i][j] = true;
			}
		}
	}
	//print_vvbool(marked);

	// 3. If there are any marked cookies, remove them all and return to 1; otherwise, terminate the procedure.

	
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

	int new_h = 0;
	int new_w = 0;
	bool ok = true;
	vector<string> new_c;
	while (ok && (H > 1 || W > 1)) {
		ok = false;
		new_c = procedure(c);

		new_h = new_c.size();
		if (new_h == 0) new_w = 0;
		else new_w = new_c[0].size();

		if ((new_h != H || new_w != W)) {
			ok = true;
			H = new_h;
			W = new_w;
			c.swap(new_c);
		}
	}


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


/*
	// for (int j = 0; j < W; j++) {
	// 	bool all_same = true;

	// 	int i = 0;
	// 	int cnt = 0;
	// 	char first_color;
	// 	while (i < H && marked[i][j] == true) {
	// 		i++;
	// 	}
	// 	if (i < H) {
	// 		cnt = 1;
	// 		first_color = c[i][j];
	// 	} else {
	// 		continue;
	// 	}

	// 	for (; i < H; i++) {
	// 		if (marked[i][j] == false) {
	// 			if (c[i][j] != first_color) {
	// 				all_same = false;
	// 				break;
	// 			}
	// 			else {
	// 				cnt++;
	// 			}
	// 		}
	// 	}

	// 	if (cnt > 1 && all_same) {
	// 		for (int i = 0; i < H; i++) {
	// 			marked[i][j] = true;
	// 		}
	// 	}
	// }
*/