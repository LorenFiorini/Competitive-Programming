#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	double vb, vs;
	cin >> vb >> vs;
	vector<double> v(n); 
	for (auto &a : v) cin >> a;
	double x, y;
	cin >> x >> y;
	
	if (x <= 0) {
		cout << "2\n";
		return 0;
	}
	
	int ans = n;
	double dist = 1e9;
	for (int i = 1; i < n; i++) {
		//cout << dist << "\n";
		double a = v[i] / vb + sqrt(pow(x-v[i] , 2) + pow(y , 2)) / vs;
		if (a <= dist) {
			dist = a;
			ans = i+1;
		} 		
	}
	
	cout << ans << "\n";
	return 0;
}

// Lorenzo Fiorini
