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
Problem Statement
We have 
N cups of ice cream.
The flavor and deliciousness of the 
i-th cup are 
F 
i
​
  and 
S 
i
​
 , respectively (
S 
i
​
  is an even number).

You will choose and eat two of the 
N cups.
Your satisfaction here is defined as follows.

Let 
s and 
t (
s≥t) be the deliciousness of the eaten cups.
If the two cups have different flavors, your satisfaction is 
s+t.
Otherwise, your satisfaction is 
s+ 
2
t
​
 .
Find the maximum achievable satisfaction.*/

void solve () {
	int ans = 0;
	int n;
	cin >> n;
	map<int, vector<int>> flavors;

	for (int i = 0; i < n; i++) {
		//cin >> cups[i][1] >> cups[i][0];
		int flavor, deliciousness;
		cin >> flavor >> deliciousness;
		flavors[flavor].push_back(deliciousness);
	}

	vector<vector<int>> cups;
	for (auto it = flavors.begin(); it != flavors.end(); it++) {
		cups.push_back(it->second);
	}

	int m = cups.size();
	for (int i = 0; i < m; i++) {
		sort(cups[i].begin(), cups[i].end(), greater<int>());
	}
	sort(cups.begin(), cups.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] > b[0];
	});

	// Debug, print cups
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < cups[i].size(); j++) {
	//		cout << cups[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	ans = max(ans, cups[0][0] + cups[0][1] / 2);
	if (m > 1) {
		ans = max(ans, cups[0][0] + cups[1][0]);
	}
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
