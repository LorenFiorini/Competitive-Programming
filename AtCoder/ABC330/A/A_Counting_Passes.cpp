/*
A - Counting Passes / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100 points

Problem Statement
N people labeled 
1,2,…,N took an exam, and person 
i scored 
A 
i
​
  points.
Only those who scored at least 
L points pass this exam.
Determine how many people out of the 
N have passed the exam.

Constraints
All input values are integers.
1≤N≤100
1≤L≤1000
0≤A 
i
​
 ≤1000
Input
The input is given from Standard Input in the following format:

N 
L
A 
1
​
  
A 
2
​
  
… 
A 
N
​
 
Output
Print the answer as an integer.
*/

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

void solve() {
	int ans = 0;
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] >= l) {
			ans++;
		}
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

/* Lorenzo Fiorini */
