#include <bits/stdc++.h>
using namespace std;

int main() 
{
	vector<long long> v;
	for (int i = 0; i < 20; i++) {
		string s;
		cin >> s;
		int sz = s.size();
		for (int j = 0; j < sz; j++) {
			long long num = s[j] - '0';
			v.push_back(num);
		}
	}
	
	long long max = 0;
	int n = v.size();
	for (int i = 0; i < n - 13; i++) {
		cout << v[i] << "\n";
		long long p = 1;
		for (int j = 0; j < 13; j++) {
			p *= v[i+j];
		}
		if (p > max) {
			max = p;
		}
	}
	
	cout << max ;
	
}



