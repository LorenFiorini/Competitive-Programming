#include <bits/stdc++.h>
using namespace std;

int main () 
{
	long long num = 600851475143;
	long long n = sqrt(num);
	for (long long i = 2; i < n + 1; i++) {
		if (i == num) {
			cout << i;
			break;
		}
		else if (num % i == 0) num /= i;
	}
	return 0;
}
