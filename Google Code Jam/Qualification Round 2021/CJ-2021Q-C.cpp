#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)1e9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//
#define FOR(i, a, b, in) for (int i=a ; i<b ; i+=in)
#define RFOR(i, a, b, in) for (int i=a-1 ; i>=(b) ; i-=in)
#define REP(i, a, b) FOR(i, a, b, 1)
#define RREP(i, a, b) RFOR(i, a, b, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define all(cont) cont.begin(), cont.end()

void show (vector<int> v) {
	int n = v.size();
	REP (i, 0, n) 
		cout << v[i] << " ";
	cout << "\n";	
}

void solve () {
	int n, c;
	cin >> n >> c; 
	int mx = (n * (n+1)) / 2 - 1;
	//REP (i, 2, n+1) mx+= i;
	if (c < n - 1 || c > mx) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	int cost = c - (n - 1);
	vector<int> ans(n);
	REP (i,0,n) ans[i] = i + 1;
	REP (i, 0, n - 1 && cost > 0) {
		//if (cost == 0) break;
		int len = min(c + 1, n - i);
		reverse(ans.begin() + i, ans.begin() + i + len);
		c -= len - 1;
	}
	
	show(ans);
}

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int c = 1;
	while (c <= t) {
		cout << "Case #" << c << ": ";
		solve();
		c++;
	}
	
	return 0;
}
