#include<bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n , h;
	cin  >> n >> h;
	int ans = n;
	for (int i = 0; i < n; i++) {
		int a; 
		cin >> a;
		ans += a > h; 
	}
	cout << ans << endl;	
}

