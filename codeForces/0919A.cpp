#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	double mn = 1e9;
	for (int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		mn = min(mn, a / b);
	}
	
	double ans = (double) m * mn;
	cout << setprecision(8) << fixed;
	cout << ans << endl;
}
