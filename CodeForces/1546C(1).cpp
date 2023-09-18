#include <bits/stdc++.h>
using namespace std;

void showv(string s, vector<vector<int>> v, int n){
	cout << s;
	for (int i = 1; i < n; i++) {
		cout << i << "_ " << v[i][0] << " " << v[i][1] << "\n"; 
	}
	cout << "\n";
} 

void solve () {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<vector<int>> cnt(1e5 + 1, vector<int>(2, 0));
	
	int mx=0;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		cnt[v[i]][i % 2] ++;
		mx=max(mx, v[i]);
	}
	//showv("BEFORE\n", cnt, mx+1);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cnt[v[i]][i % 2] --;
	}
	//showv("AFTER\n", cnt, mx+1);
	
	
	
	for (int i = 0; i < n; i++) {
		if (cnt[v[i]][0] != 0 || cnt[v[i]][1] != 0) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t; while (t--)
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
