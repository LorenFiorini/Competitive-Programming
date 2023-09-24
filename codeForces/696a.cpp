#include <bits/stdc++.h>
using namespace std;

void solve () 
{
	int n; 
	cin >> n;
	string b;
	cin >> b;
	vector<int> v(n+1);
	v[0] = 1; cout << 1;
	for (int i = 1; i < n; i++) 
	{
		bool vls = (v[i-1] == 1);
		bool bls = (b[i-1] == '1');
		bool bth = (b[i] == '1'); //d
		if (vls && bls) v[i] = !bth; // 1 1 => same
		else if (!vls && !bls) v[i] = 1; // 0 0 => 1 (just one)
		else v[i] = bth; // 10 vagy 01 => -current (opposite of the current bit)
		cout << v[i];
	}
	cout << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
