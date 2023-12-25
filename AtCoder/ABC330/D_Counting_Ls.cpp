/**D - Counting Ls / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
400 points

Problem Statement
You are given an 
N×N grid. Let 
(i,j) denote the cell in the 
i-th row from the top and the 
j-th column from the left.
The states of the cells are given by 
N strings of length 
N, 
S 
1
​
 ,S 
2
​
 ,…,S 
N
​
 , in the following format:

If the 
j-th character of 
S 
i
​
  is o, there is an o written in cell 
(i,j).
If the 
j-th character of 
S 
i
​
  is x, there is an x written in cell 
(i,j).
Find the number of triples of cells that satisfy all of the following conditions:

The three cells in the triple are distinct.
All three cells have an o written in them.
Exactly two of the cells are in the same row.
Exactly two of the cells are in the same column.
Here, two triples are considered different if and only if some cell is contained in exactly one of the triples.

Constraints
N is an integer between 
2 and 
2000, inclusive.
S 
i
​
  is a string of length 
N consisting of o and x.
Input
The input is given from Standard Input in the following format:

N
S 
1
​
 
S 
2
​
 
⋮
S 
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
    long long ans = 0;
	long long n;
	cin >> n;
    vector<string> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];

    vector<long long> row(n, 0), col(n, 0);
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++){
            if (v[i][j] == 'o') {
                row[i]++;
                col[j]++;
            }
        }
    }

    // cout << "."; for (long long num : col) cout << num << " "; cout << endl; // debug
    // for (long long num : row) cout << num << "\n"; cout << endl; // debug

    for (long long i = 0; i < n; i++) {
        // ans = 0; // debug
        for (long long j = 0; j < n; j++){
            if (v[i][j] == 'o' && min(row[i], col[j]) >= 2) {
                // long long tmp = min(row[i], col[j]) +1;
                // ans += (tmp - 1) * (tmp - 2) / 2;
                ans += (row[i] - 1) * (col[j] - 1);
                // cout << i << "," << j << " ans: " << ans << endl; // debug
            }
        }
        // cout << ans << endl; // debug
    }

	cout << ans << endl;
}

// 5625
// 5776

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

/* Lorenzo Fiorini */


/**
xooxxooooxxxoox
oxxoxoxxxoxoxxo
oxxoxoxxxoxoxxx
ooooxooooxxoxxx
oxxoxoxxxoxoxxx
oxxoxoxxxoxoxxo
oxxoxooooxxxoox
xxxxxxxxxxxxxxx
xooxxxooxxxooox
oxxoxoxxoxoxxxo
xxxoxxxxoxoxxoo
xooxxxooxxoxoxo
xxxoxxxxoxooxxo
oxxoxoxxoxoxxxo
xooxxxooxxxooox
*/
