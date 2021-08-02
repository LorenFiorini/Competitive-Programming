#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a > c) swap(a, c);
	
	ll ans = 0;
	if (b >= c) {
		ans = (2 * (b-a) + a) - c;
	} else if (b <= a) {
		if ((c-a) % 2) {
			ans = 1;
			a++;
		}
		ans += (c-a)/2 + a - b;
	} else {
		
	}	
	cout << ans << endl; 
}
















/*
int main() {
	ll a, b, c, ans = 0;
	cin >> a >> b >> c;
	if (a > c) swap(a, c);
	
	if (a == c) {
		ans = abs(a-b);
	} else if ((a+c) % 2) {
		ans = min(abs((a+c-1) / 2 - b), abs((a+c+1) / 2 - b));
	} else {
		ans = abs((a+c) / 2 - b);
	}
	
	cout << ans << endl;
}
*/
