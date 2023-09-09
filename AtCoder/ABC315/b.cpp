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


void solve () {
	int total_days = 0;
	int m;
	cin >> m;
	vector<int> d(m);
	for (int i = 0; i < m; i++) {
		cin >> d[i];
		total_days += d[i];
	}

	int middle_day = (total_days + 1) / 2;

	for (int i = 0; i < m; i++) {
		if (middle_day <= d[i]) {

			cout << i + 1 << " " << middle_day << endl;
			return;
		}
		middle_day -= d[i];
	}
	
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
