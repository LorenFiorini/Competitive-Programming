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
	int ans = 0;
	string s;
	cin >> s;
	
	for (char c : s) {
		if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') 
		{
			cout << c;
		}
	}
	
	cout << endl;
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
