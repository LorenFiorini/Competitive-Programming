#include<bits/stdc++.h>
using namespace std;

bool ok(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num%10;
		num /= 10;
	}
	return sum == 10;
}

int main () {
	int n;
	cin >> n;
	int num = 1;
	for (int i = 0; i < n; i += ok(num)) {
		num++;
	}
	
	cout << num << endl;
}
