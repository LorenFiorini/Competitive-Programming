#include <bits/stdc++.h>
using namespace std;


int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int d, sum;
	cin >> d >> sum;
	
	vector<pair<int, int>> v(d);
	for (auto &p : v) cin >> p.first >> p.second;
	
	int mn = 0, mx = 0;
	for (auto p : v) {
		mn += p.first;
		mx += p.second;
	}
	//cout << mn << " " << mx << '\n';
	if (sum < mn || sum > mx) {
		cout << "NO\n";
		return 0;
	} else {
		cout << "YES\n";
	}
	
	sum -= mn;
	vector<int> ans(d);
	for (int i = 0; i < d; i++) ans[i] = v[i].first;
	
	for (int i = 0; i < d && sum > 0; i++) {
		int dif = min(sum, v[i].second - v[i].first);
		ans[i] += dif;
		sum -= dif;
	}
	
	for (int i : ans) cout << i << " ";
	cout << "\n";
	
	
	return 0;
}

// Lorenzo Fiorini
