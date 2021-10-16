#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool lucky(ll n) {
	ll cnt = 0;
	while (n > 0) {
		cnt += (n%10 == 4) || (n%10 == 7);
		n /= 10;
	}
	if (!cnt) return false;
	
	while (cnt > 0) {
		if ((cnt%10 != 4) && (cnt%10 != 7)) return false;
		cnt /= 10;
	}
	return true;
}

int main () {
	ll n;
	cin >> n;
	if (lucky(n)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}

// Lorenzo Fiorini
