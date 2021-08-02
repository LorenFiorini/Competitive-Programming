#include<bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n ; i++) 
		cin >> v[i];
	
	for (int i = n-1; i >= 0 ; i--) 
		cout << v[i] << " ";
		
	cout << endl;
}

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
		
	return 0;
}

