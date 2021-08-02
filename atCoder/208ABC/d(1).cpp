#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e9;

void solve () {
	long long ans = 0;
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> v(n, vector<long long> (n, inf));
	
	while (m--) {
		long long a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		v[a][b] = c;
	}
	for (long long i = 0; i < n; i++) v[i][i] = 0;
	
	for (long long k = 0; k < n; k++) {
		vector<vector<long long>> time(n, vector<long long> (n, 0));
		for (long long i = 0; i < n; i++) {
			for (long long j = 0; j < n; j++) 
			{
				time[i][j] = min(v[i][j], v[i][k] + v[k][j]);
				if (time[i][j] < inf) {
					ans += time[i][j];
				}
			}
		}
		
		v.swap(time);
	}
	
	cout<< ans << "\n";
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	
	return 0;
}

// Lorenzo Fiorini
