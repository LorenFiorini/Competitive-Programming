#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	
	while (k > 0) {
		if (n % 10) {
			int dif = min(k, n % 10);
			n -= dif;
			k -= dif;
		} else {
			n /= 10;
			k--;
		}
	}
	
	cout << n << endl;
	
	return 0;
}

// Lorenzo Fiorini
