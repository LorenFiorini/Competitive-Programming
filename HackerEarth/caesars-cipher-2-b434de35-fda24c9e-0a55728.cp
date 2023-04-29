#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	string t;
	cin >> s >> t;

	int n = s.size();
	int d = t[0] - s[0];
	bool ok = 1;

	for (int i = 0; ok && i < n; i++) {
		int a = ((s[i] + d) - 'a') % 26;
		int b = ((t[i]) - 'a') % 26;
		ok &= (a == b);
	}
	if (ok) {
		if (d < 0) d += 26;
		cout << d << endl;
	} else {
		cout << "-1\n";
	}
}

int main() {
	int Q;
	cin >> Q;
	
	while (Q--) solve();

	return (0);
}