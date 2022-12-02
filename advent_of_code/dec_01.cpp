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
	string line;
	vector<int> v(1);
	int i = 0;

	while (getline(cin, line)) {
		//cout << line << endl;
		if (line.size()) {
			v[i] += stoi(line);
		} else {
			v.push_back(0);
			i++;
		}
	}
	// First star
	//int mx = *max_element(v.begin(), v.end());
	//cout << mx << endl;
	int ans = 0;
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < 3; i++) ans += v[i];
	
	cout << ans << endl;

	return 0;
}

// Lorenzo Fiorini