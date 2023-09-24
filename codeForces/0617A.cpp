#include <bits/stdc++.h>
using namespace std;

int main () 
{

	int x;
	cin >> x;
	
	int ans = (x % 5 != 0);
	ans += x / 5;
	
	cout << ans << endl;
	
	return 0;
}

// Lorenzo Fiorini
