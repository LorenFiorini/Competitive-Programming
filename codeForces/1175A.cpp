#include <bits/stdc++.h>
using namespace std;

int main() {
	long long T, n, k, a, tmp;
	cin >> T;
	while (T--) {
		a = 0;
		cin >> n >> k;
		while (n > 0) {
			if (0 == n%k) {
				n /= k;
				a++;
			} else {
				tmp = n % k;
				n -= tmp;
				a += tmp;
			}
		}
		cout << a << endl;
	}
}
