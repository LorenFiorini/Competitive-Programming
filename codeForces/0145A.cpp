#include<bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	int cnt[2] = {0, 0};
	int n = a.size();
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		if (a[i] == '4') cnt[0]++;
		else cnt[1]++;
	}
	int ans = min(cnt[0], cnt[1]) + abs(cnt[0] - cnt[1]);
	
	cout << ans << endl;
	
}
