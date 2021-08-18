#include <bits/stdc++.h>
using namespace std;


int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	
	vector<int> v(n); 
	for (auto &a : v) cin >> a;
	
	vector<int> a(n, 0);
	vector<int> b(n, 0);
	for (int i = 0; i < n; i++) {
		a[i] = v[i];
		b[n-1-i] = v[n-1-i];
		if (i) {
			a[i] += a[i-1];
			b[n-1-i] += b[n-i];
		}
	}
	
	int p = 0;
	while (p < n && a[p] <= b[p]) p++;
	
	cout << p << " " << n - p << "\n";
	
	return 0;
}

// Lorenzo Fiorini
