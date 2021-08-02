#include<bits/stdc++.h>
using namespace std;

int main() {
	int ans = 0;
	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i && v[i] <= v[i-1]) {
			int dif = abs(v[i-1] - v[i]) + 1;
			int x = dif / d + ((dif%d != 0)? 1 : 0);
			v[i] += d * x;
			ans += x;
			//cout << dif << "\t" << x << "\n";
		}
	} 
	
	//for (int i = 0; i < n; i++) cout << v[i] << " ";
	//cout << "\n";
	cout << ans << endl;
	
	
	return 0;
}
