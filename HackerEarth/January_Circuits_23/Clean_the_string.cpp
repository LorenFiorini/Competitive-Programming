#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int count(string s, string t, vector<int> v) {
	int a = 0, i = 0, j = 0;
	int b = 0;
	
	while (i < 3) {
		while (v[i] > 0) {
			a += (s[j] != t[i]);
			b += (s[j] == t[i]);
			v[i]--;
			j++;
		}
		i++;
	}
	cout << a << " " << b << endl;
	return abs(a - b);
}

void solve(void) {
	int ans = 1e9;
	string s;
	cin >> s;
	string t = "012";
	vector<int> cnt(3, 0);
	for (char c: s) cnt[c - '0']++;
	

	do {
		if (next_permutation(cnt.begin(), cnt.end()) == 0 && t != "012") {
			sort(cnt.begin(), cnt.end());
		}
		int tmp = count(s, t, cnt);
		ans = min(ans, tmp);
		//cout << tmp << " ";
	} while (next_permutation(t.begin(), t.end()));


	/*
	//   0 1 2
	// 0 
	// 1
	// 2
	string t = s;
	int n = s.size();
	sort(t.begin(), t.end());
	vector<vector<int>> v(3, vector<int> (3, 0));


	for (int i = 0; i < n; i++) {
		v[s[i] - '0'][t[i] - '0']++;
	}
	for (auto row: v) {for (auto a: row) cout << a << " "; cout << endl;}

	*/
	cout << ans << endl << endl;
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t; while (t--)
	
	solve();

	return 0;
}

// Lorenzo Fiorini
