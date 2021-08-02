#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sumsq = 0;
	int sqsum = 0;
	for (int i = 1; i <= 100; i++) {
		sqsum += i;
		sumsq += i*i;
	}
	sqsum *= sqsum;
	int ans = abs (sqsum - sumsq);
	cout << ans;
	return 0;
}
