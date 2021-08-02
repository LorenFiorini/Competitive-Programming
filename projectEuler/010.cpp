#include <bits/stdc++.h>
using namespace std;

int main () {
	vector<long long> v;
	long long n = 2 * 1e6;
	for (long long num = 2; num <= n; num++) 
	{
		bool div = false;
		long long len = v.size();
		for (long long j = 0; j < len; j++) 
		{
			if (num % v[j] == 0) {
				div = true;
				break;
			}
		}
		if (!div) {
			v.push_back(num);
		}
	}
	long long ans = 0;
	long long len = v.size();
	for (long long i = 0; i < len; i++) {
		ans += v[i];
	}
	
	
	cout << ans;
	return 0;
}


