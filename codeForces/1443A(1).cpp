#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) 
	{
		int n;
		cin >> n;
		for (int i = 4 * n, c = 1; c <= n ; i -= 2, c++) {
			cout << i << " "; 
		}
		cout << "\n";
	}
	return 0;
}
