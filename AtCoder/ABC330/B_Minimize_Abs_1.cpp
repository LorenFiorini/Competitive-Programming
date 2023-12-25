/**
 * B - Minimize Abs 1 / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200 points

Problem Statement
You are given an integer sequence 
A=(A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 ) of length 
N and integers 
L and 
R such that 
L≤R.

For each 
i=1,2,…,N, find the integer 
X 
i
​
  that satisfies both of the following conditions. Note that the integer to be found is always uniquely determined.

L≤X 
i
​
 ≤R.
For every integer 
Y such that 
L≤Y≤R, it holds that 
∣X 
i
​
 −A 
i
​
 ∣≤∣Y−A 
i
​
 ∣.
Constraints
1≤N≤2×10 
5
 
1≤L≤R≤10 
9
 
1≤A 
i
​
 ≤10 
9
 
All input values are integers.
Input
The input is given from Standard Input in the following format:

N 
L 
R
A 
1
​
  
… 
A 
N
​
 
Output
Print 
X 
i
​
  for 
i=1,2,…,N, separated by spaces.


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
	long long n, l, r;
    cin >> n >> l >> r;
    vector<long long> ans(n, l);

    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];

    for (long long i = 0; i < n; i++) {
        long long rhs = max(abs(a[i] - l), abs(a[i] - r));
        if (l <= a[i] && a[i] <= r) {
            ans[i] = a[i];
        } else if (a[i] < l) {
            ans[i] = l;
        } else {
            ans[i] = r;
        }
    }

    for (long long i = 0; i < n; i++) {
        cout << ans[i] << " ";
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

/* Lorenzo Fiorini */
