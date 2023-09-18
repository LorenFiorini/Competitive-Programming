#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	vector<int> pr;
	vector<bool> v(10001, 1);
	for (int i = 2; i < 10001; i++) {
		if (v[i]) pr.push_back(i);
		for (int j = i; j < 10001; j += i) {
			v[j] = false;
		}
	}
	
	//cout << "\n\n\n";
	while (t--) 
	{
		int n;
		cin >> n;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int num = pr[i];
			
		}
		
		cout << "\n";
	}
	/*
	while (t--) 
	{
		int n;
		cin >> n;
		int i = 0, j, cnt = 0;
		while (cnt < n) {
			j = i + 1;
			while (cnt < n && pr[i] * pr[j] <= 4 * n) {
				cout << pr[i] * pr[j] << " ";
				j++;
				cnt++;
			}
			i++;
		}
		cout << "\n";
	}*/
	return 0;
}
