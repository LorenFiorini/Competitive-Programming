#include <bits/stdc++.h>
using namespace std;

bool div(int num) {
	for (int i = 1; i < 21; i++) {
		if (num % i) {
			return false;
		}
	}
	return true;
}



int main () {
	int mx = 21;
	vector<int> v(mx, 1);
	for (int i = 2; i < mx; i++) {
		if (i) {
			for (int j = 2*i; j < mx; j += i) {
				v[j] = 0;
			}
		}
	}
	int mul = 1;
	for (int i = 2; i < mx; i++) {
		if (v[i] == 1) {
			//cout << i << "\n";
			mul *= i;
		}
	}
	int ans = mul;
	while (!div(ans)) {
		ans += mul;
	}
	cout << ans;
	return 0;
}
