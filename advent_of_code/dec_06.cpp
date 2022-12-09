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
	
	string s;
	cin >> s;
	int n = s.size();
	vector<int> v;

	/*
	// PART 1
	for (int i = 0; i < n; i++) {
		set<char> st(s.begin() + i, s.begin() + i + 4);
		if (st.size() == 4) {
			cout << i + 4 << endl;
			break;
		}
	}
	*/
	for (int i = 0; i < n - 13; i++) {
		set<char> st(s.begin() + i, s.begin() + i + 14);
		if (st.size() == 14) {
			cout << i + 14 << endl;
			break;
		}
	}


	
	return 0;
}

// Lorenzo Fiorini
// 1330

// 3986
