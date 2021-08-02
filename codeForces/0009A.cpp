#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	pair<int, int> ans = {7 - max(a, b), 6};
	
	for (int i = 2; i <= 3; i++) {
		if (ans.first % i == 0 && ans.second % i == 0) {
			ans.first /= i;
			ans.second /= i;
		}
	}
	
	cout << ans.first << "/" << ans.second << "\n";
}
