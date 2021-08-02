#include <bits/stdc++.h>
using namespace std;

int main()
{
	// 7 colors, 10 each
	// pick 20 randomly
	// ans = expected number of different colors
	double num = 1, den = 1;
	for (double i = 1; i <= 10; i+=1) {
		num *= (40 + i);
		den *= (60 + i);
	}
	double ans = 7 * ( 1 - num / den);
	cout << ans;
	return 0;
	
}
