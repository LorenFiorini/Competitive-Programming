
/*
Product
Statement
Let P be the product of all numbers from 1 to N. Write a program that calculates the last non-zero digit of number P.

Input:
The first and only line of standard input contains the number N.

Output:
The standard output should contains the last non-zero digit of number P.

Constraints:
1 ≤ N ≤ 104
Example input:
10
Example output:
8
Explanation:
1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 = 3628800 and the last non-zero digit is 8.

Time and memory limit:
0.1 second
64MB
*/

// Solution

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		while (ans % 10 == 0)
			ans /= 10;
		ans %= 100000;
	}
	cout << ans % 10 << endl;
	return 0;
}
