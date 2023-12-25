/*
Problem Statement
You are given a positive integer 
D.

Find the minimum value of 
∣x^2 + y^2 − D∣ for non-negative integers x and y.

Constraints
1≤D≤2×10^12
 
All input values are integers.
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

long long MAX = 2 * 1e12;


long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


void solve() {
    long long D;
	cin >> D;
    long long ans = D;


    long long x = sqrt(D) + 3;
    long long y = 0;

    while (x >= y) {
        x--;
        if (x * x >= D) 
            y = 0;
        else
            y = sqrt(D - x * x);
        ans = min(ans, abs(x * x - D + y * y));
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
