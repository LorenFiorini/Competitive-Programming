#include <bits/stdc++.h>
using namespace std;


int main() {
	int sum = 2;
	int last = 1;
	int cur = 2;
	while (cur < 4e6) {
		int tmp = cur;
		cur += last;
		last = tmp;
		if (cur % 2 == 0) sum += cur;
	}
	cout << sum;
	return 0;
}
