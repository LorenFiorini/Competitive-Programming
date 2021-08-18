#include <bits/stdc++.h>
using namespace std;

int check(int n, int vb, int vs, vector<int> &v, int x, int y, int i) {
	if (i == 1) return i + 1;
	// Anterior
	double a = (double)(vb * v[i]) + (double) vs * sqrt(pow(x - v[i] , 2) + pow(y , 2));
	double b;
	do {
		i--;
		b = (double)(vb * v[i]) + (double) vs * sqrt(pow(x - v[i] , 2) + pow(y , 2));
	} while (i > 1 && b < a);
	
	//cout << a << "\n" << b << "\n";
	return i + 2;
}


int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int vb, vs;
	cin >> vb >> vs;
	vector<int> v(n); 
	for (auto &a : v) cin >> a;
	int x, y;
	cin >> x >> y;
	
	if (x <= 0) {
		cout << "2\n";
		return 0;
	}
	
	
	for (int i = 0; i < n; i++) {
		if (v[i] > x) {
			int ans = check(n, vb, vs, v, x, y, i);
			cout << ans << "\n";
			return 0;
		}
	}
	
	cout << n << "\n";
	return 0;
}

// Lorenzo Fiorini
